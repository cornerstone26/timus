#include <iostream>
#include <vector>
using namespace std;
#define MAXN 300000
#define MAXQ 300000
int a[MAXN], tree[MAXN*4] = {0};
vector <int> factors[MAXN];

void print(int n){
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < factors[i].size(); j++){
            cout << factors[i][j] << " ";
        }
        cout << endl;
    }
}

void build_factors(int n){
    for (int i = 1; i <= n; i++) 
        for(int k = 1; k*i <= n; k++) 
            factors[k*i].push_back(i);
}

void build_tree(int id, int l, int r){
    if (l == r){
        tree[id] = 1;
        return;
    }

    int mid = (l + r)/2;
    build_tree(id * 2, l, m);
    build_tree(id * 2 + 1, m + 1, r);

    tree[id] = tree[id*2] + tree[id*2 + 1]; 

}

int query(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        // Trường hợp không giao nhau
        return 0;
    }
    if (u <= l && r <= v) {
        // Trường hợp [l, r] nằm hoàn toàn trong [u, v]
        return tree[id];
    }

    int mid = (l + r) / 2;
    return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid+1, r, u, v);
}

void update(int l, int r, int d){
    for (int i = l; i <= r; i++){
        tree[i] += d;
    }
}

int ask(int i){
    int res = a[i];
    for (int j = 0; j < factors[i].size(); j++){
        res += query(1,1,n,factors[i][j],factors[i][j]);
    }
    return res;
}


int main(){
    int n,q,i,l,r,d,x;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    build_factors(n);
    build_tree(1,1,n);
    print(n);
    cin >> q;
    while (q--){
        cin >> x;
        if (x == 1){
            cin i
            cin >> query (1,1,n,i,i);

        } else {
            cin >> l >> r >> d;
            update(l, r, d);
        }

    }
}

