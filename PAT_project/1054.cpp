//
// Created by 胡文杰 on 2017/1/24.
//

#include "pat.h"
#include <iostream>
#include <map>
using namespace std;

int pat_1054(){
    int m, n;
    scanf("%d%d",&m,&n);
    int half = m*n/2;
    map<int, int> color;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp ;
            scanf("%d",&temp);
            color[temp]++;
            if (color[temp] > half){
                printf("%d",temp);
                break;
            }
        }
    }
    return 0;
}