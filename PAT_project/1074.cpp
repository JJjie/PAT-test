//
// Created by 胡文杰 on 2017/2/1.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct node_74{
    int data;
    int next;
};

int pat_1074(){
    int first,n,k;
    cin >> first >> n >> k;
    vector<node_74> nodes(100000);
    for (int i = 0; i < n; ++i) {
        int add,key,next;
        cin >> add >> key >> next;
        nodes[add].data = key;
        nodes[add].next = next;
    }
    int index = first,temp=0;
    for (int i = first; i != -1 ; i = nodes[i].next) {
        temp++;
        if (temp == k) first = i;
    }
    stack<int> s;
    while (index != -1){
        for (int i = 0; i < k; ++i) {
            if (index == -1) break;
            s.push(index);
            index = nodes[index].next;
        }
        int t = index;
        temp = 0;
        for (int i = t; i != -1 ; i = nodes[i].next) {
            temp++;
            if(temp == k) t = i;
        }
        if (s.size() == k){
            while (!s.empty()){
                int add = s.top();
                s.pop();
                if (s.empty()){
                    nodes[add].next = t;
                } else {
                    nodes[add].next = s.top();
                }
            }
        }
    }
    for (int i = first; i != -1 ; i = nodes[i].next){
        if (nodes[i].next == -1){
            printf("%05d %d %d\n",i,nodes[i].data,nodes[i].next);
        } else{
            printf("%05d %d %05d\n",i,nodes[i].data,nodes[i].next);
        }
    }
    return 0;
}