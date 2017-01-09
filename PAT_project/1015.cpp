//
// Created by 胡文杰 on 2017/1/7.
//

#include "pat.h"
#include <iostream>
#include <cmath>
using namespace std;

bool isprime (int num);
int reverse (int num,int radix);

int pat_1015(){
    int prime,radix;
    cin >> prime;
    while (prime > 0){
        cin >> radix;
        if (isprime(prime)){
            int num = reverse(prime,radix);
            if (isprime(num)){
                cout << "Yes" << endl;
            } else{
                cout << "No" << endl;
            }
        } else{
            cout << "No" << endl;
        }
        cin >> prime;
    }
    return 0;
}

bool isprime(int num){
    if (num > 1){
        int sq = (int)sqrt((double)num);
        int i;
        for (i = 2; i <= sq; i++) {
            if (num % i == 0) break;
        }
        if (i > sq) return true;
    }
    return false;
}
//基于基数的逆，真值为十进制
int reverse(int num, int radix){
    int renum = 0;
    while (num > 0){
        renum = renum * radix + num % radix;
        num = num/radix;
    }
    return renum;
}