//
// Created by 胡文杰 on 2017/1/15.
//

#include "pat.h"
#include <iostream>
#include <cstring>
using namespace std;

int pat_1023(){
    char str[22];
    cin >> str;
    int len = strlen(str);
    int flag = 0; // 进位
    int *con = new int[10];//存储每一个数字
    fill(con, con+10, 0);
    for (int i = len-1; i >= 0 ; i--) {
        int tag = str[i] - '0';
        con[tag]++;
        int temp = tag*2 + flag;
        flag = 0;
        if (temp > 9){
            temp = temp - 10;
            flag = 1;
        }
        con[temp]--;
        str[i] = (char)(temp + '0');
    }
    bool flag1 = false;
    for (int i = 0; i < 10; i++) {
        if (con[i] != 0) flag1 = true;
    }
    if (flag == 1 || flag1) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
    }
    if (flag == 1) cout << "1";
    cout << str << endl;

    delete[] con;
    return 0;
}