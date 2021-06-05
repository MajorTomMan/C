#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int critic(int units) {
	printf("no luck,my friend try again:");
	scanf("%d", &units);
	return units;
}

int global(void) {
	int units;
	printf("how many pounds to a firkin of butter?\n");
	scanf("%d", &units);
	while (critic(units)!= 56) {
	}
	printf("you must have looked it up\n");
	return 0;
}

int memory_classwork_1(void) {
	global();
}


int call_n_return(void) {
	static int i = 0;
	i++;
	return i;
}

int memory_classwork_4(void) {
	int num;
	printf("请输入要调用的次数:");
	scanf("%d", &num);
	while (num--) {
		printf("第%d次调用\n", call_n_return());
	}
}

int random_n_sort(int(* ptr1)[10],int n) {
	int roll=0;
	int temp=0;
	int i, j,k;
	i = j = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			roll = rand() % n + 1;
			*(*(ptr1 + i) + j) = roll;
		}
	}
	printf("原来的数组数据为:\n");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", *(*(ptr1+ i) + j));
		}
		printf("\n");
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j <10; j++) {
			for (k = j + 1; k < 10; k++) {
				if (*(*(ptr1 + i) + j)< *(*(ptr1 + i) + k)) {
					temp = *(*(ptr1 + i) + j);
					*(*(ptr1 + i) + j) = *(*(ptr1 + i) + k);
					*(*(ptr1 + i) + k) = temp;
				}
			}
		}
	}
	printf("排序后的数组数据为:\n");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", *(*(ptr1 + i) + j));
		}
		printf("\n");
	}
}

int memory_classwork_5(void) {
	int(* ptr)[10];
	int num[10][10] = {0};
	ptr = num;
	random_n_sort(ptr, 10);
}

int random_n(void) {
	int count_1, count_2,count_3,count_4,count_5,count_6,count_7,count_8,count_9,count_10;
	count_1= count_2= count_3= count_4= count_5= count_6= count_7= count_8= count_9= count_10=0;
	int n=0;
	int roll=0;
	while (n != 1000) {
		srand((unsigned int)time(NULL));
		roll = rand() % 10 + 1;
		switch (roll) {
		case 1:count_1++; break;
		case 2:count_2++; break;
		case 3:count_3++; break;
		case 4:count_4++; break;
		case 5:count_5++; break;
		case 6:count_6++; break;
		case 7:count_7++; break;
		case 8:count_8++; break;
		case 9:count_9++; break;
		case 10:count_10++; break;
		}
		n++;
	}
	printf("1出现了%d次\n2出现了%d次\n3出现了%d次\n4出现了%d次\n"
			"5出现了%d次\n6出现了%d次\n7出现了%d次\n8出现了%d次\n"
			"9出现了%d次\n10出现了%d次\n",count_1, count_2, count_3, count_4, count_5, count_6, count_7, count_8, count_9, count_10);
}

int memory_classwork_6(void) {
	random_n();
}

int show_array(const int ar[], int n) {
	const int* ptr;
	ptr = ar;
	for (int i = 0; i < n; i++) {
		printf("%d ", *ptr++);
		if (i == 8) {
			printf("\n");
		}
	}
	printf("\n");
}

int* make_array(int item, int val) {
	int* pt=(int *)malloc(item*sizeof(int));
	int* ptr = pt;
	for (int i = 0; i < item; i++) {
		*pt = val;
		pt++;
	}
	return ptr ;
}

int pe12_8(void) {
	int* pa;
	int size;
	int value;
	printf("Enter the number of element:");
	while (scanf("%d", &size) == 1 && size > 0) {
		printf("Enter the initialization value:");
		scanf("%d", &value);
		pa = make_array(size, value);
		if (pa) {
			show_array(pa, size);
			free(pa);
		}
		printf("Enter the number of elements(<1 to quit):");
	}
	printf("Done.\n");
}


int memory_classwork_7(void) {
	pe12_8();
}
