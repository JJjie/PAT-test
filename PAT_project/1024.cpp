//
// Created by 胡文杰 on 2017/1/15.
//

#include "pat.h"
#include <iostream>
using namespace std;

bool judgePolin(long long num);
long long add(long long num);

int pat_1024(){
    long long num;
    int k;
    cin >> num >> k;
    int count = 0;
    for (int i = 0; i < k; i++) {
        if (judgePolin(num)){
            break;
        }
        num = add(num);
        count ++;
    }
    cout << num << '\n' << count << endl;
    return 0;
}

bool judgePolin(long long num){
    long long tag=0;
    long long sto=num;
    while (num > 9){
        tag = tag*10 + (num%10);
        num = num/10;
    }
    tag = tag*10 + num;
    return (tag == sto) ? true : false;
}
long long add(long long num){
    long long tag=0;
    long long sto=num;
    while (num > 9){
        tag = tag*10 + (num%10);
        num = num/10;
    }
    tag = tag*10 + num;
    return tag+sto;
}