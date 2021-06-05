#include <stdio.h>
#define FORMAT "%s! C is cool!\n"
#define Hundred_n_twentieth_two  122
#define Seconds 60
#define Week 7
#define Inches 2.54 
int test3(void) {
	int num = 10;
	printf(FORMAT, FORMAT);
	printf("%d\n",++num); // 11 前缀模式,先递增再显示
	printf("%d\n", num++);//11 后缀模式,先显示再递增
	printf("%d\n", num--);  //12 后缀模式,先显示再递增
	printf("%d\n", num); //11 后缀模式, 先显示再递增
	return 0;
}

int test4(void) {
	char ch = 'a';
	while (ch++< Hundred_n_twentieth_two) {
		printf("%5c\n", ch);
	}
	return 0;
}

int test5(void) {
	int x, a, b, c,n,k,m,q,p,d;
	x = a = b = c = n = k = m = q = p = d=0;
	x = 10;
	x = x + 1;
	c = (a + b) * 2;
	c = (a * 2) + (b * 2);
	//-----------------------------------
	x = x - 1;
	m = n/k;
	p = q / b - a;
	x = (a + b) / (c * d);
}

double cubic(double sqrt) {
	double num=0;
	num = sqrt * sqrt*sqrt;
	return num;
}

int intergral_classwork1(void) {
	int hours = Seconds * Seconds, input=1,hour,minute,second;
	while (input>0) {
		printf("hi,让我们看看你输入的时间对应着多少时间刻度\n在这里输入数字(如果输入0或者小于0的数则会退出):");
		scanf("%d", &input);
		hour = input / hours;
		minute = (input - (hour*hours))/Seconds;
		second = (input - ((hour * hours) + minute * Seconds)) % Seconds;
		printf("你输入的小时是%d,分钟是%d,秒是%d\n",hour,minute,second);
	}
	return 0;
}

int intergral_classwork2(void) {
	int num=0,num1=0;
	printf("hi,让我们看看比你输入的整数大10的有多少\n在这里输入数字:");
	scanf("%d", &num);
	num1 = num + 10;
	while (num<=num1) {
		printf("输出:%d\n", num);
		num++;
	}
	return 0;
}

int intergral_classwork3(void) {
	int days=1,weekday,day;
	while (days > 0) {
		printf("hi,让我们看看你输入的天数有多少\n在这里输入数字:");
		scanf("%d", &days);
		weekday = days / Week;
		day = (days - (weekday * Week)) % Week;
		printf("%d天有%d周和%d天\n", days, weekday, day);
	}
	return 0;
}

int intergral_classwork4(void) {
	float input = 0.0;
	float inch;
	while (input >= 0) {
		printf("hi,让我们看看你身高换算成英寸有多高呢\n在这里输入数字(输入负数即可退出):");
		scanf("%f", &input);
		inch = input / Inches;
		printf("%f厘米有%f英寸\n",input,inch);
	}
	return 0;
}

int intergral_classwork5(void) {
	int count=0,input=0,days=0;
	printf("hi,让我们看看你到输入的日期能赚多少钱呢\n在这里输入日期:");
	scanf("%d", &input);
	while (days<input) {
		count++;
		days++;
		printf("第%d天,共有%d人民币\n",days,count);
	}
	return 0;
}

int intergral_classwork6(void) {
	int count=0, input = 0, days = 0,sqrt=0;
	printf("hi,让我们看看你到输入的日期能赚多少钱呢\n在这里输入日期:");
	scanf("%d", &input);
	while (days < input) {
		count++;
		sqrt = count * count;
		days++;
		printf("第%d天,共有%d人民币\n", days, sqrt);
	}
	return 0;
}

int intergral_classwork7(double sqrt) {
	double output=0;
	output=cubic(sqrt);
	printf("立方是:%f\n", output);
	return 0;
}

int intergral_classwork8(void) {
	int input,num;
	const int staticnum;
	printf("hi,让我们看看两个整数的求余运算结果 吧\n在这里输入第一个整数:");
	scanf("%d", &input);
	printf("在这里输入第二个整数:");
	scanf("%d", &staticnum);
	num = input % staticnum;
	printf("%d和%d的求余结果是:%d\n",input,staticnum,num);
	printf("现在我们只需要输入一个整数就好了(想退出的时候输入负数)\n");
	while (input >=0) {
		printf("输入整数:");
		scanf("%d", &input);
		num = input % staticnum;
		printf("%d和%d的求余结果是:%d\n", input, staticnum, num);
	}
	return 0;
}


