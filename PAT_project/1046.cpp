//
// Created by 胡文杰 on 2017/1/20.
//

#include "pat.h"
#include <iostream>
#include <vector>
using namespace std;

int pat_1046(){
    int n, m, sum = 0;
    vector<int> distance;
    cin >> n;
    distance.resize(n+1);
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        sum += temp;
        distance[i] = sum;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int left, right;
        cin >> left >> right;
        if (left > right) swap(left, right);
        int temp = distance[right-1] - distance[left-1];
        cout << min(temp, sum-temp) << endl;
    }
    return 0;
}