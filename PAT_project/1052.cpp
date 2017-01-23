//
// Created by 胡文杰 on 2017/1/23.
//

#include "pat.h"
#include <iostream>
#include <algorithm>
using namespace std;

struct node_51{
    int address;
    int key;
    int next;
    bool flag = false;//标记结点是否被使用
};
bool cmp_51(node_51 a, node_51 b){
    if (!a.flag || !b.flag){
        return a.flag > b.flag; //将不使用的点挪后
    }else
        return a.key < b.key;
}
int pat_1052(){
    int n, index, cnt=0;
    cin >> n >> index;
    node_51 nodes[100000];
    for (int i = 0; i < n; i++) {
        int add, key, next;
        cin >> add >> key >> next;
        nodes[add].address = add;
        nodes[add].key = key;
        nodes[add].next = next;
    }
    for (int i = index; i != -1; i = nodes[i].next) {
        nodes[i].flag = true;
        cnt ++;
    }
    if (cnt == 0){
        cout << "0 -1" << endl;
    }else{
        sort(nodes, nodes+100000, cmp_51);
        printf("%d %05d\n",cnt, nodes[0].address);
        for (int i = 0; i < cnt; i++) {
            printf("%05d %d ",nodes[i].address, nodes[i].key);
            if (i != cnt-1) {
                printf("%05d\n",nodes[i+1].address);
            }
            else {
                printf("-1\n");
            }
        }
    }
    return 0;
}