//
// Created by 胡文杰 on 2017/1/22.
//

#include "pat.h"
#include <iostream>
using namespace std;

int pat_1048(){
    int n,m;
    cin >> n >> m;
    int coins[1001];
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        coins[temp] ++;
    }
    for (int i = 0; i < 1001; i++) {
        if (coins[i]){
            coins[i]--;
            if (coins[m-i] && m > i){
                cout << i << " " << m-i << endl;
                return 0;
            }
            coins[i]++;
        }
    }
    cout << "No Solution" << endl;

    return 0;
}