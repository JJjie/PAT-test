//
// Created by 胡文杰 on 2017/1/16.
//

#include "pat.h"
#include <iostream>
using namespace std;

int pat_1027(){
    int red, green, blue;
    char tag[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};
    char result[8];
    result[0] = '#';
    result[7] = '\0';
    cin >> red >> green >> blue;
    result[1] = tag[red/13];
    result[2] = tag[red-(red/13)*13];
    result[3] = tag[green/13];
    result[4] = tag[green-(green/13)*13];
    result[5] = tag[blue/13];
    result[6] = tag[blue-(blue/13)*13];
    cout << result << endl;
    return 0;
}