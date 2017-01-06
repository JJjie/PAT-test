//
// Created by 胡文杰 on 2017/1/6.
//

#include "pat.h"
#include <iostream>
#include <iomanip>
using namespace std;

struct poly{
    int exp;
    float coe;
    poly *next;
};
typedef poly* polypointer;

void Construct2(int length,polypointer &n);
polypointer Product(polypointer &p1, polypointer &p2);
void freeMemory (polypointer &p);//结构体内存释放

int pat_1009(){
    polypointer A,B;
    int a;
    cin >> a;
    Construct2(a, A);
    cin >> a;
    Construct2(a, B);

    polypointer result = Product(A, B);
    polypointer temp = result->next;
    int Len = 0;
    while (temp != NULL ){
        Len ++ ;
        temp = temp->next;
    }
    cout << Len;
    temp = result->next;
    while (temp != NULL){
        cout << " " << temp->exp << " " << fixed << setprecision(1) << temp->coe ;
        temp = temp->next;
    }
    cout << endl;

    //释放内存
    freeMemory(A);
    freeMemory(B);
    freeMemory(result);

    return 0;
}

void Construct2(int length,polypointer &n){
    n = new poly;//链表head分配内存
    polypointer pre = n;
    while (length > 0){
        polypointer item = new poly;
        cin >> item->exp >> item->coe ;
        item->next = NULL;
        pre->next = item;
        pre = item;
        length--;
    }
}

polypointer Product(polypointer &p1, polypointer &p2){
    polypointer r = new poly;//存储结果的链
    polypointer rpre = r;
    polypointer a = p1->next, b = p2->next;

    int N = a->exp + b->exp;//两个最大的幂想加为结果最大的幂，以此构建动态空间
    int i;
    float *container = new float[N+1];
    for (i = 0; i < N+1; i++) {
        container[i] = 0;
    }

    while (a != NULL){
        b = p2->next;
        while (b != NULL){
            int temp = a->exp + b->exp;
            container[temp] += a->coe * b->coe;
            b = b->next;
        }
        a = a->next;
    }
    for (i = N; i >= 0 ; i--) {
        if (container[i] != 0){
            polypointer item = new poly;
            item->exp = i;
            item->coe = container[i];
            item->next = NULL;
            rpre->next = item;
            rpre = item;
        }
    }

//  释放内存
    delete[] container;

    return r;
}

void freeMemory (polypointer &p){
    polypointer pre = NULL;
    while (p != NULL){
        pre = p;
        p = p->next;
        delete pre;
        pre = NULL;
    }
}