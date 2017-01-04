//
//  1002.cpp
//  PAT_project
//
//  Created by 胡文杰 on 16/8/15.
//  Copyright © 2016年 胡文杰. All rights reserved.
//

#include "1002.hpp"
#include <iostream>
using namespace std;

struct poly {
    int exp;
    float coe;
    poly *next;
};
typedef poly * polypointer;

polypointer  Construct(int length,polypointer n);
polypointer Attach(int exp,float coe,polypointer d);
polypointer Add(polypointer A,polypointer B);
char Compare(int a, int b);

void pat_1002(){
    int k,L=0;
    polypointer A,B,C,D;
    cin >> k;
    A = Construct(k, A);
    cin >> k;
    B = Construct(k, B);
    
    C = Add(A, B);
    D = C;
    while (D != NULL) {
        L++;
        D = D->next;
    }
    cout << L << " ";
    D = C;
    while (D->next != NULL) {
        cout << D->exp << " " << D->coe << " ";
        D = D->next;
    }//去除末尾的空格
    cout << D->exp << " " << D->coe << endl;
}

polypointer Construct(int length,polypointer n){        //输入构造多项式
    n = new poly;
    polypointer pre = n;
    while (length > 0) {
        polypointer item = new poly;
        cin >> pre->exp >> pre->coe ;
        pre->next = item;
        pre = item;
        length--;
    }
    pre->next = NULL;
    return n;
}
polypointer Attach(int exp,float coe,polypointer d){//将多项式的单独项添加到末尾，返回末尾指针
    polypointer x = new poly;
    x->exp = exp;
    x->coe = coe;
    d->next = x;
    return x;
}

polypointer Add(polypointer A,polypointer B){//多项式和操作
    polypointer p,q,d,c;
    float x;
    p = A;
    q = B;
    d = new poly;
    c = d;
    while ((p != NULL) && (q != NULL)) {
        switch (Compare(p->exp, q->exp)) {
            case '=':
                x = p->coe + q->coe;
                if (x != 0) {
                    d = Attach(p->exp, x, d);
                    p = p->next;
                    q = q->next;
                }
                break;
            case '>':
                d = Attach(p->exp, p->coe, d);
                p = p->next;
                break;
            case '<':
                d = Attach(q->exp, q->coe, d);
                q = q->next;
                break;
            default:
                break;
        }
    }
    while (p != NULL) {
        d = Attach(p->exp, p->coe, d);
        p = p->next;
    }
    while (q != NULL) {
        d = Attach(q->exp, q->coe, d);
        q = q->next;
    }
    d = NULL;
    return c;
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
