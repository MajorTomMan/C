#include<stdio.h>

int study2(void) {
	float weight, value;
	printf("are you worth your weight in platinum?\n");
	printf("let's check it out.\n");
	printf("please enter your  weight in pounds:");
	scanf("%f", &weight);
	value = 1700.0 * weight * 14.8533;
	printf("your weight in platinum is worth $%.2f.\n",value);
	printf("you are easily worth that! if platinum prices drop,\n");
	printf("eat more to maintain your value.\n");
	return 0;
}

int study3(void) {
	char x=49;
	char y = 'A' ;
	printf("C:%c\n",x); //CΪascii���ַ�
	printf("H:%#x,O:%#o,D:%#d\n",y,y,y); //%xΪʮ������(Hexadecimal),%oΪ�˽���(Octal),%dΪʮ����(decimal)
	return 0;
}

int data_classwork1(void) {
	char ch = '\r',ch_d=13,ch_o='\015',ch_x='\x0D';
	printf("output enter key:%c,dec:%c,oct:%c,hex:%c\n", ch,ch_d,ch_o,ch_x); //δ�ɹ����enter
	return 0;
}

int data_classwork2(void) {
	int x = 999999999999999+2; // �������
	float y = 3.4e38 * 100.0f;  //���������
	float z = 2.0e20+1.0f;  //����������
	z = z - 2.0e20;	
	printf("int_overflow:%d\nfloat_overflow:%f\nfloat_underflow:%f\n", x, y, z);
	return 0;
}
int data_classwork3(void) {
	int input;
	printf("please enter number (0-127):");
	scanf("%d", &input);
	printf("alright,look like this number is:%c\n",input);
	return 0;
}

int data_classwork4(void) {
	printf("\astartied by the sudden sound,sally shouted\n\"by the great pumpkin,what was that\"\n");
	return 0;
}

int data_classwork5(void) {
	double db=3.156e7;
	float age;
	printf("hello,�������������������һ���ж�����,��������������:");
	scanf("%f", &age);
	printf("�����ǿ����ӳ�����ĿǰΪֹ�㾭����:%f��\n", age * db);
	return 0;
}
int data_classwork6(void) {
	long double db = 3.0e-23; //ˮ������
	long double kilo=1/db; //һ�����ˮ����
	float q; //��ȡƷ����
	long double fo = kilo * 950; //��ȡһƷ�����е�ˮ����
	printf("hello,��������һ�������Ʒ�����ж���ˮ���Ӱ�,������Ʒ����:");
	scanf("%f", &q);
	printf("�����ǿ���һ����%f��ˮ����\n",q*fo); //��ˮ������
	return 0;
}

int data_classwork7(void) {
	double centimetre=2.54; //����
	float q; //Ӣ��
	printf("hello,��������һ���������Ƕ���,������Ӣ����:");
	scanf("%f", &q);
	printf("�����ǿ�����һ����%f����\n",q*centimetre ); //���
	return 0;
}

int data_classwork8(void) {
	long double fo, ounce, ts, tsp;//Ʒ��,��˾,������,����
	double cup; //��
	printf("hello,��������һ��Ʒ�ѺͰ�˾,�������Լ����׵ĵȼ�����,�����뱭��:");
	scanf("%lf", &cup);
	fo = cup*2;
	ounce = cup/8;
	ts = ounce/2;
	tsp = ts / 3;
	printf("�����ǿ���Ʒ�ѵĵȼ�����Ϊ:%f\n",fo);
	printf("�����ǿ�����˾�ĵȼ�����Ϊ:%f\n",ounce);
	printf("�����ǿ��������׵ĵȼ�����Ϊ:%f\n",ts);
	printf("�����ǿ������׵ĵȼ�����Ϊ:%f\n",tsp);
	//δ���
}