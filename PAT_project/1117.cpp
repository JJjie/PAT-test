//
// Created by 胡文杰 on 2017/2/10.
//

#include "pat.h"
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp_117(int a,int b){
    return a>b;
}
int pat_1117(){
    int n;
    scanf("%d",&n);
    int *a = new int[n+1];
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1,cmp_117);
    for (int i = 1; i <= n; ++i) {
        if (a[i] > i) count++;
    }
    printf("%d",count);
    delete[] a;
    return 0;
}