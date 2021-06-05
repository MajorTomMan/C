#include<stdlib.h>
#include "Stack_Word.h"

static void CopyToNode(char *words, Node* pnew);

void InitializeStack_Words(Stack* pstack) {
	pstack->front =NULL;
	pstack->n_words= 0;
}

bool Stack_Words_IsEmpty(Stack* pstack) {
	return pstack->n_words == 0;
}

bool Stack_Words_IsFull(Stack* pstack) {
	return pstack->n_words == 10;
}

int Stack_WordsCount(Stack* pstack) {
	return pstack->n_words;
}

bool EnStack_Words(char *words, Stack* pstack) {
	Node* pnew;
	Node* ptr = pstack->front;
	pnew = (Node*)malloc(sizeof(Node));
	if (Stack_Words_IsFull(pstack)) {
		return false;
	}
	if (pnew == NULL) {
		fprintf(stderr, "Unable to allocate memory!\n");
		exit(1);
	}
	CopyToNode(words, pnew);
	pnew->next = NULL;
	if (Stack_Words_IsEmpty(pstack)) {
		pstack->front = pnew;
	}
	else {
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = pnew;
	}
	pstack->n_words++;
	words++;
	return true;
}


char DeStack_Words(char words, Stack* pstack) {
	Node* temp = pstack->front;
	Node* ptr, * pnew;
	ptr = (Node*)malloc(sizeof(Node));
	pnew = (Node*)malloc(sizeof(Node));
	if (ptr == NULL || pnew == NULL) {
		return false;
	}
	if (Stack_Words_IsEmpty(pstack)) {
		return false;
	}
	while (temp->next != NULL) { //查找栈中在最后的数据
		ptr = temp;
		temp = temp->next;
	}
	words = temp->words;
	*pnew = *temp;
	free(pnew); //释放该数据的内存
	ptr->next = NULL;
	pstack->n_words--;
	pnew = NULL;
	return words;
}


void Stack_Words_AllClear(Stack* pstack) {
	Node* pnew = pstack->front;
	Node* ptr;
	while (pnew != NULL) {
		ptr = pnew->next;
		free(pnew);
		pnew = ptr;
	}
}





static void CopyToNode(char *words, Node* pnew) {
	pnew->words = *words;
}