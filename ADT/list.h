#pragma once

#ifndef LIST_H_
#define LIST_H_
#include<stdbool.h>

#define TSIZE 45
#define MAXSIZE 100
struct films {
	char title[TSIZE];
	int rating;
};
typedef struct films Item;

typedef struct node {
	Item item;
	struct node* next;
}Node;
/*
typedef Node* List;
*/
/*
typedef struct list {
	Node* head;
	Node* end;
}List;
*/

typedef struct list {
	Item entries[MAXSIZE];
	int items;
}List;

/*����ԭ��*/
/*����:��ʼ��һ������*/
/*ǰ������:plistָ��һ������*/
/*��������:�����ʼ��Ϊ��*/
void InitializeList(List* plist);

/*����:ȷ�������Ƿ��ǿն���,plistָ��һ���ѳ�ʼ��������*/
/*��������:�������Ϊ��,�ú�������true,���򷵻�false*/
bool ListIsEmpty(const List* plist);
/*����:ȷ�������Ƿ�����,plistָ��һ���ѳ�ʼ��������*/
/*��������:�������Ϊ��,�ú�������true,���򷵻�false*/
bool ListIsFull(const List* plist);
/*����:ȷ�������е�����,plistָ��һ���ѳ�ʼ��������*/
/*��������:�ú������������е�����*/
unsigned int ListItemCount(const List* plist);
/*����:�������ĩβ�����*/
/*ǰ������:item��һ����������������,plistָ��һ���ѳ�ʼ��������*/
/*��������:�������,�ú���������ĩβ���һ����,�ҷ���true,���򷵻�false*/
bool AddItem(Item item, List* plist);
/*����:�Ѻ��������������е�ÿһ��*/
/*ǰ������:*/
/*plistָ��һ���ѳ�ʼ��������*/
/*pfunָ��һ������,�ú�������һ��Item���͵Ĳ���,���޷���ֵ*/
/*��������:pfunָ��ĺ��������������е�ÿһ��һ��*/
void Traverse(const List* plist, void(*pfun)(Item item));
/*����:�ͷ��ѷ�����ڴ�(����еĻ�)*/
/*ǰ������:*/
/*plistָ��һ���ѳ�ʼ��������*/
/*��������:�ͷ���Ϊ�������������ڴ�,��������Ϊ��*/
void EmptyTheList(List* plist);

#endif
