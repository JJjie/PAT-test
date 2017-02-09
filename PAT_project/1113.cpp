//
// Created by 胡文杰 on 2017/2/9.
//

#include "pat.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int pat_1113(){
    int n;
    scanf("%d",&n);
    vector<long long > v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld",&v[i]);
    }
    sort(v.begin(),v.end());
    long long A1=0, A2=0;
    int l1 = n/2;
    int l2 = n - l1;
    for (int i = 0; i < l1; ++i) {
        A1 += v[i];
    }
    for (int i = l1; i < n; ++i) {
        A2 += v[i];
    }
    printf("%d %lld",l2-l1,A2-A1);
    return 0;
}