//
//  main.cpp
//  PAT_project
//
//  Created by 胡文杰 on 16/8/11.
//  Copyright © 2016年 胡文杰. All rights reserved.
//

#include <iostream>
#include <string>
#include "pat.h"
using namespace std;

int main(int argc, const char * argv[]) {
    int tag;
    cout << "请输入要运行的test编号：\n";
    cin >> tag;
    cin.ignore(); //忽略回车符
    if (tag == 1) {
        pat_1001();
    }else if (tag == 2){
        pat_1002();
    }else if (tag == 3){
        pat_1003();
    }else if (tag == 4){
        pat_1004();
    }
    else if (tag == 5){
        pat_1005();
    }
    else if (tag == 6){
        pat_1006();
    }
    else if (tag == 7){
        pat_1007();
    }
    else if (tag == 8){
        pat_1008();
    }
//    else if (tag == 9){
//        pat_1009();
//    }
//    else if (tag == 10){
//        pat_1010();
//    }
//    else if (tag == 11){
//        pat_1011();
//    }
//    else if (tag == 12){
//        pat_1012();
//    }
//    else if (tag == 13){
//        pat_1013();
//    }
//    else if (tag == 14){
//        pat_1014();
//    }
//    else if (tag == 15){
//        pat_1015();
//    }
//    else if (tag == 16){
//        pat_1016();
//    }

    return 0;
}
