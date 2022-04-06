#include <iostream>
#include <vector>

using namespace std;
#define MAXN 20005
#define MAXQ 50000

vector<int> tree[MAXN];
vector<int> ancestors;
vector<pair<int, int>> queues[MAXN];

int res[MAXQ];
int q;
int maxD = -1, maxNode = -1;

void findD_DFS(int curs, int prev, int d) {
    if (d > maxD){
        maxD = d;
        maxNode = curs;
    }
    
    for (int i = 0; i < tree[curs].size(); i++) {
        if (tree[curs][i] != prev) {
            findD_DFS(tree[curs][i], curs, d + 1);
        }
    }
    
}

void solve(int curs, int prev) {
    ancestors.push_back(curs);

    for (int j = 0; j < queues[curs].size(); j++){
        int d = queues[curs][j].first;
        if ( d < ancestors.size()){
            res[queues[curs][j].second] = ancestors[ancestors.size() - d - 1];
        }
    }
    
    for (int i = 0; i < tree[curs].size(); i++) {
        if (tree[curs][i] != prev) {
            solve(tree[curs][i], curs);
            ancestors.pop_back();
        }
    }
    
}

int main(){
    int n, u, v, di;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    for (int i = 0; i < q; i++){
        cin >> u >> di;
        queues[u].push_back(make_pair(di,i));
    }
    
    findD_DFS(1, 0, 0);
    int nodeD1 = maxNode;
    maxNode = -1;
    findD_DFS(nodeD1, 0, 0);
    int nodeD2 = 1;
    if (maxNode != -1){
        nodeD2 = maxNode;
    } 
    
    ancestors = {};
    solve(nodeD1, 0);
    ancestors = {};
    solve(nodeD2, 0);
 
    for (int i = 0; i < q; i++){
        cout << res[i] << endl;
    }
    return 0;
}