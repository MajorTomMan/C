#include  <stdio.h>

int alter(int *x,int *y) {
	int temp=0;
	printf("����ǰ��xֵΪ%d yֵΪ%d\n", *x, *y);
	temp = *x;
	*x = *x + *y;
	*y = temp - *y;
	printf("������xֵΪ%d yֵΪ%d\n", *x, *y);
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
	printf("�����%d\n", result);
	return 0;
}

int review_function_menu(void) {
	printf("*************************************\n");
	printf("please choose one of the following:\n");
	printf("1) copy files \t 2) move files\n"
			  "3) remove files \t 4) quit\n ");
	printf("*************************************\n");
	printf("�������������ǰ������:");
}


int min(double *x, double *y) {
	return (*x > * y) ? *y : *x;
}
int function_classwork_1(void) {
	double x = 7.0, y = 6.0;
	double result = 0.0;
	result=min(&x, &y);
	printf("�����%f\n", result);
	return 0;
}

int chline(char *ch,int *x, int *y) {
	for (int i = 0; i <= *y; i++) {//��ѭ��������
		for (int j = 0; j <= *x; j++) {//��ѭ��������
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
	for (int i = 0; i < *y; i++) { //��ѭ�� ������
		for (int j = 0; j <*x; j++) { //��ѭ�� ������
			printf("%c", *ch);
		}
		printf("\n");
	}
}
int function_classwork_3(void) {
	int x = 0, y = 0;
	char ch = ' ';
	printf("�������������������к���(��һ����һ���ַ�,�ڶ�������ʾ������,����������ʾ������,���ÿո�ָ�):");
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
	printf("��������:%lf\n", 1 / result);
}

int function_classwork_4(void) {
	double x = 5.0, y = 6.0;
	average_sum(&x, &y);
}

int  larger_of(double* x, double* y) {
	double temp = 0.0;
	printf("����ǰ��xֵΪ%f yֵΪ%f\n", *x, *y);
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
	printf("������xֵΪ%f yֵΪ%f\n", *x, *y);
	return 0;
}

int function_classwork_5(void) {
	double x, y;
	x = y  = 0.0;
	printf("�����������ÿո�տ���С��:");
	scanf("%lf %lf", &x, &y);
	larger_of(&x, &y);
}

int exchange_function(double* x, double* y, double* z) {
	double temp = 0.0;
	printf("����ǰ��xֵΪ%f yֵΪ%f zֵΪ%f\n", *x, *y, *z);
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
	printf("������xֵΪ%f yֵΪ%f zֵΪ%f\n", *x, *y, *z);
}


int function_classwork_6(void) {
	double x, y,z;
	x = y =z= 0.0;
	printf("�����������ÿո�տ���С��:");
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
	printf("%d��%d���ݽ����%lf\n",x,y,result);
}
/*
	�������ص������õݹ���д�ݺ���
	�ݹ����������һ��һ��������,ֱ������ĳ��ֵ�������²���ִ�е��������������
	��ֱ��������������ִ�����ֱ������return���
	�����ҵĹ��̽����Ժ�,����Ὣ��������䰴���෴˳��ִ��,�˴�������Ϊp-1��Ϊp+1;ֱ��p==p����
	һ��һ�����������������Ժ��һ��һ�㷵�ص��õ��ϲ㺯��
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
	printf("%d��%d���ݽ����%lf\n", x, y, result);
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
	printf("%d�Ķ�������:",num);
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
	printf("%d��%d������:", num, z);
	binary_n(num, z);
	printf("\n");
}


/*쳲��������к������ڴӵ����ʼÿһ�����ǰ����֮��
	Ȼ������д = =
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