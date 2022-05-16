#include <iostream>
#include <cstring>
using namespace std;
#define INF 1000
void delete_mat (int **a, int n){
    for (int i = 0; i < n; i ++){
        delete[] a[i];
    }
    delete[] a;
}

void prt_mat(int ** a, int n, int m) {                       
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            cout << " " << a[i][j] << " \t";
        cout << "\n";
    }
}

int main(){
    int X = 910, Y = 8110;
    int t, s1, s2;
    cin >> t;

    int ** dp = new int * [X];
    for (int i = 0; i < X; i++)
        dp[i] = new int[Y];
        
    for (int i = 0; i < X; i++){
        for (int j = 0; j < Y; j++){
            dp[i][j] = INF;
        }
    }
    
    for (int i = 1; i <= 9; i++){
        dp[i][i*i] = 1;
    }
    
    dp[0][0] = 0;
    
    for (int sumd = 1; sumd < X; sumd++){
        for (int sumd2 = 0; sumd2 < Y; sumd2++){
            for (int digit = 1; digit < 10; digit++){
                if (sumd>= digit && sumd2>=digit*digit){
                    if ((dp[sumd-digit][sumd2-digit*digit] + 1 < dp[sumd][sumd2]) && (dp[sumd-digit][sumd2-digit*digit] != INF)){
                        dp[sumd][sumd2] = dp[sumd-digit][sumd2-digit*digit] + 1 ;
                    }
                }
                
            }
        }
    }

    int d;
    for (int i = 0; i < t; i++){
        cin >> s1 >> s2;

        if ((s1 > 900) || (s2 > 8100)){
        	cout << "No solution" << endl;
        }
        else if (dp[s1][s2] > 100) {
            
            cout << "No solution" << endl;
        } else {
            
            while (s1 != 0 || s2 != 0){
                for (d = 1; d < 10; d++){

                    if ((s1 >= d) && (s2 >= d*d)){
                        if  (dp[s1 - d][s2 - d*d] + 1 == dp[s1][s2]){
                            cout << d;
                            s1 -= d;
                            s2 -= d*d;
                            break;
                        }
                    }
                    
                }
            }
            cout << endl;
        }
    }
    
    delete_mat(dp, X);
    return 0;
}