//
// Created by 胡文杰 on 2017/2/2.
//

#include "pat.h"
#include <iostream>
using namespace std;

bool isprime_78(int a) {
    if(a == 1) return false;
    for(int i = 2; i * i <= a; i++)
        if(a % i == 0)
            return false;
    return true;
}

int pat_1078(){
    int msize,n;
    scanf("%d %d",&msize,&n);
    while (!isprime_78(msize)){
        msize++;
    }
    bool *hashtable = new bool[msize];
    fill(hashtable,hashtable+msize, false);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d",&a);
        int b = a % msize;
        if (!hashtable[b]){
            hashtable[b] = true;
            if (i == 0) printf("%d",b);
            else printf(" %d",b);
        } else {
            bool temp = false;
            for (int j = 1; j < msize ; ++j) {
                b = (a + j*j) % msize;
                if (!hashtable[b]){
                    hashtable[b] = true;
                    printf(" %d",b);
                    temp = true;
                    break;
                }
            }
            if (!temp) printf(" -");
        }
    }
    delete[] hashtable;
    return 0;
}