//
// Created by 胡文杰 on 2017/1/22.
//

#include "pat.h"
#include <iostream>
#include <cstring>
using namespace std;

int pat_1050(){
    char str1[100000], str2[100000];
    cin.getline(str1, 100000);
    cin.getline(str2, 100000);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    bool flag[256] = {false};
    for (int i = 0; i < len2; i++) {
        flag[str2[i]] = true;//ASCII标记
    }
    for (int i = 0; i < len1; i++) {
        if (!flag[str1[i]]){
            printf("%c",str1[i]);
        }
    }

    return 0;
}