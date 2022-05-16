#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 100010

void getsubstring(char a[], char b[], int x, int y){
    int index = 0;
    for (int i = x; i <= x + y; i++){
        b[index++] = a[i];
    }
}

void computeLPSarr(char P[], int m, int lps[]){
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < m){
        if (P[i] == P[len]){
            lps[i] = ++len;
            i++;
        } else {
            if (len != 0){
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
    }
}

int KMPsearch(char P[], int m, char T[]){
    int n = strlen(T);
    int lps[MAXN];
    memset(lps, 0, m);
    computeLPSarr(P, m, lps);
    int i = 0, j = 0;
    while (i < n){
        if (T[i] == P[j]){
            i++;
            j++;
        } else {
            if (j!= 0){
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        if (j == m){
            //cout << "Pattern found at " << i - j << " length = "<< j << endl;
            return i - j;
            //j = lps[j - 1];
        }
    }
    return -1;
}

int main(){
    char s1[MAXN], s2[MAXN], substr[MAXN];
    int N, res, i, j;
    cin >> N;
    cin >> s1;
    cin >> s2;
    for (j = N; j > 0; j--){
        for (i = 0; i <= N - j; i++){
            getsubstring(s1, substr, i, j);
            //cout << substr << endl;
            res = KMPsearch(substr, j, s2); 
            if (res != -1){
                for (int k = res; k < res + j; k++){
                    cout << s2[k];
                }
                return 0;
            }
        }
    }
}