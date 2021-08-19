#include <iostream>
#include <string.h>
using namespace std;
int check(char s1[], int index){
    int x = strlen(s1) - 1;
    for (int i = index; i < (strlen(s1) + index)/2; i++){
        if (s1[i] != s1[x--]){
            return 0;
        }
    }
    return 1;
}

int main(){
    char s1[20000];
    cin >> s1;
    int index = 1;
    while (check(s1,index) == 0 && index < strlen(s1)){
        index++;
    }

    //cout << index << endl;

    cout << s1;
    
    for (int i = index - 1; i >= 0; i--){
        cout << s1[i];
    }

    return 0;
}

