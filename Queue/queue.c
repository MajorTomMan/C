#include<stdio.h>
#include"queue.h"
#include<stdlib.h>



//Queue *pq 是指向队列的指针
//Item *pi是指向整型的指针
//Node *pn是指向
static void CopyToNode(Item item, Node* pn);

static void CopyToItem(Node* pn, Item* pi);

void InitializeQueue(Queue* pq) {
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

bool QueueIsFull(const Queue* pq) {
	return pq->items == MaxQUEUE;
}
bool QueueIsEmpty(const Queue* pq) {
	return pq->items == 0;
}

int QueueItemCount(const Queue* pq) {
	return pq->items;
}
bool EnQueue(Item item, Queue* pq) {  //Item 为int类型
	Node* pnew; //用于拷贝数据
	if (QueueIsFull(pq)) {
		return false;  
	}
	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL) {
		fprintf(stderr, "Unable to allocate memory!\n");
		exit(1);
	}
	CopyToNode(item, pnew); //队列赋值函数
	pnew->next = NULL; //重置为NULL代表这是尾项
	if (QueueIsEmpty(pq)) {
		pq->front = pnew;/*项位于队列首端*/
	}
	else {
		pq->rear->next = pnew; /*链接到队列尾端*/
	}
	pq->rear = pnew;
	pq->items++;
}
bool DeQueue(Item* pitem, Queue* pq) { //Item是指向int类型的指针 
	Node* pt; //临时指针
	if (QueueIsEmpty(pq)) {
		return false;
	}
	CopyToItem(pq->front, pitem);  //拷贝数据至指定变量
	pt = pq->front;
	pq->front = pq->front->next;
	free(pt);
	pq->items--;
	if (pq->items == 0) {
		pq->rear = NULL;
	}
	return true;
}
void EmptyTheQueue(Queue* pq) {
	Item dummy;
	while (!QueueIsEmpty(pq)) {
		DeQueue(&dummy, pq);
	}
}

/*局部函数*/

static void CopyToNode(Item item, Node* pn) {
	pn->item = item;
}

static void CopyToItem(Node* pn,Item *pi) {
	*pi = pn->item;
}
