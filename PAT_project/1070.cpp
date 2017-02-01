//
// Created by 胡文杰 on 2017/2/1.
//

#include "pat.h"
#include <iostream>
#include <algorithm>
using namespace std;

struct mooncake{
    float mount;
    float profit;
    float unit;
};
bool cmp_70(mooncake a,mooncake b){
    return a.unit > b.unit;
}
int pat_1070(){
    int n,need;
    cin >> n >> need;
    mooncake *cakes = new mooncake[n];
    for (int i = 0; i < n; ++i) {
        cin >> cakes[i].mount;
    }
    for (int i = 0; i < n; ++i) {
        cin >> cakes[i].profit;
    }
    for (int i = 0; i < n; i++) {
        cakes[i].unit = cakes[i].profit / cakes[i].mount;
    }
    sort(cakes, cakes+n, cmp_70);
    float result = 0.0;
    for (int i = 0; i < n; i++) {
        if (cakes[i].mount <= need){
            result += cakes[i].profit;
        }else{
            result += cakes[i].unit * need;
            break;
        }
        need = need - cakes[i].mount;
    }
    printf("%.2f",result);
    return 0;
}