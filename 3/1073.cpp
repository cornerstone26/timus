#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int N, dp[60005];
    cin >> N;
    dp[0] = 0;
    for (int i = 1; i <= N; i++){
        dp[i] = 5;
    }
    for (int i = 1; i*i <= N; i++){
        dp[i*i] = 1;
    }

    for (int i = 2; i <= N; i++){
        for (int j = 1 ; j*j <= i; j++){
            dp[i] = min(dp[i], dp[i - j*j] + 1);
        }
    }

    cout << dp[N];
}