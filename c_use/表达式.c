#include <stdio.h>
#define FORMAT "%s! C is cool!\n"
#define Hundred_n_twentieth_two  122
#define Seconds 60
#define Week 7
#define Inches 2.54 
int test3(void) {
	int num = 10;
	printf(FORMAT, FORMAT);
	printf("%d\n",++num); // 11 ǰ׺ģʽ,�ȵ�������ʾ
	printf("%d\n", num++);//11 ��׺ģʽ,����ʾ�ٵ���
	printf("%d\n", num--);  //12 ��׺ģʽ,����ʾ�ٵ���
	printf("%d\n", num); //11 ��׺ģʽ, ����ʾ�ٵ���
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
		printf("hi,�����ǿ����������ʱ���Ӧ�Ŷ���ʱ��̶�\n��������������(�������0����С��0��������˳�):");
		scanf("%d", &input);
		hour = input / hours;
		minute = (input - (hour*hours))/Seconds;
		second = (input - ((hour * hours) + minute * Seconds)) % Seconds;
		printf("�������Сʱ��%d,������%d,����%d\n",hour,minute,second);
	}
	return 0;
}

int intergral_classwork2(void) {
	int num=0,num1=0;
	printf("hi,�����ǿ������������������10���ж���\n��������������:");
	scanf("%d", &num);
	num1 = num + 10;
	while (num<=num1) {
		printf("���:%d\n", num);
		num++;
	}
	return 0;
}

int intergral_classwork3(void) {
	int days=1,weekday,day;
	while (days > 0) {
		printf("hi,�����ǿ���������������ж���\n��������������:");
		scanf("%d", &days);
		weekday = days / Week;
		day = (days - (weekday * Week)) % Week;
		printf("%d����%d�ܺ�%d��\n", days, weekday, day);
	}
	return 0;
}

int intergral_classwork4(void) {
	float input = 0.0;
	float inch;
	while (input >= 0) {
		printf("hi,�����ǿ�������߻����Ӣ���ж����\n��������������(���븺�������˳�):");
		scanf("%f", &input);
		inch = input / Inches;
		printf("%f������%fӢ��\n",input,inch);
	}
	return 0;
}

int intergral_classwork5(void) {
	int count=0,input=0,days=0;
	printf("hi,�����ǿ����㵽�����������׬����Ǯ��\n��������������:");
	scanf("%d", &input);
	while (days<input) {
		count++;
		days++;
		printf("��%d��,����%d�����\n",days,count);
	}
	return 0;
}

int intergral_classwork6(void) {
	int count=0, input = 0, days = 0,sqrt=0;
	printf("hi,�����ǿ����㵽�����������׬����Ǯ��\n��������������:");
	scanf("%d", &input);
	while (days < input) {
		count++;
		sqrt = count * count;
		days++;
		printf("��%d��,����%d�����\n", days, sqrt);
	}
	return 0;
}

int intergral_classwork7(double sqrt) {
	double output=0;
	output=cubic(sqrt);
	printf("������:%f\n", output);
	return 0;
}

int intergral_classwork8(void) {
	int input,num;
	const int staticnum;
	printf("hi,�����ǿ����������������������� ��\n�����������һ������:");
	scanf("%d", &input);
	printf("����������ڶ�������:");
	scanf("%d", &staticnum);
	num = input % staticnum;
	printf("%d��%d����������:%d\n",input,staticnum,num);
	printf("��������ֻ��Ҫ����һ�������ͺ���(���˳���ʱ�����븺��)\n");
	while (input >=0) {
		printf("��������:");
		scanf("%d", &input);
		num = input % staticnum;
		printf("%d��%d����������:%d\n", input, staticnum, num);
	}
	return 0;
}


