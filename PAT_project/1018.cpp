//
// Created by 胡文杰 on 2017/1/10.
//

#include "pat.h"
#include <iostream>
#include <vector>
using namespace std;
vector<int> path,temppath;
int minNeed = INT_MAX, minBack = INT_MAX;

void DFS(int sp, int *weight, vector<int> *pre);

int pat_1018(){
    int C_MAX, N, SP, M;
    cin >> C_MAX >> N >> SP >> M;
    N = N+1;
    int **roads = new int*[N];//道路图的邻接矩阵
    int *weight = new int[N];//每一个结点的单车数目
    bool *visited = new bool[N];
    int *destination = new int[N];//到达每一个结点的最短路径
    vector<int> *pre = new vector<int>[N];//记录到这个点之前的最短路径
    for (int i = 0; i < N; i++) {
        roads[i] = new int[N];
    }
    fill(roads[0], roads[0]+N*N, INT_MAX);
    fill(visited, visited+N, false);
    fill(destination, destination+N, INT_MAX);

    for (int i = 1; i < N; i++) {
        int w;
        cin >> w;
        weight[i] = w - C_MAX/2;
    }
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        roads[a][b] = c;
        roads[b][a] = c;
    }

//    dijkstra
    destination[0] = 0;
    for (int i = 0; i < N; i++) {
        int u = -1, min = INT_MAX;
        for (int j = 0; j < N; j++) {//找出未访问的点
            if (!visited[j] && destination[j] < min){
                u = j;
                min = destination[j];
            }
        }
        if (u == -1) break;
        visited[u] = true;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && roads[u][j] != INT_MAX){
                if (destination[j] > destination[u] + roads[u][j]){
                    destination[j] = destination[u] + roads[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                }else if (destination[j] == destination[u] + roads[u][j]){
                    pre[j].push_back(u);
                }
            }
        }
    }

//    dfs
    DFS(SP,weight,pre);

    cout << minNeed << " 0" ;
    for (int i = path.size() - 2; i >= 0 ; i--) {
        cout << "->" << path[i] ;
    }
    cout << " " <<minBack << endl;

//    释放内存
    for (int i = 0; i < N; i++) {
        delete[] roads[i];
    }
    delete[] weight;
    delete[] destination;
    delete[] visited;
//    delete[] pre;
    return 0;
}

void DFS(int sp, int *weight, vector<int> *pre){
    if (sp == 0){//PBMC
        temppath.push_back(sp);
        int need = 0, back = 0;
        for (int i = temppath.size(); i >=0 ; i--) {
            int id = temppath[i];
            if (weight[id] > 0){
                back += weight[id];
            } else {
                if (back > (-weight[id])){
                    back += weight[id];//供大于求
                }else{
                    need += ((-weight[id]) - back);//供不应求
                    back = 0;
                }
            }
        }
        if(need < minNeed){
            minNeed = need;
            minBack = back;
            path = temppath;
        }else if (need == minNeed && back < minBack){
            minBack = back;
            path = temppath;
        }
        temppath.pop_back();
        return ;
    }
    temppath.push_back(sp);
    for (int i = 0; i < pre[sp].size(); i++) {
        DFS(pre[sp][i],weight,pre);
    }
    temppath.pop_back();
}