//
// Created by 胡文杰 on 2017/1/25.
//

#include "pat.h"
#include <iostream>
using namespace std;

int pat_1065(){
    int n;
    scanf("%d",&n);
    long long a,b,c;
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld %lld",&a,&b,&c);
        long long sum = a+b;
        if (a > 0 && b > 0 && sum < 0) { // 结果溢出,真值定会大于c
            printf("Case #%d: true\n",i+1);
        } else if (a < 0 && b < 0 && sum >= 0){
            printf("Case #%d: false\n",i+1);
        } else if (sum > c){
            printf("Case #%d: true\n",i+1);
        } else {
            printf("Case #%d: false\n",i+1);
        }
    }
    return 0;
}