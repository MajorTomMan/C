#include "tree.h"
#include<stdio.h>
#include <string.h>
#include<stdlib.h>



typedef struct stack_tree {
	Trnode* Data;
	struct stack_tree* next;
}Stack_tree;
typedef struct stack {
	Stack_tree *Head;
}Stack;

typedef struct status {
	int status;
	struct status* next;
}Status;


typedef struct pair {
	Trnode* parent;
	Trnode* child;
}Pair;

static Trnode* MakeNode(const Item *pi);
static void AddNode(Trnode* new_node, Trnode* root);
static bool ToLeft(const Item* i1, const Item* i2);
static bool ToRight(const Item* i1, const Item* i2);
static Pair SeekItem(const Item* pi, const Tree* ptree);
bool InTree(const Item* pi, const Tree* ptree);
static void InOrder(const Trnode* root, void (*pfun)(Item item));
static void DeleteAllNodes(Trnode* root);
static void DeleteNode(Trnode** ptr);


void InitializeTree(Tree* ptree) {
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree* ptree) {
	if (ptree->root != NULL) {
		return false;
	}
	return true;
}

bool TreeIsFull(const Tree* ptree) {
	if (ptree->size!=MAXITEMS) {
		return false;
	}
	return true;
}

int TreeItemCount(const Tree* ptree){
	return ptree->size;
}

bool Tree_AddItem(const Item* pi, Tree* ptree){
	Trnode* new_node;
	if (TreeIsFull(ptree)) {
		fprintf(stderr, "Tree is Full\n");
		return false; /*提前返回*/
	}
	if (SeekItem(pi, ptree).child != NULL) {
		fprintf(stderr, "Attempted to add duplicate item\n");
		return false;/*提前返回*/
	}
	new_node = MakeNode(pi); /*指向新节点*/
	if (new_node == NULL) { 
		fprintf(stderr, "Couldn't create node\n");
		return false;/*提前返回*/
	}
	ptree->size++;
	if (ptree->root == NULL) { /*情况1:树为空*/
		ptree->root = new_node; /*新节点是根节点*/
	}
	else {
		AddNode(new_node, ptree->root);/*在树中添加一个新节点*/
	}
	return true; /*成功返回*/
}

static Trnode* MakeNode(const Item* pi) {
	Trnode* new_node;
	new_node = (Trnode*)malloc(sizeof(Trnode));
	if (new_node != NULL) {
		new_node->item = *pi;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;
}

static void AddNode(Trnode* new_node, Trnode* root) {
	if (ToLeft(&new_node->item, &root->item)) {
		if (root->left == NULL) {/*空子树*/
			root->left = new_node; /*所以添加节点*/
		}
		else {
			AddNode(new_node, root->left);/*否则,处理该子树*/
		}
	 }
	else if(ToRight(&new_node->item, &root->item)){
		if (root->right == NULL) {
			root->right= new_node;
		}
		else {
			AddNode(new_node, root->right);
		}
	}
	else {/*不应含有重复项*/
		fprintf(stderr, "location error in AddNode()\n");
		exit(1);
	}
}

static bool ToLeft(const Item* i1, const Item *i2) {//若i1>i2返回正数,若i1<i2返回负数,相等返回0
	int comp1;
	if ((comp1 = strcmp(i1->petname, i2->petname)) < 0) {
		return true;
	}
	else if(comp1==0&&strcmp(i1->petkind, i2->petkind)<0){
		return true;
	}
	else {
		return false;
	}
}

static bool ToRight(const Item* i1, const Item* i2) {
	int comp1;
	if ((comp1 = strcmp(i1->petname, i2->petname)) > 0) {
		return true;
	}
	else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) > 0) {
		return true;
	}
	else {
		return false;
	}
}


static Pair SeekItem(const Item* pi, const Tree* ptree) {
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;
	if (look.child == NULL) {
		return look;
	}
	while (look.child != NULL) {
		if (ToLeft(pi, &(look.child->item))) {
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, &(look.child->item))) {
			look.parent = look.child;
			look.child = look.child->right;
		}
		else {
			break;
		}
	}
	return look;
}


bool InTree(const Item* pi, const Tree* ptree) {
	return (SeekItem(pi, ptree).child == NULL) ? false:true;
}

bool DeleteItem(const Item* pi, Tree* ptree) {
	Pair look;
	look = SeekItem(pi, ptree);
	if (look.child == NULL) {
		return false;
	}
	if (look.parent == NULL) {
		DeleteNode(&ptree->root);
	}
	else if (look.parent->left == look.child) {
		DeleteNode(&look.parent->left);
	}
	else{
		DeleteNode(&look.parent->right);
	}
	ptree->size--;
	return true;
}

void Tree_Traverse(const Tree* ptree, void (*pfun)(Item item)) {
	if (ptree != NULL) {
		InOrder(ptree->root, pfun);
	}
}

void DeleteAll(Tree* ptree) {
	if (ptree != NULL) {
		DeleteAllNodes(ptree->root);
	}
	ptree->root = NULL;
	ptree->size = 0;
}

static void InOrder(const Trnode* root, void (*pfun)(Item item)) {
	if (root != NULL) {
		InOrder(root->left, pfun);
		(*pfun)(root->item);
		InOrder(root->right, pfun);
	}
}

static void DeleteAllNodes(Trnode* root) {
	Trnode* pright;
	if (root !=NULL) {
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}


static void DeleteNode(Trnode** ptr) {
	Trnode* temp;
	if ((*ptr)->left == NULL) {
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if ((*ptr)->left == NULL) {
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
	else {
		for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right) {
			continue;
		}
		temp->right = (*ptr)->right;
		temp= *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}


void push_stack(Trnode* Node, Stack* stack) {
	Trnode* Temp;
	Stack_tree* Temp_s;
	Temp = (Trnode*)malloc(sizeof(Trnode));
	Temp_s = (Stack_tree*)malloc(sizeof(Stack_tree));
	if (Temp != NULL) {
		*Temp = *Node;
	}
	else {
		printf("申请内存失败");
		return;
	}
	if (Temp_s != NULL) {
		Temp_s->Data = Temp;
		Temp_s->next = NULL;
	}
	else {
		printf("申请内存失败");
	}
	if (stack->Head == NULL) {
		stack->Head = Temp_s;
	}
	else {
		while (stack->Head->next != NULL) {
			stack->Head = stack->Head->next;
		}
		stack->Head->next = Temp_s;
	}
}

void Traverse_TREE(Tree* Tree_p) {
	Trnode* Trnode_p=Tree_p->root;
	Stack *stack;
	Status *status;
	Stack_tree stack_tree;
	stack = (Stack*)malloc(sizeof(Stack));
	stack->Head = NULL;
	stack->Head=Trnode_p;
	while (Trnode_p != NULL) {
		push_stack(Trnode_p, stack);
		Trnode_p = Tree_p->root->left;
	}
}
