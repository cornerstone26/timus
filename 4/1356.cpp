#include <iostream>
using namespace std;

int n;
bool is_prime(int number){
    for (int i = 2; i*i <= number; i++)
        if (number % i == 0) return false;
    return number > 1;
}


int solve(int number){
    if (is_prime(number) == true){
        cout << number << endl;
        return 0;
    } else if (number % 2 == 1) {
        if (is_prime(number - 2) == true){
            cout << "2 " << number - 2 << endl;
            return 0;
        } else {
            number -= 3;
            cout << "3 "; 
        }
    }
    
    int p = number;
    while (p > 1){
        if (is_prime(p) == true && is_prime(number - p) == true){
            cout << p << " " << number - p << endl;
            return 0;
        }
        p -= 1;
    }
    return 1;
}

int main(){
    int n, number;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> number;
        solve(number);
    }
    return 0;
}