//
//  1003.cpp
//  PAT_project
//
//  Created by 胡文杰 on 2017/1/4.
//  Copyright © 2017年 胡文杰. All rights reserved.
//

#include "pat.h"
#include <iostream>
using namespace std;


int pat_1003(){
    int num_city, num_road, outset, destination;
    int i,j;
    cin >> num_city >> num_road >> outset >> destination;
    
    int **road = new int *[num_city];//二元数组
    //构建邻接矩阵
    for (i=0 ; i<num_city; i++) {
        road[i] = new int[num_city];
        for (j=0; j<num_city; j++) {
            road[i][j] = INT_MAX;
        }
        road[i][i] = 0;
        
    }
    int *teams = new int[num_road];
    for (i=0; i<num_city; i++) {
        cin >> teams[i];
    }

    for (i=0; i<num_road; i++) {
        int a,b,len;
        cin >> a >> b >> len;
        
        road[a][b] = len;
        road[b][a] = len;
    }
        
    //预备参数
    int *equalpath = new int[num_city];//相同路径条数
    int *max = new int[num_city];//最大要求的team数量
    int *shortestpath = new int[num_city];//outset到i_th的最短距离
    bool *visited = new bool[num_city];//标记i_th是否被访问
    for (i=0; i<num_city; i++) {
        visited[i] = false;
        if (i==outset) {
            shortestpath[i] = 0;
            equalpath[i] = 1;
            max[i] = teams[i];
            visited[i] = true;
        }else{
            shortestpath[i] = road[outset][i];
            if (shortestpath[i] == INT_MAX) {
                equalpath[i] = 0;
                max[i] = teams[i];
            }else{
                equalpath[i] = 1;
                max[i] = teams[outset] + teams[i];
            }
        }
    }
    
    //dijkstra
    int min,v=0;
    for (i=1; i<num_city; i++) {//
        min = INT_MAX;
        for (j=0; j<num_city; j++) {//找一条outset出发的最短路
            if (!visited[j] && shortestpath[j] < min) {
                min = shortestpath[j];
                v = j;
            }
        }
        if (v == destination) {
            break;
        }
        visited[v]=true;
        for (j=0; j<num_city; j++) {
            if (!visited[j] && road[v][j] < INT_MAX)
            {
                shortestpath[j] = min + road[v][j];
                equalpath[j] = equalpath[v];
                max[j] += max[v];
            }
            else if(min + road[v][j] == shortestpath[j])
            {
                equalpath[j] += equalpath[v];
                if (max[v] + teams[j] > max[j])
                {
                    max[j] = max[v] + teams[j];
                }
            }
        }
    }
    
    cout << equalpath[destination] << " " << max[destination];
    
    //释放内存
    for (i=0; i<num_city; i++) {
        delete[] road[i];
    }
    delete[] road;
    delete[] teams;
    delete[] equalpath;
    delete[] shortestpath;
    delete[] visited;
    
    return 0;
}
