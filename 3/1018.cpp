#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
#define MAXN 100

vector<int> a[MAXN];
int n;
int apples[MAXN][MAXN];
int dp[MAXN][MAXN];
int l_node[MAXN];
int r_node[MAXN];

void prt_mat(int *a, int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void DFS(int u, int v) {
    l_node[u] = 0;
    r_node[u] = 0;

    for (int i = 0; i < a[u].size(); i++) {
         if (a[u][i] != v) {
            DFS(a[u][i], u);
        }
        if (l_node[v] == 0){
            l_node[v] = u;
        } else {
            r_node[v] = u;
        }
    }
}

int calc(int u, int k){
    int ret = -2, l, r;
    if (dp[u][k] != -1) return dp[u][k];
    if (k == 0){
        return 0;
    } else if (k < 0){
        return -2;
    } else {
        if (r_node[u] != 0){
            ret = max(ret, calc(r_node[u], k - 1) + apples[u][r_node[u]]);
        }
        
        if (l_node[u] != 0){
            ret = max(ret, calc(l_node[u], k - 1) + apples[u][l_node[u]]);
        }
        
        if (l_node[u] != 0 && r_node[u] != 0){
            for (int i = 1; i < k; i++){
                if (calc(l_node[u], i - 1) != -2 && calc(r_node[u], k - i - 1) != -2){
                    l = calc(l_node[u], i - 1) + apples[u][l_node[u]];
                    r = calc(r_node[u], k - i - 1) + apples[u][r_node[u]];
                    ret = max(ret, l + r);
                }
                
            }
        }
    }
    
    dp[u][k] = ret;
    return ret;
}

void solve(){
    int q, u, v, w;
    cin >> n >> q;

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            apples[i][j] = -11;
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < n - 1; i++){
        cin >> u >> v >> w;
        apples[u][v] = w;
        apples[v][u] = w;
        a[u].push_back(v);
        a[v].push_back(u);

    }

    DFS(1, 0);
    calc(1, q);   
    cout << dp[1][q];
}

int main(){
    solve();
    return 0;
}