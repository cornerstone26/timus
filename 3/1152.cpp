#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
void prt(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
int main(){
    int N;
    cin >> N;
    int arr[21], subarr[7], res = 0, index = 0;
    memset(arr, 0, sizeof(arr));
    int sum = 0;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    //prt(arr, 21);
    //cout << sum << endl;

    for (int i = 0; i < 21; i += 3){
        subarr[index++] = arr[i] + arr[i + 1] + arr[i + 2];
    }

    for (int i = 0; i < 7; i++){
        for (int j = i; j < 7; j++){
            if (subarr[j] < subarr[j + 1]){
                int tmp = subarr[j + 1];
                subarr[j + 1] = subarr[j];
                subarr[j] = tmp;
            }  
        }
    }
    //prt(subarr, 7);
    for (int i = 0; i < N/3; i++){
        sum -= subarr[i];
        res += sum;
        //cout << res << " ";
    }
    cout << res;
}