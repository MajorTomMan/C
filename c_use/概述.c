#include <stdio.h> //Ԥ����

int study1(void) {
	int num=1;  // ����һ����������ֵΪ1
	printf("my favorite number is %d\n", num); //��ӡһ����Ϣ��ʾ����ϲ����������num�����е�����,ʹ��%dռλ������ʶnum������ֵӦ����������ʾ
	//,num��ʾ����num����
	return 0;
} //���������

int test1(void) {
	int a=5, b=2;
	b = a;
	a = b;
	printf("a:%d,b:%d\n", a,b);
	return 0;
}

int test2() {
	int x=10, y=5;
	y = x + y;
	x = x * y;
	printf("x:%d,y:%d\n", x, y);
	return 0;
}

int adumbrate_classwork1(void) {
	printf("hello,xxx\n");
	printf("���������:x\n");
	printf("���������:xxx\n");
	printf("�����������:xxxx\n");
	return 0;
}

int adumbrate_classwork2(void) {
	printf("hello,xxx,������ĵ�ַ:xxx\n");
	return 0;
}

int adumbrate_classwork3(void) {
	int age = 23,days=365,countdays;
	countdays = age * days;
	printf("�������������һ����ȥ��%d��\n",countdays);
	return 0;
}

int adumbrate_classwork4(void) {
	jolly();
	jolly();
	jolly();
	deny();
	return 0;
}

int adumbrate_classwork5(void) {
	br();
	ic();
	return 0;
}

int adumbrate_classwork6(void) {
	int toes = 10;
	printf("toes variable  value is %d ", toes); //ԭֵ 
	printf("after value is %d ", toes*2); //����
	printf("final value is %d\n", toes *toes); //ƽ��
	return 0;
}

int adumbrate_classwork7(void) {
	one_three();
	return 0;
}

int jolly(void) {
	printf("for he's is a jolly good fellow!\n");
	return 0;
}

int deny(void) {
	printf("which nobody can deny!\n");
	return 0;
}

int br(void) {
	printf("brazil,bussia\n");
	return 0;
}

int ic(void){
	printf("india,china\n");
	return 0;
}

int one_three(void) {
	printf("one\n");
	two();
	return 0;
}

int two(void) {
	printf("two\nthree\n");
	return 0;
}