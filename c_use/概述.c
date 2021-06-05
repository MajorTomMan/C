#include <stdio.h> //预处理

int study1(void) {
	int num=1;  // 命名一个变量并赋值为1
	printf("my favorite number is %d\n", num); //打印一条信息显示我最喜欢的数字是num变量中的数字,使用%d占位符来标识num变量的值应该在哪里显示
	//,num表示调用num变量
	return 0;
} //函数体结束

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
	printf("hello,胡峻豪\n");
	printf("这是你的姓:胡\n");
	printf("这是你的名:峻豪\n");
	printf("这是你的姓名:胡峻豪\n");
	return 0;
}

int adumbrate_classwork2(void) {
	printf("hello,胡峻豪,这是你的地址:江西省赣州市宁都县林业局宿舍\n");
	return 0;
}

int adumbrate_classwork3(void) {
	int age = 23,days=365,countdays;
	countdays = age * days;
	printf("从你出生到现在一共过去了%d天\n",countdays);
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
	printf("toes variable  value is %d ", toes); //原值 
	printf("after value is %d ", toes*2); //两倍
	printf("final value is %d\n", toes *toes); //平方
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