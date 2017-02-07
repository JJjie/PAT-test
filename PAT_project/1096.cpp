//
// Created by 胡文杰 on 2017/2/7.
//

#include "pat.h"
#include <iostream>
#include <cmath>
using namespace std;

int pat_1096(){
    int n;
    scanf("%d",&n);
    int max = sqrt(n);
    for (int len = 12; len >= 1 ; len--) { // 2往上连续12个数超过2^21
        for (int start = 2; start <= max; start++) {
            long long ans = 1;
            for (int i = start; i - start < len ; ++i)
                ans *= i;
            if (n % ans == 0){
                printf("%d\n%d",len,start);
                for (int i = start+1; i-start < len ; ++i) {
                    printf("*%d",i);
                }
                return 0;
            }
        }
    }
    printf("1\n%d",n);
    return 0;
}