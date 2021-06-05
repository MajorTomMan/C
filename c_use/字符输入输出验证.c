#include<stdio.h>

int char_comfirm_classwork1(void) {
	char ch=' ';
	int end=0;
	printf("请输入一段话(-1为退出):");
	while (ch!=EOF) {
		ch = getchar();
		putchar(ch);
	}
	return 0;
}