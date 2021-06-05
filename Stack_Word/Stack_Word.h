#pragma once
#include <stdio.h>

#ifndef _STACK_WORD_H_
#define _STACK_WORD_H_
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

typedef struct  node {
	char words;
	struct node* next;
}Node;

typedef struct stack {
	Node* front;
	int n_words;
}Stack;

/*����ԭ��*/
/*����:��ʼ��ջ*/
/*ǰ������:pstackָ��һ��δ����ʼ����ջ*/
/*��������:ջ����ʼ��Ϊ��*/
void InitializeStack_Words(Stack* pstack);

/*����ԭ��*/
/*����:ȷ��ջ�ѿ�*/
/*ǰ������:pstackָ��һ���ѱ���ʼ����ջ*/
/*��������:�ѿշ���true,���򷵻�false*/
bool Stack_Words_IsEmpty(Stack* pstack);

/*����ԭ��*/
/*����:ȷ��ջ����*/
/*ǰ������:pstackָ��һ���ѱ���ʼ����ջ*/
/*��������:��������true,���򷵻�false*/
bool Stack_Words_IsFull(Stack* pstack);

/*����ԭ��*/
/*����:ȷ��ջ�е�����*/
/*ǰ������:pstackָ��һ���ѱ���ʼ����ջ*/
/*��������:����ջ�е�����*/
int Stack_WordsCount(Stack* pstack);

/*����ԭ��*/
/*����:��ջ��ѹ����*/
/*ǰ������:pstackָ��һ���ѱ���ʼ����ջ*/
/*��������:����ӳɹ�����true,���򷵻�false*/
bool EnStack_Words(char*words, Stack* pstack);

/*����ԭ��*/
/*����:��ջ�е�����*/
/*ǰ������:pstackָ��һ���ѱ���ʼ����ջ*/
/*��������:��ɾ���ɹ�����true,���򷵻�false*/
char DeStack_Words(char words,Stack* pstack);

/*����ԭ��*/
/*����:���ջ*/
/*ǰ������:pstackָ��һ���ѱ���ʼ����ջ*/
/*��������:ջ��ճɹ�*/
void Stack_Words_AllClear(Stack* pstack);

#endif _STACK_WORD_H_