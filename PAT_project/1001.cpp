//
//  1003.cpp
//  PAT_project
//
//  Created by 胡文杰 on 16/8/11.
//  Copyright © 2016年 胡文杰. All rights reserved.
//

#include "pat.h"
#include <cstdio>
#include <cstdlib>


int pat_1001() {
    int a, b, sum;
    int output[3];
    
    scanf("%d %d", &a, &b);
    
    sum = a + b;
    
    if (sum == 0) {
        printf("0");
    }
    else {
        if (sum < 0) {
            printf("-");
            sum = -sum;
        }
        int i = 2;
        while (sum != 0) {
            output[i] = sum % 1000;
            sum = sum / 1000;
            i--;
        }
        i++;
        printf("%d", output[i]);
        i++;
        while (i < 3) {
            printf(",%03d", output[i]);
            i++;
        }
    }
    printf("\n");
    
    return 0;
}
