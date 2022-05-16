#include <iostream>
#include <vector>
using namespace std;
#define MAXN 50000
#define MAXLOGN 17 

vector<int> a[MAXN];
vector<int> b[MAXN];

int dis[MAXN];
int l[MAXN]={0}; 
int P[MAXN][MAXLOGN]; 
int n;

void DFS(int u, int v) {
    l[u] = l[v] + 1;
    for (int k = 1; k < MAXLOGN; k++) 
        P[u][k] = P[P[u][k - 1]][k - 1];
 
    for (int i = 0; i < a[u].size(); i++) {
         if (a[u][i] != P[u][0]) {
            P[a[u][i]][0] = u;
            dis[a[u][i]] = dis[u] + b[u][i];
            DFS(a[u][i], u);
        }
    }
}


int LCA(int x, int y) {
    for (int k = MAXLOGN - 1; k >= 0; k--)
        if (l[P[x][k]] >= l[y])
            x = P[x][k];

    for (int k = MAXLOGN - 1; k >= 0; k--)
        if (l[P[y][k]] >= l[x])
            y = P[y][k];
    
    for (int k = MAXLOGN - 1; k >= 0; k--)
        if (P[x][k] != P[y][k]) {
            x = P[x][k];
            y = P[y][k];
        }
    while (x != y) {
        
        x = P[x][0];
        y = P[y][0];
    }
    return x;
}

int min_distance(int x, int y){
    int ans = 0;
    if (x == y){
        return 0;
    } else {
        int lca = LCA (x,y);
        ans = dis[x] + dis[y] - 2*dis[lca];
        return ans;
    }
}

void solve() {
    P[0][0] = 0; 
    dis[0] = 0;
    int m,u,v,w;
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        cin >> u >> v >> w;
        a[u].push_back(v);
        a[v].push_back(u);
        b[u].push_back(w);
        b[v].push_back(w);
    }
    l[0] = 0;
    DFS(0, 0);
    
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> u >> v;
        cout << min_distance (u,v) << endl;
    }
    
}

int main(){
    solve();
    return 0;
}