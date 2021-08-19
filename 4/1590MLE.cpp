#include <iostream>
#include <cstring>
#define MAX 5000
using namespace std;
int arr[MAX][MAX];

void getsubstring(char a[], char b[], int x, int y){
    int index = 0;
    for (int i = x; i < x + y; i++){
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
            }else{
                lps[i++] = 0;
            }
        }
    }
}

void KMPsearch(char P[], int m, char T[], int index){
    int n = strlen(T);
    int lps[MAX];
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
            //cout << "Found pattern at " << i - j << endl;
            if (i - j != index){
                arr[m][i-j] = -1;
            }
            j = lps[j - 1];
        }
    }
}

int main(){
    char str[MAX], substr[MAX];
    cin >> str;
    int n = strlen(str);
    int res = 0;
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= n - i; j++){
            res += arr[j][i];
            if (arr[j][i] == 0){
                getsubstring(str, substr, i,j);
                //cout << substr << endl;
                //cout <<"Substring starts at " << i << " with length = " << j << endl;
                KMPsearch(substr, j, str, i);
            }
        }
    }
     
    // for (int i = 1; i <= n; i++){
    //     for (int j = 0; j < n; j++){
    //         cout << arr[i][j] << " ";
    //         if (j == n - 1){
    //             cout << endl;
    //         }
    //     }
    // }

    cout << n*(n+1)/2 + res;
    return 0;

}