#include <stdio.h>
#define Size 46

int recycle_classwork1(void) {
	int ch[Size] = {0};
	int i=0;
	printf("输入数字进数组存储(按Q退出):");
	while (scanf("%d",&ch[i])==1) {
		i++;
		if (i == Size) {
			fflush(stdin);
			break;
		}
	}
	i =0;
	while (i != Size) {
		printf("输入%d\n", ch[i]);
		i++;
	}
	i = 0;
	return 0;
}

int recycle_classwork2(void) {
	char ch[Size] = { " " };
	for (int i = 1; i <=Size-1; i++) {
		for (int j = i-1; j <= i-1; j++) {
			ch[j]='$';
			printf("输出:%s\n", &ch);
		}
	}
	return 0;
}

int recycle_classwork3(void) {
	char ch[Size] = { 'F'};
	for (int i = 1; i <=('F'-'A');i++) {
		ch[i] = 'F' - i;
		printf("输出:%s\n", &ch);
	}
	return 0;
}
/*
int recycle_classwork4(void) {
	char ch[Size] = { 'A' };
	for (int i = 1; i <=('Z'-'A'); i++) {
		for(int j=i-1;j<=i;j++){
			ch[j] = 'A'+j;
			ch[i] = 'A'+i;
			printf("输出:%s\n", &ch);
		}
	}
	return 0;
}
*/
/*
	思路:用两个嵌套循环来控制输出,外层是控制行数,内层是用于控制输出长度
		     用一个字符变量来控制输出内容
*/
int recycle_classwork4(void) {
	char ch = 'A';
	for (int i = 0; i <= 6; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%c", ch++);
		}
		printf("\n");
	}
	return 0;
}

/*
	思路:外层循环用来控制行数,第一个循环用于控制空格次数,次数要点在于随着行数即i的增大而减小
			 第二个循环用来控制正序,要点在于停止条件第一次不进入循环,
			 输出要点在于被赋予字符A的变量需要随着循环的局部变量而增加,
			 第三个循环用于控制倒序输出,停止条件要点同二,
			 输出要点在于输出时用外层行数来控制倒序输出,每次减1
*/
int recycle_classwork5(void) {
	char input = ' ';
	char asi = 'A';
	printf("请输入一个大写字母:");
	scanf("%c", &input);
	int length = input - 'A';
	for (int i = 0; i <= length; i++) {
		for (int j = 0; j <= length - i; j++) {
			printf(" ");
		}
		for (int j = 0; j <= i; j++) {
			printf("%c", asi + j);
		}
		for (int j = 1; j <= i; j++) {
			printf("%c", asi + i - j);
		}
		printf("\n");
	}
	return 0;
}

int recycle_classwork6(void) {
	char ch = "";
	int topline, bottomline;
	int basenumber,square,cube;
	printf("请输入表格上限和下限 (用空格分隔):");
	scanf("%d %d", &topline, &bottomline);
	printf("基本数 平方 立方\n");
	for (int i = topline; i <= bottomline; i++) {
		basenumber=i;
		square = basenumber*basenumber;
		cube = basenumber*basenumber*basenumber;
		printf("%-5d  %-5d  %d\n",i ,square,cube);
	}
}

int recycle_classwork7(void) {
	char ch_1=' ';
	char ch[Size] = "" ;
	printf("请输入一个单词:");
	scanf("%s", ch);
	for (int i = strlen(ch)-1; i>=0; i--) {
		ch_1 = ch[i];
		printf("%c",ch_1 );
	}
	printf("\n");
	return 0;
}

int recycle_classwork8(void) {
	float testnum1=0.0, testnum2=0.0;
	printf("请输入两个浮点数:");
	while (scanf("%f %f", &testnum1, &testnum2)) {
		printf("结果为:%f\n", ((testnum1 - testnum2) / (testnum1 * testnum2)));
	}
	return 0;
}
int recycle_classwork9(void) {
	recycle_classwork8_func();
}

