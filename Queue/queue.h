#pragma once

#ifndef _QUEUE_H_
#define _QUEUE_H_
#include<stdio.h>
#include<stdbool.h>
#define MaxQUEUE 10

//typedef int Item;

typedef struct item {
	long arrive;
	int processtime;
}Item;


typedef struct node {
	Item item;
	struct node* next;
}Node;


typedef struct queue {
	Node* front; /*ָ����������ָ��*/
	Node* rear;/*ָ�����β���ָ��*/
	int items; /*��¼�����е�����*/
}Queue;


/*����:��ʼ������*/
/*ǰ������:pqָ��һ������*/
/*��������:���б���ʼ��Ϊ��*/
void InitializeQueue(Queue *pq);

/*����:����?*/
/*ǰ������:pqָ��֮ǰ����ʼ���Ķ���*/
/*��������:��������true���򷵻�false*/
bool QueueIsFull(const Queue* pq);
/*����:�ǿ�?*/
/*ǰ������:pqָ��֮ǰ����ʼ���Ķ���*/
/*��������:Ϊ�շ���true���򷵻�false*/
bool QueueIsEmpty(const Queue* pq);
/*����:ȷ�������е�����*/
/*ǰ������:pqָ��֮ǰ����ʼ���Ķ���*/
/*��������:���ض����е�����*/
int QueueItemCount(const Queue* pq);

/*����:�ڶ���ĩβ�����*/
/*ǰ������:
		pqָ��֮ǰ����ʼ���Ķ���
		item��Ҫ������ڶ���ĩβ����
*/
/*��������:
		������в�Ϊ��,item��������ڶ��е�ĩβ
		����ӷ���true,δ�ı䷵��false
*/
bool EnQueue(Item item, Queue* pq);


/*����:�Ӷ��еĿ�ͷɾ����*/
/*ǰ������:
		pqָ��֮ǰ����ʼ���Ķ���
*/
/*��������:
		������в�Ϊ��,�����׶˵�item����������*pitem
		����ɾ��,�Һ�������true
		����ò���ʹ�ö���Ϊ��,�����ö���Ϊ��
		��������ڲ���ǰΪ��,�ú�������false
*/
bool DeQueue(Item* pitem, Queue* pq);


/*����:��ն���*/
/*ǰ������:pqָ��֮ǰ����ʼ���Ķ���*/
/*��������:���б����*/
void EmptyTheQueue(Queue* pq);

#endif
