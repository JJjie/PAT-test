//
// Created by 胡文杰 on 2017/1/10.
//

#include "pat.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int pat_1019(){
    int N, base;
    cin >> N >> base;
    queue<int> q;
    stack<int> s;
    while (N >= base){
        int n = N / base;
        int tag = N - n*base;
        q.push(tag);
        s.push(tag);
        N = n;
    }
    q.push(N);
    s.push(N);

    unsigned long len = q.size();
    int *temp = new int[len];
    int flag = 0, i = 0;
    while (!q.empty() && !s.empty()){
        int qt = q.front();
        int st = s.top();
        if (st != qt) flag = 1;
        temp[i] = st;
        q.pop();
        s.pop();
        i++;
    }
    if (flag) cout << "No" << endl;
    else cout << "Yes" << endl;
    for (i = 0; i < len-1; i++) {
        cout << temp[i] << " " ;
    }
    cout << temp[i] << endl;

    delete[] temp;
    return 0;
}