//
// Created by 胡文杰 on 2017/1/19.
//

#include "pat.h"
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int pat_1039(){
    int n, k;
    map<string, vector<int>> stu;
    scanf("%d%d",&n,&k);
    for (int i = 0; i < k; i++) {
        int cindex, num;
        scanf("%d%d",&cindex,&num);
        char stuname[5];
        for (int j = 0; j < num; j++) {
            scanf("%s",stuname);
            stu[stuname].push_back(cindex);
        }
    }
    for (int i = 0; i < n; i++) {
        char targetname[5];
        scanf("%s",targetname);
        int len = stu[targetname].size();
        sort(stu[targetname].begin(), stu[targetname].end());
        printf("%s %d",targetname,len);
        for (int j = 0; j < len; j++) {
            printf(" %d",stu[targetname][j]);
        }
        cout << endl;
    }
    return 0;
}