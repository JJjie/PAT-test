//
// Created by 胡文杰 on 2017/1/20.
//

#include "pat.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> pre_43;
vector<int> post_43;
bool mirror;

void getpost(int root, int tail){
    if (root > tail) return;
    int i = root + 1, j = tail;
    if (!mirror){
        while (i <= tail && pre_43[root] > pre_43[i]) i++; // 左子树
        while (j > root && pre_43[root] <= pre_43[j]) j--; // 右子树
    }else{
        while (i <= tail && pre_43[root] <= pre_43[i]) i++;
        while (j > root && pre_43[root] > pre_43[j]) j--;
    }
    if(i - j != 1) return ;
    getpost(root + 1, j);
    getpost(i, tail);
    post_43.push_back(pre_43[root]);
}

int pat_1043(){
    int n;
    cin >> n;
    pre_43.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre_43[i];
    }
    getpost(0, n-1);
    if(post_43.size() != n) {
        mirror = true;
        post_43.clear();
        getpost(0, n - 1);
    }
    if(post_43.size() == n) {
        printf("YES\n%d", post_43[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", post_43[i]);
    } else {
        printf("NO");
    }

    return 0;
}