//
// Created by 胡文杰 on 2017/1/15.
//

#include "pat.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> post, in, level(100000,-1);
void Level(int root, int start, int end, int index);

int pat_1020(){
    int n, count=0;
    cin >> n;
    post.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) cin >> post[i];
    for (int i = 0; i < n; i++) cin >> in[i];
    Level(n-1,0,n-1,0);
    for (int i = 0; i < level.size(); i++) {
        if(level[i] != -1 && count != n - 1) {
            printf("%d ", level[i]);
            count++;
        } else if(level[i] != -1){
            printf("%d", level[i]);
            break;
        }
    }

    return 0;
}

void Level(int root, int start, int end, int index){
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    level[index] = post[root];
    Level(root - 1 - end + i, start, i - 1, 2 * index + 1);//左子树
    Level(root - 1, i + 1, end, 2 * index + 2);//右子数
}