#pragma once
#include <stdio.h>

#ifndef _STACK_WORD_H_
#define _STACK_WORD_H_
#include<stdio.h>
#include<stdbool.h>


/*
* 伪代码
* 类型名称: 栈
* 类型属性:先进后出
					只能在链表的一端添加和删除项
					项被压入和弹出栈
					LIFO(last in,first out)
* 类型操作:初始化栈为空
*					确定栈已空
*					确定栈已满
*					确定栈中的项数
*					在栈中压入项
*					在栈中弹出项
*					清空栈
*/

#define MAXSIZE 40

typedef struct  node {
	char words;
	struct node* next;
}Node;

typedef struct stack {
	Node* front;
	int n_words;
}Stack;

/*函数原型*/
/*操作:初始化栈*/
/*前提条件:pstack指向一个未被初始化的栈*/
/*后置条件:栈被初始化为空*/
void InitializeStack_Words(Stack* pstack);

/*函数原型*/
/*操作:确定栈已空*/
/*前提条件:pstack指向一个已被初始化的栈*/
/*后置条件:已空返回true,否则返回false*/
bool Stack_Words_IsEmpty(Stack* pstack);

/*函数原型*/
/*操作:确定栈已满*/
/*前提条件:pstack指向一个已被初始化的栈*/
/*后置条件:已满返回true,否则返回false*/
bool Stack_Words_IsFull(Stack* pstack);

/*函数原型*/
/*操作:确定栈中的项数*/
/*前提条件:pstack指向一个已被初始化的栈*/
/*后置条件:返回栈中的项数*/
int Stack_WordsCount(Stack* pstack);

/*函数原型*/
/*操作:向栈中压入项*/
/*前提条件:pstack指向一个已被初始化的栈*/
/*后置条件:项添加成功返回true,否则返回false*/
bool EnStack_Words(char*words, Stack* pstack);

/*函数原型*/
/*操作:向栈中弹出项*/
/*前提条件:pstack指向一个已被初始化的栈*/
/*后置条件:项删除成功返回true,否则返回false*/
char DeStack_Words(char words,Stack* pstack);

/*函数原型*/
/*操作:清空栈*/
/*前提条件:pstack指向一个已被初始化的栈*/
/*后置条件:栈清空成功*/
void Stack_Words_AllClear(Stack* pstack);

#endif _STACK_WORD_H_