#include <iostream>
using namespace std;
int n, m;

void f_calc(int *k, int *res){
    int i,j;
    for (i = 1; i < n; i ++){
        res[i] = 2;
        for (j = 0; j < m; j++){
            if (i >= k[j] && res[i - k[j]] == 2){
                res[i] = 1;
                break;
            }
        }
    }
    cout << res[n - 1];
}

int main(){
    cin >> n >> m;
    int *k = new int[m];
    int *res = new int[++n];
    res[1] = 2;
    for (int i = 0; i < m; i++){
        cin >> k[i];
    }
    f_calc(k, res);
}