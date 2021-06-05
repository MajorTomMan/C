#include <stdio.h>
#include "Stack.h"
#include "stdio.h"
int Stack_u(void) {
	Stack* stack=(Stack*)malloc(sizeof(Stack));
	Goods temp;
	char ch;
	InitializeStack(stack);
	puts("Testing the Stack interface.Type a to add a value,");
	puts("type d to detele a value,and type q to quit.");
	while ((ch = getchar()) != 'q') {
		if (ch != 'a' && ch != 'd') { /*忽略其他输出*/
			continue;
		}
		if (ch == 'a') {
			printf("Interger  Goods to Stack:\n");
			printf("Interger Goods Name:");
			scanf("%s", &temp.goods_name);
			printf("Interger Goods value:");
			scanf("%d", &temp.value);
			if (!StackIsFull(stack)) {
				printf("Putting Name:%s value:%d into Goods\n", temp.goods_name, temp.value);
				Push(&temp, stack);
			}
			else {
				puts("Queue is Full!");
			}
		}
		else {
			if (StackIsEmpty(stack)) {
				puts("Nothing to delete!");
			}
			else {
				Pop(&temp,stack);
				printf("Removing Name:%s value:%d from Stack.\n",temp.goods_name,temp.value); //栈顶弹出的元素;
			}
		}
		printf("%d items in Stack\n", StackGoodsCount(stack));
		puts("Type a to add,d to delete,q to quit;");
	}
	StackAllClear(stack);
	puts("Bye!");
	return 0;
}