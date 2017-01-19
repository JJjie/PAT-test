//
// Created by 胡文杰 on 2017/1/19.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp_37(int a, int b){
    return a > b;
}

int pat_1037(){
    int nc, np;
    int cindex=0, pindex=0;//标记序列中为负的索引
    int sum = 0;
    cin >> nc;
    vector<int> coupon;
    vector<int> product;
    for (int i = 0; i < nc; i++) {
        int a;
        cin >> a;
        coupon.push_back(a);
    }
    cin >> np;
    for (int i = 0; i < np; i++) {
        int a;
        cin >> a;
        product.push_back(a);
    }
    sort(coupon.begin(), coupon.end(), cmp_37);
    sort(product.begin(), product.end(), cmp_37);

    int p=0,q=0;
    while (p<nc && q<np && coupon[p]>0 && product[q]>0){
        sum += coupon[p] * product[q];
        p++, q++;
    }
    p = nc-1, q= np - 1;
    while (p >= 0 && q >=0 && coupon[p]<0 && product[q]<0){
        sum += coupon[p] * product[q];
        p--, q--;
    }

    cout << sum << endl;

    return 0;
}