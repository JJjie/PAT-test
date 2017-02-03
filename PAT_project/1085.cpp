//
// Created by 胡文杰 on 2017/2/3.
//

#include "pat.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int pat_1085(){
    int n;
    long long p;
    scanf("%d %lld",&n,&p);
    vector<long long > v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld",&v[i]);
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        long long int high = v[i] * p;
        for (int j = i + ans; j < n; ++j) {
            if (v[j] <= high) ans++;
            else break;
        }
        if (v[n-1] < high) break;
    }
    printf("%d",ans);
    return 0;
}