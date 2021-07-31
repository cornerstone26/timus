#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n;
    int mod = 1e9 + 9;
	cin >> n;
    
    int p[1000];
    for (int i = 2; i < 1000; i++){
        p[i] = 1;
    }
    
    for (int i = 2; i < 1000; i++){
        if (p[i] == 1){
            for (int j = 2*i; j < 1000; j += i){
                p[j] = 0;
            }
        }
    }
    
    int dp[10005][100];
    memset(dp,0,sizeof(dp));
    for (int i = 100; i < 1000; i++){
        if (p[i]){
            dp[3][i % 100]++;
        }
    }
    
    int x;
    for (int i = 4; i <= n; i++){
        for (int j = 10; j <= 99; j++){
            for ( int k = 1; k <= 9; k++){
                x = j*10 + k;
                if (x < 100 || x > 999) 
                    continue;
                if (p[x]){
                    dp[i][x%100] = (dp[i][x%100] + dp[i-1][j])%mod;
                }
            }
        }
    }
    
    long long res = 0;
    for (int i = 1; i <= 99; i++){
        res = (res + dp[n][i]) % mod;
    }
    cout << res;
    return 0;
}