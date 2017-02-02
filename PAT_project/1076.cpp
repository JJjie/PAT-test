//
// Created by 胡文杰 on 2017/2/2.
//

#include "pat.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node_76{
    int id;
    int layer;
};

int pat_1076(){
    int n,l;
    scanf("%d %d",&n,&l);
    vector<vector<int> > map(n+1);
    for (int i = 1; i <= n ; ++i) {
        int m;
        scanf("%d",&m);
        for (int j = 0; j < m; ++j) {
            int temp;
            scanf("%d",&temp);
            map[temp].push_back(i);
        }
    }
    int k;
    scanf("%d",&k);
    int id,layer;
    for (int i = 0; i < k; ++i) {
        scanf("%d",&id);
        node_76 tnode;
        tnode.id = id;
        tnode.layer = 0;
//       bfs
        bool visited[1001] = {false};
        queue<node_76> q;
        q.push(tnode);
        visited[id] = true;
        int ans = 0;
        while (!q.empty()){
            node_76 top = q.front();
            q.pop();
            int tid = top.id;
            for (int j = 0; j < map[tid].size(); ++j) {
                int nextid = map[tid][j];
                if (!visited[nextid] && top.layer < l){
                    node_76 next;
                    next.id = nextid;
                    next.layer = top.layer + 1;
                    q.push(next);
                    visited[nextid] = true;
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}