//
//  1007.cpp
//  PAT_project
//  dp动态规划问题
//  Created by 胡文杰 on 2017/1/5.
//  Copyright © 2017年 胡文杰. All rights reserved.
//

#include "pat.h"
#include <iostream>
using namespace std;

int pat_1007(){
    int N, flag=0, sum=-1, left=0, right=0, temp=0, tempindex=0;
    cin >> N;
    cin.ignore();
    int *set = new int[N];
    for (int i = 0; i < N ; i++) {
        cin >> set[i];
        if (set[i] >= 0){
            flag = 1;
        }
        temp += set[i];
        if (temp > sum){
            sum = temp;
            left = tempindex;
            right = i;
        }else if (temp < 0){
            temp = 0;
            tempindex = i + 1;
        }
    }
    if (flag == 0){
        cout << 0 << " " << set[0] << " " << set[N-1] << endl;
    }else {
        cout << sum << " " << set[left] << " " << set[right] << endl;
    }

//    释放内存
    delete[] set;

    return 0;
}
