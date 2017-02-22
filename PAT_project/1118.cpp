//
// Created by 胡文杰 on 2017/2/22.
//

#include "pat.h"
#include <iostream>
using namespace std;

int pa[10001]={0},isroot[10001]={0};
int findPa(int x){
    while (x != pa[x])
        x = pa[x];
    return x;
}
void Union118(int a, int b){
    int fa = findPa(a);
    int fb = findPa(b);
    if (fa != fb)
        pa[fa] = fb;
}
int pat_1118(){
    int n,k,temp,cnt=0,num = 0;
    int a,b;
    int birds[10001] = {0};
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        pa[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&k);
        for (int j = 0; j < k; ++j) {
            scanf("%d",&temp);
            if (birds[temp] == 0) {
                birds[temp] = i;
                num++;
            }
            Union118(i,birds[temp]);
        }
    }
    for (int i = 1 ; i <= n ; ++i) {
        int id = findPa(i);
        isroot[id]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (isroot[i] != 0)
            cnt++;
    }
    printf("%d %d\n",cnt, num);
    scanf("%d",&k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %d",&a,&b);
        int aa = findPa(birds[a]);
        int bb = findPa(birds[b]);
        if (aa == bb)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}