int recycle_classwork8_func(void) {
	float testnum1 = 0.0, testnum2 = 0.0;
	printf("请输入两个浮点数:");
	while (scanf("%f %f", &testnum1, &testnum2)) {
		printf("结果为:%f\n", ((testnum1 - testnum2) / (testnum1 * testnum2)));
	}
	return 0;
}
int recycle_classwork10(void) {
	int top=0, bottom=1,square,sums=0;
	while (1) {
		printf("请输入两个整数:");
		scanf("%d %d", &top, &bottom);
		if (top>=bottom) {
			break;
		}
		for (int i = top; i <= bottom; i++) {
			square = i * i;
			sums+=square;
		}
		printf("结果为:%d\n", sums);
		sums = 0;
	}
	printf("程序结束\n");
	return 0;
}

int recycle_classwork11(void) {
	int array_int[8] = { 0 };
	int i = 0;
	for (printf("请输入8个整数:"); i != 8; i++) {
		scanf("%d", &array_int[i]);
	}
	for (int j = 7; j>= 0; j--) {
		printf("输出:%d\n", array_int[j]);
	}
}

int recycle_classwork12(void) {
	;
}

int recycle_classwork13(void) {
	int i = 0,j=0,results=1;
	int array_int[9] = {0};

	for (; j != 9; j++) {
		results *= 2;
		array_int[j] = results;
	}
	do {
		printf("%d ", array_int[i]);
		i++;
	} while (i != 9);
	printf("\n");
}

int recycle_classwork14(void) {
	double db_1[8] = { 0.0 };
	double db_2[8] = { 0.0 };
	double sum = 0.0;
	printf("请输入8个小数:");
	for (int i = 0; i != 8; i++) {
		scanf("%lf", &db_1[i]);
	}
	for (int j = 0; j != 8; j++) {
		for (int i = 0; i <=j; i++) {
			sum += db_1[i];
		}
		db_2[j] = sum;
		sum = 0.0;
	}
	for (int i = 0; i != 8; i++) {
		printf("%f ", db_1[i]);
	}
	printf("\n");
	for (int i = 0; i != 8; i++) {
		printf("%f ", db_2[i]);
	}
	printf("\n");
	return 0;
}

int recycle_classwork15(void) {
	char ch_1[Size] = { "" };
	for (int i = 0; i <= 7; i++) {
		scanf("%c", &ch_1[i]);
	}
	for (int i = strlen(ch_1)-1; i!=0; i--) {
		printf("%c", ch_1[i]);
	}
	printf("\n");
}//Unfinished

int recycle_classwork16(void) {
	float cost_Daphne = 0.1, cost_Deirdre = 0.05;
	float capital_Daphne = 100, capital_Deirdre = 100;
	int years = 1;
	float cost_Da = 0, cost_De = 0;
	float count_Da = 0, count_De = 0;
	_Bool result;
	while (1) {
		cost_Da = cost_Daphne * capital_Daphne;
		count_Da = cost_Da + capital_Daphne;
		cost_De = cost_Deirdre * capital_Deirdre;
		count_De = cost_De + capital_Deirdre;
		capital_Deirdre = count_De;
		years += 1;
		result = count_Da >= count_De;
		if (result) {
			;
		}
		else {
			printf("姓名    投资额   经过年数\n");
			printf("Daphne: %5f %5d\n", count_Da, years);
			printf("Deirdre: %5f %5d\n", count_De, years);
			break;
		}
	}
}

int recycle_classwork17(void) {
	float total=100;
	float percent = 0.08;
	float minius=10;
	float fet;
	int years = 1;
	while (1) {
		fet = total * percent;
		total = total + fet;
		total -= minius;
		years += 1;
		if (total <= 0) {
			break;
		}
	}
	printf("取完花了%d年\n", years);
}

int recycle_classwork18(void) {
	int friendsnum = 5;
	for (int i = 1;; i++) {
		friendsnum -= i;
		friendsnum *= 2;
		printf("every week mr.rabnud doc friendsnum is:%d\n", friendsnum);
		if (friendsnum >= 150) {
			break;
		}
	}
}