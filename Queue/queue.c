#include<stdio.h>
#include"queue.h"
#include<stdlib.h>



//Queue *pq ��ָ����е�ָ��
//Item *pi��ָ�����͵�ָ��
//Node *pn��ָ��
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
bool EnQueue(Item item, Queue* pq) {  //Item Ϊint����
	Node* pnew; //���ڿ�������
	if (QueueIsFull(pq)) {
		return false;  
	}
	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL) {
		fprintf(stderr, "Unable to allocate memory!\n");
		exit(1);
	}
	CopyToNode(item, pnew); //���и�ֵ����
	pnew->next = NULL; //����ΪNULL��������β��
	if (QueueIsEmpty(pq)) {
		pq->front = pnew;/*��λ�ڶ����׶�*/
	}
	else {
		pq->rear->next = pnew; /*���ӵ�����β��*/
	}
	pq->rear = pnew;
	pq->items++;
}
bool DeQueue(Item* pitem, Queue* pq) { //Item��ָ��int���͵�ָ�� 
	Node* pt; //��ʱָ��
	if (QueueIsEmpty(pq)) {
		return false;
	}
	CopyToItem(pq->front, pitem);  //����������ָ������
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

/*�ֲ�����*/

static void CopyToNode(Item item, Node* pn) {
	pn->item = item;
}

static void CopyToItem(Node* pn,Item *pi) {
	*pi = pn->item;
}
