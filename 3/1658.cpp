#include <iostream>
#include <cstring>
using namespace std;


int main(){
    int t, s1, s2;
    cin >> t;
    int dp[901][8101];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    for (int digit = 0; digit < 10; digit++){
        for (int sdigit = 1; sdigit <= 900; sdigit++){
            for (int ssdigit = 1; ssdigit <= 8100; ssdigit){
                
            }
        }
    }


    for (int i = 0; i < t; i++){
        cin >> s1 >> s2;

    }
}