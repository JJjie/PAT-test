//
// Created by 胡文杰 on 2017/1/25.
//

#include "pat.h"
#include <iostream>
using namespace std;

int pat_1059(){
    long int num;
    cin >> num;
    cout << num << "=";
    if (num == 1) cout << num << endl;
    bool state = false;//标记前面是否需要输出"*"
    for (int i = 2; num >= 2 ; i++) {
        int cnt = 0, flag = 0;
        while (num % i == 0){
            cnt ++;
            num = num / i;
            flag = 1;
        }
        if (flag){
            if (state) cout << "*";
            cout << i;
            state = true;
        }
        if (cnt > 1){
            cout << "^" << cnt;
        }
    }
    return 0;
}