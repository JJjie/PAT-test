//
// Created by 胡文杰 on 2017/1/25.
//

#include "pat.h"
#include <iostream>
#include <cstring>
using namespace std;

int pat_1060(){
    int n;
    char n1[10000],n2[10000];
    scanf("%d %s %s",&n, n1, n2);
    int len1=strlen(n1),len2=strlen(n2);//10^的系数
    int index1=0, index2=0; // 排除前面有0的情况
    for (int i = 0; i < len1; i++) {
        if (n1[i] == '.'){
            len1 = i;
            break;
        }
    }
    for (int i = 0; i < len2; i++) {
        if (n2[i] == '.'){
            len2 = i;
            break;
        }
    }
    while (n1[index1] == '0' || n1[index1] == '.') index1 ++; // 真值前有0的情况
    while (n2[index2] == '0' || n2[index2] == '.') index2 ++;
    if (len1 >= index1) len1 = len1 - index1;// 例如：001.23,000.123
    else len1 = len1 -index1 + 1;// 例如：000.0123
    if (len2 >= index2) len2 = len2 - index2;
    else len2 = len2 -index2 + 1;

    char tag1[n+1],tag2[n+1];
    int i=0;
    while (i<n){
        if (n1[index1] != '.' && index1 < strlen(n1)){
            tag1[i] = n1[index1];
            i++;
        } else if (index1 >= strlen(n1)){
            tag1[i] = '0'; // 4 1.2 => 0.1200
            i++;
        }
        index1++;
    }
    tag1[i] = '\0';
    i=0;
    while (i<n){
        if (n2[index2] != '.' && index2 < strlen(n2)){
            tag2[i] = n2[index2];
            i++;
        } else if (index2 >= strlen(n2)){
            tag2[i] = '0';
            i++;
        }
        index2++;
    }
    tag2[i] = '\0';

    if (len1 != len2){
        printf("NO 0.%s*10^%d 0.%s*10^%d",tag1,len1,tag2,len2);
        return 0;
    }
    bool state = (strcmp(tag1,tag2) == 0);
    if (state) printf("YES 0.%s*10^%d",tag1,len1);
    else printf("NO 0.%s*10^%d 0.%s*10^%d",tag1,len1,tag2,len2);

    return 0;
}