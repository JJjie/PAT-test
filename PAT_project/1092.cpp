//
// Created by 胡文杰 on 2017/2/7.
//

#include "pat.h"
#include <iostream>
#include <map>
using namespace std;

int pat_1092(){
    map<char, int> shop;
    string sh,ne;
    cin >> sh >> ne;
    int slen = sh.length();
    int nlen = ne.length();
    int ans = 0;
    bool temp = true;
    for (int i = 0; i < slen; ++i) {
        shop[sh[i]] ++ ;
    }
    for (int i = 0; i < nlen; ++i) {
        shop[ne[i]] -- ;
        if (shop[ne[i]] < 0) {
            temp = false;
            ans ++;
        }
    }
    if (temp){
        cout << "Yes " << slen-nlen << endl;
    } else {
        cout << "No " << ans << endl;
    }
    return 0;
}