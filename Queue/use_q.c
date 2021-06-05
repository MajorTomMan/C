#include <stdio.h>
#include "queue.h"

int queue(void) {
	Queue line;
	Item temp;
	char ch;
	InitializeQueue(&line);
	puts("Testing the Queue interface.Type a to add a value,");
	puts("type d to detele a value,and type q to quit.");
	while ((ch = getchar()) != 'q') {
		if (ch != 'a' && ch != 'd') { /*忽略其他输出*/
			continue;
		}
		if (ch == 'a') {
			printf("Interger to add:");
			scanf("%d", &temp); 
			if (!QueueIsFull(&line)) {
				printf("Putting %d into Queue\n", temp);
				EnQueue(temp, &line);
			}
			else {
				puts("Queue is Full!");
			}
		}
		else {
			if (QueueIsEmpty(&line)) {
				puts("Nothing to delete!");
			}
			else {
				DeQueue(&temp, &line);
				printf("Removing %d from queue.\n", temp); //被DeQueue中的pitem所赋值;
			}
		}
		printf("%d items in queue\n", QueueItemCount(&line));
		puts("Type a to add,d to delete,q to quit;");
	}
	EmptyTheQueue(&line);
	puts("Bye!");
	return 0;
}