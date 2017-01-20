//
// Created by 胡文杰 on 2017/1/20.
//

#include "pat.h"
#include <iostream>
#include <vector>
using namespace std;

int pat_1041(){
    vector<int> records;
    int n;
    vector<int> num;
    cin >> n;
    records.resize(10001);
    num.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        records[num[i]] ++;
    }

    int index;
    for ( index = 0; index < n; index++) {
        if (records[num[index]]==1) {
            break;
        }
    }

    if (index == n) {
        printf("None\n");
    }
    else {
        printf("%d\n", num[index]);
    }
    return 0;
}