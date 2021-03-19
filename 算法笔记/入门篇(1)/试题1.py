#!/bin/python
# -*- coding: utf8 -*-
import sys
import os
import re

#在保证初始代码结构不变的情况下，可以通过下面“char_count”一个函数实现题目的要求，也可以通过多个函数实现
    
#=============这里往下是你主要编写代码的地方，此区域外的代码都不能删除==================
#入口函数，不能删除，因为在下方有调用

def  char_count(str):  #str = "aaabbcccaab"
    d = {}
    l = len(str)
    Arr_list = list(str)
    print(Arr_list)
    for i in Arr_list:
        if d.get(i):
            d[i] +=1
        else:
            d[i] = 1
    print(d)
    return "OK"

#其他函数可以从这里写起

#=============这里往上是你主要编写代码的地方，此区域外的代码都不能删除==================


try:
    _str = input()
except:
    _str = None

  
res = char_count(_str)

print(res + "\n")