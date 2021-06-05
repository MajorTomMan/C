#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define TSIZE 45


struct film { //双向电影名称存储链表
	char title[TSIZE];
	int rating;
	struct film* next; //指向下一个结构的地址 
};


char* s_gets_list(char* str, int n) {
	char* ret_val;
	char* find;
	ret_val = fgets(str, n, stdin);
	if (ret_val) {
		find = strchr(str,'\n');
		if (find) {
			*find = '\0';
		}
		else {
			while (getchar() != '\n') {
				continue;
			}
		}
	}
	return ret_val;
}

int films(void) {
	struct film* head = NULL;
	struct film* prev, * current;
	struct film temp;
	char input[TSIZE];
	printf("Enter first movie title:");
	while (s_gets_list(input, TSIZE) != NULL&&input[0]!='\0') { //s_gets_Tree用于删除换行符 第二个条件检验是否为空字符串
		current = (struct film*)malloc(sizeof(struct film)); 
		if (head == NULL) {  //如果头指针为NULL
			head = current; //将current指针申请到的内存赋值给头指针
		}
		else {
			prev->next = current; //不为NULL则该头指针已经指向一个链表的头部
		}
		current->next = NULL; //将申请到的内存赋值完后给next指针指向NULL
		strcpy(current->title, input); //将标题字符串赋值
		printf("Enter your rating <0-10>:"); 
		scanf("%d", &current->rating); 
		while (getchar() != '\n') { //查找换行符 getchar用于读取换行符
			continue;
		}
		printf("Enter next movie title(empty line to step):");
		prev = current;//创建一个新表
	}

	/*展示链表中的数据*/
	if (head == NULL) { //无数据输入
		printf("No data entered");
	}
	else {
		printf("here is the movie list:\n");
	}
	current = head;//将头指针赋值给current指针
	while (current != NULL) {
		printf("Movie:%s Rating:%d\n",current->title,current->rating);
		current = current->next;
	}
	current = head;//重置current指针
	while (current != NULL) {
		prev = current->next;
		free(current);
		current = prev;
	}
	printf("Bye\n");
	return 0;
}

struct film_traverse { //双向电影名称存储链表
	char title[TSIZE];
	int rating;
	struct film_traverse* next; //指向下一个结构的地址 
	struct film_traverse* last; //指向上一个结构的地址 
};

int list_traverse(void) {   //双向链表
	struct film_traverse* head = NULL;
	struct film_traverse* prev, * current;
	char input[TSIZE];
	printf("Enter first movie title:");
	while (s_gets_list(input, TSIZE) != NULL && input[0] != '\0') {
		current = (struct film_traverse*)malloc(sizeof(struct film_traverse));
		current->last = NULL;
		if (head == NULL) {  //如果头指针为NULL
			head = current; //将current指针申请到的内存赋值给头指针
		}
		else {
			prev->next = current; //不为NULL则该头指针已经指向一个链表的头部
			current->last = prev; //将申请到的内存current的last存为上一个结构的地址
		}
		current->next = NULL;
		strcpy(current->title, input); //将标题字符串赋值
		printf("Enter your rating <0-10>:");
		scanf("%d", &current->rating);
		while (getchar() != '\n') { //查找换行符 getchar用于读取换行符
			continue;
		}
		printf("Enter next movie title(empty line to step):");
		prev = current;//创建一个新表 //等于把head赋值给prev 因为head指针和current指针指向同一块内存
	}
	if (head == NULL) { //无数据输入
		printf("No data entered");
	}
	else {
		printf("here is the movie list:\n");
	}
	current = head;
	while (current != NULL) {
		printf("Movie:%s Rating:%d\n", current->title, current->rating);
		current = current->next;
	}
	current = head;
	while (current->next!=NULL) {
		current=current->next;
	}
	while (current != NULL) {
		printf("Traverse:Movie:%s Rating:%d\n", current->title, current->rating);
		current = current->last;
	}
	getchar();
	return 0;
}


void array_sort(int ptr[], int length);
int half_search(int ptr[], int length, int Use_to_search);


void Test_search() { //二分查找
	int roll;
	srand((unsigned int)time(NULL));	
	int array[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		roll = rand() % 10 + 1;
		array[i] = roll;
	}
	array_sort(array, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("result is %d\n", half_search(array, 10, -1));
}

void array_sort( int ptr[],int length) {
	int temp;
	for (int i = 0; i < length-1; i++) {
		for (int j = i + 1; j < length; j++) {
			if (ptr[i] > ptr[j]) {
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}
}

int half_search(int ptr[], int length,int Use_to_search) {
	int low, high, middle;
	low = 0;
	high = length - 1;
	int i = 0;
	while (low <= high) {
		i++;
		middle = (low + high) / 2;
		if (ptr[middle] == Use_to_search) {
			printf("此时的索引为%d\n", middle);
			printf("一共循环了%d次\n", i);
			return middle;
		}
		else if (ptr[middle] < Use_to_search) {
			low = middle + 1;
		}
		else {
			high = middle - 1;
		}
	}
	printf("一共循环了%d次\n", i);
	return -1;
}