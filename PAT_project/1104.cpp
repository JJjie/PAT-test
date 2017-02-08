//
// Created by 胡文杰 on 2017/2/8.
//

#include "pat.h"
#include <iostream>
#include <vector>
using namespace std;

int pat_1104(){
    int n;
    scanf("%d",&n);
    vector<double> v(n+1);
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lf",&v[i]);
        sum += v[i] * i * (n+1-i);
    }
    printf("%.2f",sum);
    return 0;
}