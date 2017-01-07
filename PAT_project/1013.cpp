//
// Created by 胡文杰 on 2017/1/7.
//

#include "pat.h"
#include <iostream>
using namespace std;
int N;

void DFS(int **cities, int index, bool *visited);

int pat_1013(){
    int M, K;
    cin >> N >> M >> K;
    int **cities = new int *[N];
    bool *visited = new bool [N];
    for (int i = 0; i < N; i++) {
        cities[i] = new int [N];
        visited[i] = false;
        for (int j = 0; j < N; j++) {
            cities[i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        int i1, i2;
        cin >> i1 >> i2;
        i1 = i1-1, i2 = i2-1;
        cities[i1][i2] = 1;
        cities[i2][i1] = 1;
    }
    for (int i = 0; i < K; i++) {
        int target, num = 0;
        for (int j = 0; j < N; j++) {//每一次假设占领前将visited初始化
            visited[j] = false;
        }
        cin >> target;
        visited[target-1] = true;
        for (int j = 0; j < N; j++) {
            if (!visited[j]){
                DFS(cities, j, visited);
                num ++;
            }
        }
        cout << num-1 << endl;
    }

//    释放内存
    for (int i = 0; i < N; i++) {
        delete[] cities[i];
    }
    delete[] visited;

    return 0;
}

void DFS(int **cities, int index, bool *visited){
    visited[index] = true;
    for (int i = 0; i < N; ++i) {
        if (!visited[i] && cities[index][i] == 1){
            DFS(cities, i, visited);
        }
    }
}