//
// Created by 胡文杰 on 2017/2/9.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct tree_110{
    int left,right;
};
int pat_1110(){
    int n,root = 0;
    scanf("%d",&n);
    string l,r;
    vector<tree_110> tree(n);
    vector<bool> roottag(n, false);
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        if (l[0] == '-') tree[i].left = -1;
        else {
            int num = 0;
            for (int j = 0; j < l.length(); ++j) {
                num = num*10 + (int)(l[j]-'0');
            }
            tree[i].left = num;
            roottag[num] = true;
        }
        if (r[0] == '-') tree[i].right = -1;
        else {
            int num = 0;
            for (int j = 0; j < r.length(); ++j) {
                num = num*10 + (int)(r[j]-'0');
            }
            tree[i].right = num;
            roottag[num] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!roottag[i]) {
            root = i;
            break;
        }
    }
    queue<int> q;
    q.push(root);
    int cnt = 0,lastnode = 0;
    while (!q.empty()){
        int current = q.front();
        q.pop();
        if (current != -1){
            lastnode = current;
            cnt++;
        } else {
            if (cnt != n)
                printf("NO %d",root);
            else
                printf("YES %d",lastnode);
            return 0;
        }
        q.push(tree[current].left);
        q.push(tree[current].right);
    }
    return 0;
}