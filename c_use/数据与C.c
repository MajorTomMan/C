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
	printf("C:%c\n",x); //C为ascii码字符
	printf("H:%#x,O:%#o,D:%#d\n",y,y,y); //%x为十六进制(Hexadecimal),%o为八进制(Octal),%d为十进制(decimal)
	return 0;
}

int data_classwork1(void) {
	char ch = '\r',ch_d=13,ch_o='\015',ch_x='\x0D';
	printf("output enter key:%c,dec:%c,oct:%c,hex:%c\n", ch,ch_d,ch_o,ch_x); //未成功输出enter
	return 0;
}

int data_classwork2(void) {
	int x = 999999999999999+2; // 整数溢出
	float y = 3.4e38 * 100.0f;  //浮点数溢出
	float z = 2.0e20+1.0f;  //浮点数下溢
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
	printf("hello,让我们来算算你的年龄一共有多少秒,先输入你的年龄吧:");
	scanf("%f", &age);
	printf("让我们看看从出生到目前为止你经历了:%f秒\n", age * db);
	return 0;
}
int data_classwork6(void) {
	long double db = 3.0e-23; //水分子数
	long double kilo=1/db; //一克里的水分子
	float q; //获取品脱数
	long double fo = kilo * 950; //获取一品脱数中的水分子
	printf("hello,让我们算一下输入的品脱里有多少水分子吧,先输入品脱数:");
	scanf("%f", &q);
	printf("让我们看看一共有%f个水分子\n",q*fo); //总水分子数
	return 0;
}

int data_classwork7(void) {
	double centimetre=2.54; //厘米
	float q; //英寸
	printf("hello,让我们算一下你的身高是多少,先输入英寸数:");
	scanf("%f", &q);
	printf("让我们看看你一共有%f厘米\n",q*centimetre ); //身高
	return 0;
}

int data_classwork8(void) {
	long double fo, ounce, ts, tsp;//品脱,盎司,大汤勺,茶勺
	double cup; //杯
	printf("hello,让我们算一下品脱和盎司,大汤勺以及茶勺的等价容量,先输入杯数:");
	scanf("%lf", &cup);
	fo = cup*2;
	ounce = cup/8;
	ts = ounce/2;
	tsp = ts / 3;
	printf("让我们看看品脱的等价容量为:%f\n",fo);
	printf("让我们看看盎司的等价容量为:%f\n",ounce);
	printf("让我们看看大汤勺的等价容量为:%f\n",ts);
	printf("让我们看看茶勺的等价容量为:%f\n",tsp);
	//未完成
}