#include<stdio.h>

int char_comfirm_classwork1(void) {
	char ch=' ';
	int end=0;
	printf("������һ�λ�(-1Ϊ�˳�):");
	while (ch!=EOF) {
		ch = getchar();
		putchar(ch);
	}
	return 0;
}