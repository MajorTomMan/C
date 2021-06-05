#include<stdlib.h>
#include "Stack.h"

static void CopyToNode(Goods* goods, Node* pnew);

void InitializeStack(Stack* stack) {
	stack->size = 0;
	stack->top = NULL;
}

bool StackIsEmpty(Stack* stack) {
	if (stack->top == NULL) {
		return true;
	}
	return false;
}

bool StackIsFull(Stack* stack) {
	if (stack->size == 10) {
		return true;
	}
	return false;
}

int StackGoodsCount(Stack* stack) {
	return stack->size;
}

bool Push(Goods* goods,Stack* stack) {
	Node* pnew = (Node*)malloc(sizeof(Node));
	CopyToNode(goods, pnew);
	if (StackIsEmpty(stack)) {
		stack->top = pnew;
		stack->size++;
		return true;
	}
	pnew->next = stack->top;
	stack->top = pnew;
	stack->size++;
	return true;
}



bool Pop(Goods *goods,Stack* stack) {
	Node* temp;
	*goods = stack->top->goods;
	temp = stack->top;
	stack->top = stack->top->next;
	free(temp);
	stack->size--;
	temp = NULL;
	return true;
}


void StackAllClear(Stack* stack) {
	Goods* goods = (Goods*)malloc(sizeof(Goods));
	while (!StackIsEmpty(stack)) {
		Pop(goods,stack);
		printf("Removing Name:%s value:%d from Stack.\n", goods->goods_name, goods->value);
	}
}



static void CopyToNode(Goods* goods, Node* pnew) {
	pnew->goods = (*goods);
	pnew->next = NULL;
}