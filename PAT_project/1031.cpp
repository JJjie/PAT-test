//
// Created by 胡文杰 on 2017/1/16.
//

#include "pat.h"
#include <iostream>
using namespace std;

int pat_1031(){
    string str;
    cin >> str;
    int len = str.length();
    int n1 = len/3;
    int n2 = n1 + len%3;
    int i;
    while (n2<3){
        n1 = n1-1;
        n2 = len - 2*n1;
    }
    for (i = 0; i < n1; i++) {
        cout << str[i];
        for (int j = 0; j < n2-2; j++) {
            cout << " ";
        }
        cout << str[len-i-1] << endl;
    }
    len = len - i;
    for (int j = i; j < len; j++) {
        cout << str[j];
    }
    cout << endl;

    return 0;
}