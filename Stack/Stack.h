#include <stdio.h>

#ifndef _STACK_H_
#define _STACK_H_
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
typedef struct goods {
	char goods_name[MAXSIZE];
	int value;
}Goods;

typedef struct  node {
	Goods goods;
	struct node* next;
}Node;

typedef struct stack {
	Node* top;
	int size;
}Stack;

/*函数原型*/
/*操作:初始化栈*/
/*前提条件:pstack指向一个未被初始化的栈*/
/*后置条件:栈被初始化为空*/
void InitializeStack(Stack* stack);

/*函数原型*/
/*操作:确定栈已空*/
/*前提条件:pstack指向一个已被初始化的栈*/
/*后置条件:已空返回true,否则返回false*/
bool StackIsEmpty(Stack* stack);

/*函数原型*/
/*操作:确定栈已满*/
/*前提条件:pstack指向一个已被初始化的栈*/
/*后置条件:已满返回true,否则返回false*/
bool StackIsFull(Stack* stack);

/*函数原型*/
/*操作:确定栈中的项数*/
/*前提条件:pstack指向一个已被初始化的栈*/
/*后置条件:返回栈中的项数*/
int StackGoodsCount(Stack * stack);

/*函数原型*/
/*操作:向栈中压入项*/
/*前提条件:pstack指向一个已被初始化的栈*/
/*后置条件:项添加成功返回true,否则返回false*/
bool Push(Goods *goods,Stack* stack);

/*函数原型*/
/*操作:向栈中弹出项*/
/*前提条件:pstack指向一个已被初始化的栈*/
/*后置条件:项删除成功返回true,否则返回false*/
bool Pop(Goods *goods,Stack* stack);

/*函数原型*/
/*操作:清空栈*/
/*前提条件:pstack指向一个已被初始化的栈*/
/*后置条件:栈清空成功*/
void StackAllClear(Stack* stack);

#endif _STACK_H_