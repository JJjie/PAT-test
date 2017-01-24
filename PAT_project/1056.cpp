//
// Created by 胡文杰 on 2017/1/24.
//

#include "pat.h"
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct mice_56{
    int weight;
    int index; //给出的序列
    int index0;//排序前的序列
    int rank;//最后排名
};
bool cmp_56(mice_56 a,mice_56 b){
    return a.index0 < b.index0;
}
int pat_1056(){
    int np,ng;
    scanf("%d %d",&np,&ng);
    vector<int> v(np);
    vector<mice_56> w(np);
    for (int i = 0; i < np; i++) {
        scanf("%d",&v[i]);
    }
    for (int i = 0; i < np; i++) {
        int order;
        scanf("%d",&order);
        w[i].weight = v[order];
        w[i].index = i;
        w[i].index0 = order;
    }
    queue<mice_56> q;
    for (int i = 0; i < np; i++) {
        q.push(w[i]);
    }
    while (!q.empty()){
        int size = q.size();
        if (size == 1){
            mice_56 temp = q.front();
            w[temp.index].rank = 1;
            break;
        }
        int group = size / ng;
        if (size % ng != 0) group += 1;
        mice_56 maxnode;
        int maxweight = -1, cnt = 0;
        for (int i = 0; i < size; i++) {
            mice_56 temp = q.front();
            w[temp.index].rank = group + 1;
            q.pop();
            cnt ++;
            if (temp.weight > maxweight){
                maxweight = temp.weight;
                maxnode = temp;
            }
            if (cnt == ng || i == size -1){
                cnt = 0;
                maxweight = -1;
                q.push(maxnode);
            }
        }
    }
    sort(w.begin(), w.end(), cmp_56);
    for (int i = 0; i < np; i++) {
        printf("%d%c",w[i].rank,(i==np-1) ? '\n' : ' ');
    }
    return 0;
}