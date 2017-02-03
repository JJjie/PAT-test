//
// Created by 胡文杰 on 2017/2/3.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> pre_86, in_86, post_86;

void postorder(int root, int start, int end){
    if (start > end) return;
    int i = start;
    while (i < end && in_86[i] != pre_86[root]) i++;
    postorder(root+1,start,i-1);
    postorder(root+1+i-start,i+1,end);
    post_86.push_back(pre_86[root]);
}

int pat_1086(){
    int n;
    cin >> n;
    string c;
    int d;
    stack<int> s;
    for (int i = 0; i < 2*n; ++i) {
        cin >> c;
        if (c[1] == 'u') {
            cin >> d;
            pre_86.push_back(d);
            s.push(d);
        } else {
            int a = s.top();
            in_86.push_back(a);
            s.pop();
        }
    }
    postorder(0,0,n-1);
    cout << post_86[0];
    for (int i = 1; i < n; ++i) {
        cout << " " << post_86[i];
    }
    return 0;
}