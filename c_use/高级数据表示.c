#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define TSIZE 45


struct film { //˫���Ӱ���ƴ洢����
	char title[TSIZE];
	int rating;
	struct film* next; //ָ����һ���ṹ�ĵ�ַ 
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
	while (s_gets_list(input, TSIZE) != NULL&&input[0]!='\0') { //s_gets_Tree����ɾ�����з� �ڶ������������Ƿ�Ϊ���ַ���
		current = (struct film*)malloc(sizeof(struct film)); 
		if (head == NULL) {  //���ͷָ��ΪNULL
			head = current; //��currentָ�����뵽���ڴ渳ֵ��ͷָ��
		}
		else {
			prev->next = current; //��ΪNULL���ͷָ���Ѿ�ָ��һ�������ͷ��
		}
		current->next = NULL; //�����뵽���ڴ渳ֵ����nextָ��ָ��NULL
		strcpy(current->title, input); //�������ַ�����ֵ
		printf("Enter your rating <0-10>:"); 
		scanf("%d", &current->rating); 
		while (getchar() != '\n') { //���һ��з� getchar���ڶ�ȡ���з�
			continue;
		}
		printf("Enter next movie title(empty line to step):");
		prev = current;//����һ���±�
	}

	/*չʾ�����е�����*/
	if (head == NULL) { //����������
		printf("No data entered");
	}
	else {
		printf("here is the movie list:\n");
	}
	current = head;//��ͷָ�븳ֵ��currentָ��
	while (current != NULL) {
		printf("Movie:%s Rating:%d\n",current->title,current->rating);
		current = current->next;
	}
	current = head;//����currentָ��
	while (current != NULL) {
		prev = current->next;
		free(current);
		current = prev;
	}
	printf("Bye\n");
	return 0;
}

struct film_traverse { //˫���Ӱ���ƴ洢����
	char title[TSIZE];
	int rating;
	struct film_traverse* next; //ָ����һ���ṹ�ĵ�ַ 
	struct film_traverse* last; //ָ����һ���ṹ�ĵ�ַ 
};

int list_traverse(void) {   //˫������
	struct film_traverse* head = NULL;
	struct film_traverse* prev, * current;
	char input[TSIZE];
	printf("Enter first movie title:");
	while (s_gets_list(input, TSIZE) != NULL && input[0] != '\0') {
		current = (struct film_traverse*)malloc(sizeof(struct film_traverse));
		current->last = NULL;
		if (head == NULL) {  //���ͷָ��ΪNULL
			head = current; //��currentָ�����뵽���ڴ渳ֵ��ͷָ��
		}
		else {
			prev->next = current; //��ΪNULL���ͷָ���Ѿ�ָ��һ�������ͷ��
			current->last = prev; //�����뵽���ڴ�current��last��Ϊ��һ���ṹ�ĵ�ַ
		}
		current->next = NULL;
		strcpy(current->title, input); //�������ַ�����ֵ
		printf("Enter your rating <0-10>:");
		scanf("%d", &current->rating);
		while (getchar() != '\n') { //���һ��з� getchar���ڶ�ȡ���з�
			continue;
		}
		printf("Enter next movie title(empty line to step):");
		prev = current;//����һ���±� //���ڰ�head��ֵ��prev ��Ϊheadָ���currentָ��ָ��ͬһ���ڴ�
	}
	if (head == NULL) { //����������
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


void Test_search() { //���ֲ���
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
			printf("��ʱ������Ϊ%d\n", middle);
			printf("һ��ѭ����%d��\n", i);
			return middle;
		}
		else if (ptr[middle] < Use_to_search) {
			low = middle + 1;
		}
		else {
			high = middle - 1;
		}
	}
	printf("һ��ѭ����%d��\n", i);
	return -1;
}