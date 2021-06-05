#include  <stdio.h>

int alter(int *x,int *y) {
	int temp=0;
	printf("计算前的x值为%d y值为%d\n", *x, *y);
	temp = *x;
	*x = *x + *y;
	*y = temp - *y;
	printf("计算后的x值为%d y值为%d\n", *x, *y);
}
int review_function_6(void) {
	int x = 5, y = 10;
	alter(&x, &y);
	return 0;
}

int max_return(int *x,int *y,int *z) {
	if (*x > * y && *x > * z) {
		return *x;
	}
	else if (*y > * z && *y > * x) {
		return *y;
	}
	else {
		return *z;
	}
}

int review_function_8(void) {
	int x = 22, y = 23,z=10;
	int result = 0;
	result=max_return(&x, &y,&z);
	printf("结果是%d\n", result);
	return 0;
}

int review_function_menu(void) {
	printf("*************************************\n");
	printf("please choose one of the following:\n");
	printf("1) copy files \t 2) move files\n"
			  "3) remove files \t 4) quit\n ");
	printf("*************************************\n");
	printf("请输入属于类别前的数字:");
}


int min(double *x, double *y) {
	return (*x > * y) ? *y : *x;
}
int function_classwork_1(void) {
	double x = 7.0, y = 6.0;
	double result = 0.0;
	result=min(&x, &y);
	printf("结果是%f\n", result);
	return 0;
}

int chline(char *ch,int *x, int *y) {
	for (int i = 0; i <= *y; i++) {//外循环控制行
		for (int j = 0; j <= *x; j++) {//内循环控制列
			printf("%c", *ch);
		}
		printf("\n");
	}
}
int function_classwork_2(void) {
	int x=10, y=10;
	char ch = 's';
	chline(&ch, &x, &y);
}

int chline_1(char* ch, int* x, int* y) {
	for (int i = 0; i < *y; i++) { //外循环 控制行
		for (int j = 0; j <*x; j++) { //内循环 控制列
			printf("%c", *ch);
		}
		printf("\n");
	}
}
int function_classwork_3(void) {
	int x = 0, y = 0;
	char ch = ' ';
	printf("请输入三个参数来运行函数(第一个是一个字符,第二个是显示的列数,第三个是显示的行数,请用空格分隔):");
	scanf("%c %d %d", &ch, &x, &y);
	chline_1(&ch, &x, &y);
}

int average_sum(double *x,double *y) {
	double x_1=*x, y_1=*y;
	double z=1.0;
	double x_reciprocal, y_reciprocal;
	double result;
	x_reciprocal = 1/x_1;
	y_reciprocal = 1 / y_1;
	result =(x_reciprocal + y_reciprocal)/2;
	printf("计算结果是:%lf\n", 1 / result);
}

int function_classwork_4(void) {
	double x = 5.0, y = 6.0;
	average_sum(&x, &y);
}

int  larger_of(double* x, double* y) {
	double temp = 0.0;
	printf("计算前的x值为%f y值为%f\n", *x, *y);
	if (*x > * y) {
		temp = *y;
		*y = *x;
		*x = temp;
	}
	else {
		temp = *x;
		*x = *y;
		*y = temp;
	}
	printf("计算后的x值为%f y值为%f\n", *x, *y);
	return 0;
}

int function_classwork_5(void) {
	double x, y;
	x = y  = 0.0;
	printf("请输入两个用空格空开的小数:");
	scanf("%lf %lf", &x, &y);
	larger_of(&x, &y);
}

int exchange_function(double* x, double* y, double* z) {
	double temp = 0.0;
	printf("计算前的x值为%f y值为%f z值为%f\n", *x, *y, *z);
	if (*x > * y && *x > * z) {
		temp = *x;
		*x = *z;
		*z = temp;
		if (*y < *x) {
			temp = *x;
			*x = *y;
			*y = temp;
		}
	}
	else if (*y > * x && *y > * z) {
		temp = *z;
		*z = *y;
		*y = temp;
		if (*x > * y) {
			temp = *x;
			*x = *y;
			*y = temp;
		}
	}
	else if (*z > * x && *z > * y) {
		if (*x > * y) {
			temp = *x;
			*x = *y;
			*y = temp;
		}
	}
	printf("计算后的x值为%f y值为%f z值为%f\n", *x, *y, *z);
}


int function_classwork_6(void) {
	double x, y,z;
	x = y =z= 0.0;
	printf("请输入三个用空格空开的小数:");
	scanf("%lf %lf %lf", &x, &y,&z);
	exchange_function(&x, &y,&z);
}

int function_classwork_7(void) {

}

double power(double n, int p) {
	double pow = 1;
	int i;
	if (n == 0) {
		return 0;
	}
	if (p == 0) {
		return 1;
	}
	if(p>0){
		for (i = 1; i <= p; i++) {
			pow *= n;
		}
	}
	else {
		for (i = 1; i <= (p*-1); i++) {
			pow *= n;
		}
		pow = 1 / pow;
	}
	return pow;
}

int function_classwork_8(void) {
	int x, y;
	x = 0;
	y = 9;
	double result;
	result=power(x, y);
	printf("%d的%d次幂结果是%lf\n",x,y,result);
}
/*
	这道题的重点是运用递归来写幂函数
	递归的条件就是一层一层往下找,直到满足某个值的条件下不会执行调用自身函数的语句
	会直接跳过并且往下执行语句直到遇到return语句
	往下找的过程结束以后,程序会将遇到的语句按照相反顺序执行,此处的例子为p-1变为p+1;直到p==p结束
	一层一层往下找满足条件以后会一层一层返回调用的上层函数
*/
double power_recursion(double n, int p) {
	double 	ans;
	if(p>0){
		ans = n * power_recursion(n, p - 1);
	}
	else {
		ans = 1;
	}
	return ans;
}

int function_classwork_9(void) {
	int x, y;
	x = 2, y = 4;
	double result;
	result = power_recursion(x, y);
	printf("%d的%d次幂结果是%lf\n", x, y, result);
}

int binary(unsigned long num) {
	int  read;
	read = num % 2;
	if (num >= 2)
		binary(num / 2);
	printf("%d", read);
}

int function_classwork_10(void) {
	int num = 20;
	printf("%d的二进制是:",num);
	binary(num);
	printf("\n");
}

int binary_n(unsigned long num,int y) {
	int  read;
	read = num % y;
	if (num >= y)
		binary_n(num/y,y);
	printf("%d", read);
}

int function_classwork_11(void) {
	int num = 129, z = 8;
	printf("%d的%d进制是:", num, z);
	binary_n(num, z);
	printf("\n");
}


/*斐波拉契数列核心在于从第三项开始每一项都等于前两项之和
	然而不会写 = =
*/
int fibonacci(int x) {
	int result;
	if (1 == x || 2 == x)
	{
		return 1;
	}
	return fibonacci(x - 2) + fibonacci(x - 1);
}

int function_classwork_12(void) {
	int x = 8;
	int result = 0;
	fibonacci(x);
}