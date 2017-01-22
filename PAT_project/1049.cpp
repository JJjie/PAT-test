//
// Created by 胡文杰 on 2017/1/22.
//

#include "pat.h"
#include <iostream>
using namespace std;

int pat_1049(){
    int n, left, right, now=1, radix=1, sum=0; // radix为基数，left为基数左边的数，right为基数右边的数
    scanf("%d",&n);
    while (n / radix){
        left = n / (radix * 10);
        now = n / radix % 10;
        right = n % radix;
        if (now == 0) sum += left * radix;
        else if (now == 1) sum += left * radix + right + 1;
        else sum += (left + 1) * radix;
        radix = radix * 10;
    }
    cout << sum << endl;

    return 0;
}