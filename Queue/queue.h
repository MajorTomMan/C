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
	Node* front; /*指向队列首项的指针*/
	Node* rear;/*指向队列尾项的指针*/
	int items; /*记录队列中的项数*/
}Queue;


/*操作:初始化队列*/
/*前提条件:pq指向一个队列*/
/*后置条件:队列被初始化为空*/
void InitializeQueue(Queue *pq);

/*操作:已满?*/
/*前提条件:pq指向之前被初始化的队列*/
/*后置条件:已满返回true否则返回false*/
bool QueueIsFull(const Queue* pq);
/*操作:非空?*/
/*前提条件:pq指向之前被初始化的队列*/
/*后置条件:为空返回true否则返回false*/
bool QueueIsEmpty(const Queue* pq);
/*操作:确定队列中的项数*/
/*前提条件:pq指向之前被初始化的队列*/
/*后置条件:返回队列中的项数*/
int QueueItemCount(const Queue* pq);

/*操作:在队列末尾添加项*/
/*前提条件:
		pq指向之前被初始化的队列
		item是要被添加在队列末尾的项
*/
/*后置条件:
		如果队列不为空,item将被添加在队列的末尾
		已添加返回true,未改变返回false
*/
bool EnQueue(Item item, Queue* pq);


/*操作:从队列的开头删除项*/
/*前提条件:
		pq指向之前被初始化的队列
*/
/*后置条件:
		如果队列不为空,队列首端的item将被拷贝到*pitem
		并被删除,且函数返回true
		如果该操作使得队列为空,则重置队列为空
		如果队列在操作前为空,该函数返回false
*/
bool DeQueue(Item* pitem, Queue* pq);


/*操作:清空队列*/
/*前提条件:pq指向之前被初始化的队列*/
/*后置条件:队列被清空*/
void EmptyTheQueue(Queue* pq);

#endif
