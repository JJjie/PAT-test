//
// Created by 胡文杰 on 2017/2/2.
//

#include "pat.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct stu_75{
    int id;
    int totalscore;
    int perfectsolved = 0;
    int pro[5] = {-2,-2,-2,-2,-2};
};

bool cmp_75(stu_75 a,stu_75 b){
    if (a.totalscore == b.totalscore){
        if (a.perfectsolved == b.perfectsolved){
            return a.id < b.id;
        } else {
            return a.perfectsolved > b.perfectsolved;
        }
    } else {
        return a.totalscore > b.totalscore;
    }
}

int pat_1075(){
    int n,k,m,stuindex,proindex,score;
    scanf("%d %d %d",&n,&k,&m);
    vector<int> problem(k);
    vector<stu_75> students(n+1);
    for (int i = 0; i < k; ++i) {
        scanf("%d",&problem[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d",&stuindex,&proindex,&score);
        students[stuindex].id = stuindex;
        if (score > students[stuindex].pro[proindex-1])
            students[stuindex].pro[proindex-1] = score;

        if (problem[proindex-1] - score == 0)
            students[stuindex].perfectsolved += 1;
    }
    vector<stu_75> ans;
    for (int i = 1; i <= n; ++i) {
        int totalscore = 0;
        int num= 0;//记录为-1的个数
        for (int j = 0; j < k; ++j) {
            int s = students[i].pro[j];
            if (s < 0){
                num ++;
                if (s == -1) students[i].pro[j] = 0;
            } else {
                totalscore += s;
            }
        }
        if (num != k){
            students[i].totalscore = totalscore;
            ans.push_back(students[i]);
        }
    }
    sort(ans.begin(),ans.end(),cmp_75);
    int range = 1,rangescore=ans[0].totalscore;
    for (int i = 0; i < ans.size() ; ++i) {
        if (ans[i].totalscore < rangescore ) {
            rangescore = ans[i].totalscore;
            range = i+1;
        }
        printf("%d %05d %d",range,ans[i].id,ans[i].totalscore);
        for (int j = 0; j < k; ++j) {
            if (ans[i].pro[j] == -2){
                printf(" -");
            } else {
                printf(" %d",ans[i].pro[j]);
            }
        }
        printf("\n");
    }
    return 0;
}