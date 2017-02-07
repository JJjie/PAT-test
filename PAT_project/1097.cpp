//
// Created by 胡文杰 on 2017/2/7.
//

#include "pat.h"
#include <iostream>
#include <algorithm>
using namespace std;
struct node_97{
    int id;
    int key;
    int next;
    int num = 200000;
};
bool cmp_97(node_97 a,node_97 b){
    return a.num < b.num;
}
int pat_1097(){
    int n,first;
    scanf("%d %d",&first,&n);
    node_97 nodes[100000];
    bool tag[100000] = {false};
    for (int i = 0; i < n; ++i) {
        int index,key,next;
        scanf("%d %d %d",&index,&key,&next);
        nodes[index].id = index;
        nodes[index].key = key;
        nodes[index].next = next;
    }
    int num1 = 0,num2 = 0;
    for (int i = first; i != -1 ; i = nodes[i].next) {
        int a = abs(nodes[i].key);
        if (!tag[a]){
            tag[a] = true;
            nodes[i].num = num1;
            num1++;
        } else {
            nodes[i].num = 100000 + num2;
            num2++;
        }
    }
    int num = num1 + num2;
    sort(nodes,nodes+100000,cmp_97);
    for (int i = 0; i < num; ++i) {
        if (i == num1 - 1 || i == num-1) printf("%05d %d -1\n",nodes[i].id,nodes[i].key);
        else printf("%05d %d %05d\n",nodes[i].id,nodes[i].key,nodes[i+1].id);
    }
    return 0;
}