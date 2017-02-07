//
// Created by 胡文杰 on 2017/2/7.
//

#include "pat.h"
#include <iostream>
using namespace std;

int pat_1093(){
    string str;
    cin >> str;
    int len = str.length();
    int result = 0;
    int countp = 0;
    int countt = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == 'T') countt++;
    }
    for (int i = 0; i < len; ++i) {
        if (str[i] == 'P') countp++;
        if (str[i] == 'T') countt--;
        if (str[i] == 'A') {
            result = (result + (countp * countt) % 1000000007) % 1000000007;
        }
    }
    cout << result;
    return 0;
}