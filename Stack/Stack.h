#include <stdio.h>

#ifndef _STACK_H_
#define _STACK_H_
#include<stdio.h>
#include<stdbool.h>


/* 
* α����
* ��������: ջ
* ��������:�Ƚ����
					ֻ���������һ����Ӻ�ɾ����
					�ѹ��͵���ջ
					LIFO(last in,first out)
* ���Ͳ���:��ʼ��ջΪ��
*					ȷ��ջ�ѿ�
*					ȷ��ջ����
*					ȷ��ջ�е�����
*					��ջ��ѹ����
*					��ջ�е�����
*					���ջ
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

/*����ԭ��*/
/*����:��ʼ��ջ*/
/*ǰ������:pstackָ��һ��δ����ʼ����ջ*/
/*��������:ջ����ʼ��Ϊ��*/
void InitializeStack(Stack* stack);

/*����ԭ��*/
/*����:ȷ��ջ�ѿ�*/
/*ǰ������:pstackָ��һ���ѱ���ʼ����ջ*/
/*��������:�ѿշ���true,���򷵻�false*/
bool StackIsEmpty(Stack* stack);

/*����ԭ��*/
/*����:ȷ��ջ����*/
/*ǰ������:pstackָ��һ���ѱ���ʼ����ջ*/
/*��������:��������true,���򷵻�false*/
bool StackIsFull(Stack* stack);

/*����ԭ��*/
/*����:ȷ��ջ�е�����*/
/*ǰ������:pstackָ��һ���ѱ���ʼ����ջ*/
/*��������:����ջ�е�����*/
int StackGoodsCount(Stack * stack);

/*����ԭ��*/
/*����:��ջ��ѹ����*/
/*ǰ������:pstackָ��һ���ѱ���ʼ����ջ*/
/*��������:����ӳɹ�����true,���򷵻�false*/
bool Push(Goods *goods,Stack* stack);

/*����ԭ��*/
/*����:��ջ�е�����*/
/*ǰ������:pstackָ��һ���ѱ���ʼ����ջ*/
/*��������:��ɾ���ɹ�����true,���򷵻�false*/
bool Pop(Goods *goods,Stack* stack);

/*����ԭ��*/
/*����:���ջ*/
/*ǰ������:pstackָ��һ���ѱ���ʼ����ջ*/
/*��������:ջ��ճɹ�*/
void StackAllClear(Stack* stack);

#endif _STACK_H_