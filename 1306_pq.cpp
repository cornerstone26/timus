#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    priority_queue <int> pqueue;
    int tmp;
    //push n / 2 + 1 numbers to queue
    for (int i = 0; i <= N/2; i++) {
        scanf("%d", &tmp);
        pqueue.push(tmp);
    }

  
    for (int i = N / 2 + 1; i < N; i++) {
        scanf("%d", &tmp);
        if (tmp < pqueue.top()) {
            pqueue.pop();
            pqueue.push(tmp);
        }
        
    }

    /*while (pqueue.size() != 0) {
        cout << pqueue.top() << endl;
        pqueue.pop();
    }*/
    if (N % 2) {
        printf("%.1lf", pqueue.top()/1.0);
    }
    else {
        int x = pqueue.top();
        pqueue.pop();
        int y = pqueue.top();
        unsigned z = x + y;
        printf("%.1lf", z/2.0);
    }
    
}