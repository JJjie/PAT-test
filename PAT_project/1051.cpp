//
// Created by 胡文杰 on 2017/1/22.
//

#include "pat.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int pat_1051(){
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        stack<int> s;
        vector<int> v(n+1);
        for (int j = 1; j <= n; ++j) {
            cin >> v[j];
        }
        int current = 1;
        for (int j = 1; j <= n; j++) {
            s.push(j);
            if (s.size() > m) break;
            while (!s.empty() && s.top() == v[current]){
                s.pop();
                current ++;
            }
        }
        if (current == n+1){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}