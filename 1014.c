#include <stdio.h>

int pof(int n){
    if (n == 1){
        printf("%d", 1);
        return 0;
    }
    if (n == 0){
        printf("%d", 10);
        return 10;
    }
    int res[20];
    int j = 0;
    for (int i = 9; i > 1 ; i--){
        if (n % i == 0){
            res[j] = i;
            j++;
            n = n/i;
            if (n > 1){
                i = 10;
                continue;
            } else {
                for (int k = j - 1; k >= 0 ; k--){
                    printf("%d", res[k]);
                }
                return 0;
            }
        }
        
    }
    printf("%d", -1);    //Không có nghiệm 1 chữ số nên trả về -1
    return 0;
}
        
int main(){
    int n;              
    scanf("%d", &n);       
    pof(n);
    return 0;
}
