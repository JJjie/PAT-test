//
//  main.cpp
//  PAT_project
//
//  Created by 胡文杰 on 16/8/11.
//  Copyright © 2016年 胡文杰. All rights reserved.
//

#include <iostream>
#include <string>
#include "1001.hpp"
#include "1002.hpp"
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
        
    }
    
    return 0;
}
