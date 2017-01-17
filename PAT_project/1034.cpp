//
// Created by 胡文杰 on 2017/1/17.
//

#include "pat.h"
#include <iostream>
#include <map>
using namespace std;
map<string, int> nameToint;
map<int, string> intToname;
int idnum = 1;

int stoifunc(string s){
    if (nameToint[s] == 0){
        nameToint[s] = idnum;
        intToname[idnum] = s;
        return idnum++;
    }else{
        return nameToint[s];
    }
}
void DFS(int u, int &head, int &numMember, int &totalWeight, bool *visited, int *weight, int **callrecord){
    visited[u] = true;
    numMember ++;
    if (weight[u] > weight[head]) head = u;
    for (int i = 1; i < idnum; i++) {
        if (callrecord[u][i] > 0){
            totalWeight += callrecord[u][i];
            callrecord[u][i] = callrecord[i][u] = 0;
            if (!visited[i]){
                DFS(i, head, numMember, totalWeight, visited, weight, callrecord);
            }
        }
    }
}

int pat_1034(){
    int n, k, c;
    cin >> n >> k;
    map<string, int> result;
    int N = 2*n + 1;
    int *weight = new int[N];
    int **callrecord = new int *[N];
    bool *visited = new bool[N];
    fill(weight, weight+N, 0);
    fill(visited, visited+N, false);
    for (int i = 0; i < N; i++) {
        callrecord[i] = new int [N];
        fill(callrecord[i], callrecord[i]+N, 0);
    }

    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2 >> c;
        int id1 = stoifunc(s1);
        int id2 = stoifunc(s2);
        weight[id1] += c;
        weight[id2] += c;
        callrecord[id1][id2] += c;
        callrecord[id2][id1] += c;
    }

//    dfs
    for (int i = 1; i < idnum; i++) {
        if (!visited[i]){
            int head = i, numMember = 0, totalweight = 0;
            DFS(i, head, numMember, totalweight, visited, weight, callrecord);
            if (numMember > 2 && totalweight > k){
                result[intToname[head]] = numMember;
            }
        }
    }

    int len = result.size();
    cout << len << endl;
    for (map<string, int>::iterator it = result.begin();it != result.end();it++) {
        cout << it->first << " " << it->second << endl;
    }

    delete[] weight;
    delete[] visited;
    for (int i = 0; i < 2*n; i++) {
        delete[] callrecord[i];
    }
    return 0;
}