#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 1000

vector<int> p[MAXN];
vector<int> c[MAXN];

void prt (int *a, int n){
    for (int i = 0; i <= n; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

void fill_arr(int *a, int n){
    for (int i = 0; i < n; i++){
        a[i] = 0;
    }
}
void solvep(int cur, int prev, int *wolf){
    wolf[cur] = 1;
    for (int i = 0; i < p[cur].size(); i++){
        if (p[cur][i] != prev){
            solvep(p[cur][i], cur, wolf);
        }
    }
}

void solvec(int cur, int prev, int *wolf){
    wolf[cur] = 1;
    for (int i = 0; i < c[cur].size(); i++){
        if (c[cur][i] != prev){
            solvec(c[cur][i], cur, wolf);
        }
    }
}

void result(int *wolf, int n){
    int iswolf = 0;
    for (int i = 1; i <= n; i++){
        if (wolf[i] == 0){
            cout << i << " ";
            iswolf = 1;
        }
    }
    
    if (iswolf == 0){
        cout << "0";
    }
}

int main(){
    int n, u, v;
    cin >> n;
    char s[10];
    while (1){
    	 scanf("%s",s);
    	 if (strcmp(s,"BLOOD") == 0) break;
    	 sscanf(s,"%d",&v); 
    	 scanf("%d",&u);
    	 p[u].push_back(v); 
    	 c[v].push_back(u);
    }


    int *wolf = new int[n + 1];
    fill_arr(wolf, n);
    while (scanf("%d", &u) != EOF){
        solvep(u, 0, wolf);
        solvec(u, 0, wolf);
    }
    result(wolf, n);


}