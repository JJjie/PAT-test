//
// Created by 胡文杰 on 2017/2/9.
//

#include "pat.h"
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
struct node116{
    int rank = 0;
    bool visited = false;
};
bool isprime116(int num){
    bool flag = true;
    int n = sqrt(num);
    for (int i = 2; i <= n; ++i) {
        if (num % i == 0){
            flag = false;
            break;
        }
    }
    return flag;
}
int pat_1116(){
    int n,k;
    scanf("%d",&n);
    map<int,node116> mapp;
    for (int i = 1; i <= n; ++i) {
        int id;
        scanf("%d",&id);
        mapp[id].rank = i;
    }
    scanf("%d",&k);
    for (int i = 0; i < k; ++i) {
        int id;
        scanf("%d",&id);
        if (mapp[id].rank == 0) printf("%04d: Are you kidding?\n",id);
        else {
            if (!mapp[id].visited){
                if (mapp[id].rank == 1) printf("%04d: Mystery Award\n",id);
                else if (isprime116(mapp[id].rank)) printf("%04d: Minion\n",id);
                else printf("%04d: Chocolate\n",id);
                mapp[id].visited = true;
            } else {
                printf("%04d: Checked\n",id);
            }
        }
    }
    return 0;
}