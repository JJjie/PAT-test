//
// Created by 胡文杰 on 2017/1/24.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void peekMedian(vector<int> v){
    int len = v.size();
    vector<int> vt(len);
    for (int i = 0; i < len; i++) {
        vt[i] = v[i];
    }
    int index;
    if (len % 2 == 0) index = len / 2 - 1;
    else index = (len+1)/2 - 1;
    sort(vt.begin(), vt.end());
    printf("%d\n",vt[index]);
}

int pat_1057(){
    int n,temp;
    char str[11];
    scanf("%d",&n);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        scanf("%s",str);
        if (str[1] == 'u'){
            cin >> temp;
            v.push_back(temp);
        } else if (str[1] == 'o'){
            if (!v.empty()){
                printf("%d\n",v.back());
                v.pop_back();
            } else{
                printf("Invalid\n");
            }
        } else {
            if (!v.empty()){
                peekMedian(v);
            } else{
                printf("Invalid\n");
            }
        }
    }
    return 0;
}