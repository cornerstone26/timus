#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
#define MAXN 9
int x[8] = {-2,-2,-1,-1,1,1,2,2}, y[8] = {-1,1,-2,2,-2,2,-1,1};
int a[MAXN][MAXN];
int res[MAXN*MAXN];
int count = 0, n;

void fill_arr(){
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            a[i][j] = 0;
        }
    }
}

bool check(int a, int b){
    if (a + b > 0 && a + b <= n){
        return true;
    } 
    return false;
}

char int_to_char (int a){
    return (char) (a + 96);
}

void prt_res(){
    for (int i = 0; i < n*n; i++){
        cout << int_to_char(res[i] % 10) << (int) res[i]/10 << endl; 
    }
}

int move(int cur_x, int cur_y){
    //cout << "from " << int_to_char(cur_x) << cur_y << " " << count << endl;
    a[cur_x][cur_y] = 1;
    res[count++] = cur_x + cur_y * 10;
 
    int has_sol = 0, i;
    for (i = 0; i < 8; i++){
        if (count == n*n){
            prt_res();
            exit(0);
        }
        if (check(cur_x, x[i]) && check(cur_y, y[i]) && a[cur_x + x[i]][cur_y + y[i]] == 0){
            move(cur_x + x[i], cur_y + y[i]);
        } 
    }
    
    count--;
    a[cur_x][cur_y] = 0;
    return 0;
}

int main(){
    cin >> n;
    fill_arr();
    if (move(1,1) != 1){
        cout << "IMPOSSIBLE";
    }
    return 0;
}