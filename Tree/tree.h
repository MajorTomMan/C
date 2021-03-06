#pragma once

#ifndef  _TREE_H_
#define _TREE_H_
#include <stdbool.h>

//根据具体情况定义Item
#define SLEN 20

typedef struct item {
	char petname[SLEN];
	char petkind[SLEN];
}Item;

#define MAXITEMS 10

typedef struct trnode {
	Item item;
	struct trnode* left;  /*指向左节点的指针*/
	struct trnode* right; /*指向右节点的指针*/
}Trnode;

typedef struct tree {
	Trnode *root; /*指向根节点的指针*/
	int size; /*树的项数*/
}Tree;


/*函数原型*/

/*操作:把树初始化为空*/
/*
	前提条件:
	ptree指向一棵树
*/
/*
	后置条件:
	树被初始化为空
*/
void InitializeTree(Tree *ptree);
/*操作:确定树是否为空*/
/*
	前提条件:
	ptree指向一棵树
*/
/*
	后置条件:
	如果树为空,该函数返回true
	否则返回false
*/
bool TreeIsEmpty(const Tree* ptree);
/*操作:确定树是否已满*/
/*
	前提条件:
	ptree指向一棵树
*/
/*
	后置条件:
	如果树已满,该函数返回true
	否则返回false
*/

bool TreeIsFull(const Tree* ptree);

/*操作:确定树的项数*/
/*
	前提条件:
	ptree指向一棵树
*/
/*
	后置条件:返回树的项数
*/
int TreeItemCount(const Tree* ptree);

/*操作:在树中添加一个项*/
/*
	前提条件:
	pi是待添加项的地址
*/
/*
	后置条件:
	如果可以添加,该函数将在树中添加一个项
	并返回true
	否则返回false
*/
bool Tree_AddItem(const Item* pi,Tree *ptree);

/*操作:在树中查找一个项*/
/*
	前提条件:
	pi指向一个项
	ptree指向一个已初始化的树
	*/
/*
	后置条件:
	如果在树中找到指定项
	返回true
	否则返回false
*/
bool InTree(const Item* pi,const Tree* ptree);
/*操作:在树中删除一个项*/
/*
	前提条件:
	pi是删除项的地址
	ptree指向一个已初始化的树
	*/
	/*
		后置条件:
		如果在树中成功删除一个项
		返回true
		否则返回false
	*/
bool DeleteItem(const Item* pi, Tree* ptree);

/*操作:把函数应用在树中的每一项*/
/*
	前提条件:
	ptree指向一个树
	pfun指向一个函数
	该函数接受一个Item类型的参数,并无返回值
	*/
	/*
		后置条件:
		pfun指向的函数为树中的每一项执行一次
	*/
void Tree_Traverse(const Tree* ptree,void(*pfun)(Item item));

/*操作:删除树中的所有内容*/
/*
	前提条件:
	ptree指向一个已初始化的树
	*/
	/*
		后置条件:
		树为空
	*/
void DeleteAll(Tree* ptree);

void Traverse_TREE(Tree* Tree_p);

#endif


