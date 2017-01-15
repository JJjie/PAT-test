//
// Created by 胡文杰 on 2017/1/15.
//

#include "pat.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct student{
    long long ID ;
    int score, fr, ln, lr;
};
bool cmpstu(student A, student B){
    if (A.score != B.score){
        return A.score > B.score;
    }else{
        return A.ID < B.ID;
    }
}
int pat_1025(){
    int n,m;
    cin >> n;
    vector<student> finalrank;
    for (int i = 0; i < n; i++) {
        cin >> m;
        vector<student> locals(m);
        for (int j = 0; j < m; j++) {
            cin >> locals[j].ID >> locals[j].score ;
            locals[j].ln = i+1;
        }
        sort(locals.begin(), locals.end(), cmpstu);
        locals[0].lr = 1;
        finalrank.push_back(locals[0]);
        for (int j = 1; j < m; j++) {
            locals[j].lr = (locals[j].score == locals[j-1].score) ? locals[j-1].lr : (j+1);
            finalrank.push_back(locals[j]);
        }
    }
    sort(finalrank.begin(), finalrank.end(), cmpstu);
    int len = finalrank.size();
    finalrank[0].fr = 1;
    for (int i = 1; i < len; i++) {
        finalrank[i].fr = (finalrank[i].score == finalrank[i-1].score) ? finalrank[i-1].fr : (i+1);
    }
    cout << len << endl;
    for (int i = 0; i < len; i++) {
        printf("%013lld %d %d %d\n",finalrank[i].ID,finalrank[i].fr,finalrank[i].ln,finalrank[i].lr);
    }

    return 0;
}