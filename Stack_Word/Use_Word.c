#pragma once
#include <stdio.h>
#include "Stack_Word.h"


int Stack_Word(void) {
	Stack line;
	Node *temp;
	char *input=" ";
	char GetDelete=' ';
	char ch;
	int i = 0;
	InitializeStack_Words(&line);
	puts("Testing the Queue interface.Type a to add a value,");
	puts("type d to detele a value,and type q to quit.");
	while ((ch = getchar()) != 'q') {
		if (ch != 'a' && ch != 'd') { /*忽略其他输出*/
			continue;
		}
		if (ch == 'a') {
			while (getchar() != '\n') {
				continue;
			}
			printf("Interger  Words to Stack:\n");
			printf("Interger Words:");
			gets_s(input,MAXSIZE);
			if (!Stack_Words_IsFull(&line)) {
				printf("Putting Word:%s into Stack\n", input);
				while (*input != '\0') {
					EnStack_Words(input, &line); //读取单个字符
					input++;
				}
			}
			else {
				puts("Stack is Full!");
			}
		}
		else {
			if (Stack_Words_IsEmpty(&line)) {
				puts("Nothing to delete!");
			}
			else {
				GetDelete=DeStack_Words(GetDelete, &line);
				printf("Removing Word:%c from Stack.\n", GetDelete); //被DeQueue中的pitem所赋值;
			}
		}
		printf("%d items in Stack\n", Stack_WordsCount(&line));
		puts("Type a to add,d to delete,q to quit;");
	}
	Stack_Words_AllClear(&line);
	puts("Bye!");
	return 0;
}