//
// Created by 胡文杰 on 2017/1/6.
//

#include "pat.h"
#include <iostream>
using namespace std;

int  pat_1008(){
    int N,a;
    int now = 0;
    int sum = 0;
    cin >> N;
    while(N>0) {
        cin >> a;
        if(a > now) {
            sum = sum + 6 * (a - now);
        } else {
            sum = sum + 4 * (now - a);
        }
        now = a;
        sum += 5;
        N--;
    }
    cout << sum;

    return 0;
}
