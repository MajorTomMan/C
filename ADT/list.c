#include<stdio.h>
#include "list.h"
#include <stdlib.h>
#include<stdbool.h>
/*�ֲ�����ԭ��*/
// static void CopyToNode(Item item, Node* pnode);
/*�ӿں���*/
/*����������Ϊ��*/
/*
void InitializeList(List* plist) {
	*plist = NULL;
}
*/
/*�����������,����true*/
/*
bool ListIsEmpty(const List* plist) {
	if (*plist == NULL) {
		return true;
	}
	else {
		return false;
	}
}
*/
/*�����������,����true*/
/*
bool ListIsFull(const List* plist) {
	Node* pt;
	bool full;
	pt = (Node*)malloc(sizeof(Node));
	if (pt == NULL) {
		full = true;
	}
	else {
		full = false;
	}
	free(pt);
	return full;
}
*/
/*
unsigned int ListItemCount(const List* plist) {
	unsigned  int count = 0;
	Node* pnode = *plist;
	while (pnode != NULL) {
		++count;
		pnode = pnode->next;
	}
	return count;
}
bool AddItem(Item item, List* plist) {
	Node* pnew;
	Node* scan = *plist;
	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL) {
		return false;  //ʧ���˳�����
	}
	CopyToNode(item,pnew);
	pnew->next = NULL;
	if (scan == NULL) { //������
		*plist = pnew;  //pnew��������Ŀ�ͷ
	}
	else {
		while (scan->next != NULL) {
			scan = scan->next; //�ҵ������ĩβ
		}
		scan->next=pnew; //��pnew��ӵ������ĩβ
	}
	return true;
}

void Traverse(const List* plist, void(*pfun)(Item item)) {
	Node* pnode = *plist;
	while (pnode != NULL) {
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

void EmptyTheList(List* plist) {
	Node* psave;
	while (*plist != NULL) {
		psave = (*plist)->next;
		free(*plist);
		*plist = psave;
	}
}

static void CopyToNode(Item item, Node* pnode) {
	pnode->item = item;
}
*/


/*ʹ�ò�ͬ��list����дlist.c*/
/*

static void CopyToNode(Item item, Node* pnode);

void InitializeList(List* plist) {
	plist->head = NULL;
	plist->end = NULL;
}

bool ListIsEmpty(const List* plist) {
	if (plist->head ==NULL) {
		return true;
	}
	return false;
}


bool ListIsFull(const List* plist) {
	Node *list;
	list = (Node*)malloc(sizeof(Node));
	if (list == NULL) {
		return true;
	}
	free(list);
	return false;
}
unsigned int ListItemCount(const List* plist) {
	unsigned int count=0;
	Node* list = plist->head;
	while (list != NULL) {
		count++;
		list = list->next;
	}
	return count;
}
bool AddItem(Item item, List* plist) {
	Node* pnew;
	Node *scan = plist->head;
	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL) {
		return false;
	}
	CopyToNode(item, pnew);
	pnew->next= NULL;
	if (plist->head== NULL) {
		plist->head = pnew;
	}
	else {
		while (scan->next!= NULL) {
			scan=scan->next;
		}
		scan->next= pnew;
	}
	plist->end = pnew;
	return true;
}

void Traverse(const List* plist, void(*pfun)(Item item)) {
	Node* pnode = plist->head;
	while (pnode != NULL) {
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

void EmptyTheList(List* plist) {
	Node* scan = plist->head;
	Node* temp=NULL;
	while (scan!=NULL) {
		temp = scan->next;
		free(scan);
		scan = temp;
	}
}

static void CopyToNode(Item item, Node* pnode) {
	pnode->item = item;
}
*/


static void CopyToNode(Item item, Node* pnode);

void InitializeList(List* plist) {
	plist->items=0;
}

bool ListIsEmpty(const List* plist) {
	if (plist->items ==0) {
		return true;
	}
	return false;
}


bool ListIsFull(const List* plist) {
	if (plist->items == MAXSIZE) {
		return true;
	}
	return false;
}
unsigned int ListItemCount(const List* plist) {
	return plist->items;
}
bool AddItem(Item item, List* plist) {
	static int i = 0;
	Item *ptr=plist->entries;
	*(ptr + i) = item;
	i++;
	plist->items++;
	return true;
}

void Traverse(const List* plist, void(*pfun)(Item item)) {
	int i = 0;
	Item *ptr=plist->entries;
	while (i!=plist->items) {
		(*pfun)(*(ptr+i));
		i++;
	}
}

void EmptyTheList(List* plist) {
	;
}

static void CopyToNode(Item item, Node* pnode) {
	pnode->item = item;
}