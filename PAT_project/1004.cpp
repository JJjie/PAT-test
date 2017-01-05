//
//  1004.cpp
//  PAT_project
//  树的遍历 dfs bfs
//  Created by 胡文杰 on 2017/1/5.
//  Copyright © 2017年 胡文杰. All rights reserved.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int>* node);
void DFS(vector<int>* node, int* level, int index, int deepth);

int maxdeepth = -1;//DFS初始最大深度

int pat_1004(){
    
    int N, M, ID, K, child;
    int i, j;
    
    //构建树结构（二维数组，N*M）
    cin >> N >> M;
    vector<int> *Nodes = new vector<int>[N];
    for (i=0; i<M; i++) {
        cin >> ID >> K;
        for (j=0; j<K; j++) {
            cin >> child;
            Nodes[ID-1].push_back(child-1);
        }
    }
    
    //BFS
    BFS(Nodes);
    
    //DFS
    int *level = new int[N];//标记每层的叶子数
    for (i=0; i<N; i++) {
        level[i] = 0;
    }
    
    DFS(Nodes, level, 0, 0);
    
    cout << level[0];
    for (i=1; i<=maxdeepth; i++) {
        cout << " " << level[i];
    }
    cout << endl;
    
    //释放内存
    for (i=0; i<M; i++) {
        vector<int>(Nodes[i]).swap(Nodes[i]);
    }
    delete[] level;
    
    
    return 0;
}

void BFS(vector<int>* node){
    queue<int> layer;
    layer.push(0);
    while (!layer.empty())
    {
        int num_leaf = 0;
        int i, j;
        int cursize = layer.size();
        for (i=0; i < cursize; i++)
        {
            int one = layer.front();
            if (node[one].empty())
            {
                num_leaf ++ ;
            }
            else
            {
                for (j=0; j < node[one].size(); j++) {
                    layer.push(node[one][j]);
                }
            }
            layer.pop();
        }
        cout << num_leaf;
        if (!layer.empty()) {
            cout << " ";
        }
    }
    cout << endl;
}

void DFS(vector<int>* node, int* level, int index, int deepth){
    if (node[index].empty()) {
        level[deepth]++;
        maxdeepth = max(maxdeepth, deepth);
        return;
    }else{
        for (int i=0; i<node[index].size(); i++) {
            DFS(node, level, node[index][i], deepth+1);
        }
    }
}
