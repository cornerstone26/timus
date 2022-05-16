#include <iostream>
#include <cstring>
#define MAXN 5010
using namespace std;

void fill_arr(int a[], int n, int val){
    for (int i = 0; i < n; i++){
        a[i] = val;
    }
}

void prt_arr(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << "\t";
    }
}
void zfunc(string str, int z[], int n){

    z[0] = n;
    // for (int i = 1; i < n; i++){
    //     while ((i + z[i] < n) && str[z[i]] == str[i+z[i]]){
    //         z[i]++;
    //     }
    // }

    int l = 0, r = 0;
    for (int i = 1; i < n; i++){
        z[i] = max(0, min(r - i, z[i - l]));
        while ((i + z[i]) < n && str[z[i]] == str[i + z[i]]){
            z[i]++;
        }
        if (i + z[i] > r){
            l = i;
            r = i + z[i];
        }
        
    }
}

void prefix_from_zfunc(int z[], int prefix[], int n){
    fill_arr(prefix, n, 0);
    for (int i = 1; i < n; i++){
        for (int j = z[i] - 1; j >= 0; j--){
            if (prefix[i + j] > 0){
                break;
            } else {
                prefix[i + j] = j + 1;
            }
        }
    }
}

int main(){
    string str;
    cin >> str;
    int n = str.length();
    int z[MAXN];
    int prefix[MAXN];
    zfunc(str, z, n);
    prefix_from_zfunc (z, prefix, n);
}