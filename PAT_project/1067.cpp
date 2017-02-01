//
// Created by 胡文杰 on 2017/1/30.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pat_1067(){
    int n;
    scanf("%d",&n);
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&num[i]);
    }
    int res = 0;//记录交换次数
    for (int i = 0; i < num.size(); ++i) {
        if (num[i] != i){
            if (i != 0){
                swap(num[0],num[i]);
                res ++;
            }
            int count = 0;
            int temp1 = 0;
            int temp2 = num[0]; //temp2为num[i]的值
            num[0] = 0;
            while (temp2 != num[temp2]){
                temp1 = num[temp2];
                num[temp2] = temp2;
                temp2 = temp1;
                count ++;
            }
            res += count;
        }
    }
    printf("%d",res);
    return 0;
}