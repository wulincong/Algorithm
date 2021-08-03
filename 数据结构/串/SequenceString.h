#ifndef SEQUENCESTRING 
#define SEQUENCESTRING

#include <stdio.h>
#include <string.h>
#include "Status.h"

#define MAXSTRING 255

typedef unsigned char SString[MAXSTRING + 1];

Status StrAssign_Sq(SString T, const char *chars);
//生成一个其值等于常量chars的串T

void StrCpoy_Sq(SString T, SString S);
// 由串S复制得到串T

Status StrEmpty_Sq(SString S);
//若S为空串返回TRUE， 否则返回FALSE

int StrCompare_Sq(SString S, SString T);
//若S>t,返回值>0, 若S<T，返回值<0，相等返回0

int StrLength_Sq(SString S);
//求串长

void ClearString_Sq(SString S);
//清空串

Status Concat(SString T, SString S1, SString S2);
//用T返回由S1 和S2 连结成的新串

Status SubString_Sq(SString Sub, SString S, int pos, int len);
//用Sub返回串S的第pos起长度len的子串

int Index_Sq_1(SString S, SString T, int pos);
//算法4.1 返回T在S中pos个字符后第一次出现的位置，不存在返回-1

int Index_Sq_2(SString S, SString T, int pos);
//算法4.5 返回T在S中pos个字符后第一次出现的位置，不存在返回-1

Status Replace_Sq(SString S, SString T, SString V);
//用V替换主串S中出现的所有与T相等的不重叠的字串，可以完全替代返回1

Status StrInsert_Sq(SString S,int pos, SString T);
//在串S的pos个字符前插入串T，可以完全插入返回OK，否则返回ERROR

Status StrDelete_Sq(SString S,int pos, int len);
//从串S中删除第pos个字符起长度为len的子串

void DestroyString_Sq(SString S);
//销毁串S

void StrPrint_Sq(SString S);
//输出串S

#endif