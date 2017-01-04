//
//  1002.cpp
//  PAT_project
//
//  Created by 胡文杰 on 16/8/15.
//  Copyright © 2016年 胡文杰. All rights reserved.
//

#include "pat.h"
#include <iostream>
#include <iomanip>
using namespace std;

struct poly {
    int exp;
    float coe;
    poly * next;
};
typedef poly * polypointer;

void Construct(int length,polypointer &n);
int Add(polypointer &A,polypointer &B);
char Compare(int a, int b);

void pat_1002(){
    int k;
    polypointer A,B,temp;
    cin >> k;
    Construct(k, A);
    cin >> k;
    Construct(k, B);
    
    k = Add(A, B);
    cout << k;
    temp=A->next;
    delete A;
    while (temp != NULL) {
        cout << " " << temp->exp << " " << fixed << setprecision(1) << temp->coe ; //小数点1位数，iomanip头文件
        A = temp;
        temp = temp->next;
        delete A;
    }
    cout << endl;
}

void Construct(int length,polypointer &n){        //输入构造多项式
    n = new poly;
    polypointer pre = n;
    while (length > 0) {
        polypointer item = new poly;
        cin >> item->exp >> item->coe ;
        item->next = NULL;
        pre->next = item;
        pre = item;
        length--;
    }
}

int Add(polypointer &A,polypointer &B){//多项式和操作
    int length = 0;
    polypointer p,q,pre,temp;
    p = A->next;
    q = B->next;
    pre = A;
    delete B;
    while ((p != NULL) && (q != NULL)) {
        switch (Compare(p->exp, q->exp)) {
            case '=':
                p->coe += q->coe;
                temp = q;
                q = q->next;
                delete temp;
                if (p->coe == 0) {
                    temp = p;
                    p = p->next;
                    delete temp;
                }else{
                    length++;
                    pre->next = p;
                    pre = pre->next;
                    p = p->next;
                }
                break;
            case '>':
                length++;
                pre->next = p;
                pre = pre->next;
                p = p->next;
                break;
            case '<':
                length++;
                pre->next = q;
                pre = pre->next;
                q = q->next;
                break;
            default:
                break;
        }
    }
    while (p != NULL) {
        length++;
        pre->next = p;
        pre = pre->next;
        p = p->next;
    }
    while (q != NULL) {
        length++;
        pre->next = q;
        pre = pre->next;
        q = q->next;
    }
    pre->next = NULL;
    return length;
}

char Compare(int a, int b){
    if (a==b) {
        return '=';
    }else if (a > b){
        return '>';
    }else{
        return '<';
    }
}
