//
// Created by 胡文杰 on 2017/2/1.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp_69_up(int a, int b){
    return a>b;
}
bool cmp_69_down(int a, int b){
    return a<b;
}

int pat_1069(){
    int num;
    int result = 0;
    scanf("%d",&num);
    vector<int> val(4);
    while (result != 6174){
        val[0] = num/1000;
        val[1] = (num - (num/1000)*1000)/100 ;
        val[2] = (num - (num/100)*100)/10;
        val[3] = num%10;
        sort(val.begin(),val.end(),cmp_69_up);
        int result1 = val[0]*1000 + val[1]*100 + val[2]*10 + val[3];
        sort(val.begin(),val.end(),cmp_69_down);
        int result2 = val[0]*1000 + val[1]*100 + val[2]*10 + val[3];
        result = result1 - result2;
        if (result == 0){
            printf("%04d - %04d = 0000\n",num,num);
            return 0;
        } else{
            printf("%04d - %04d = %04d\n",result1,result2,result);
            num = result;
        }
    }

    return 0;
}