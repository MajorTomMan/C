#include <stdio.h>
#include <string.h>
#define months 12
#define years  5
#define size 5
int rain(void) {
	const float rainfall_num[years][months] = {
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
		{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
		{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
		{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
		{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,3.2}
	};
	int year, month;
	float subtot, total;
	float (* ptr)[months];  //结合律
	ptr= rainfall_num;
	printf(" \t year \t rainfall (inches)\n");
	for (year = 0,total=0.0; year < years; year++) {
		for (month = 0,subtot=0.0; month < months; month++) {
			 subtot+=*(*(ptr+year)+month);
		}
		printf(" \t %d \t %.1f\n", 2010 + month, subtot);
		total += subtot;
	}
	printf("The yearly average is %.1f inches.\n\n", total/years);
	printf("monthly averages:\n\n");
	printf("Jeb \t Feb \t Mar \t Apr \t May \t Jun \t Jul \t Aug \t Sep \t Oct \t Nov \t Dec\n");
	for (month = 0, total = 0.0; month < months; month++) {
		for (year = 0, subtot = 0.0; year < years; year++) {
			subtot += *(*(ptr + year) + month);
		}
		printf("%.1f \t ", subtot/years);
		total += subtot;
	}
	printf("\n");
	printf("\n");
}

int printer_classwork_1(void) {
	rain();
}

void copy_arr1(double arr[], double arr_copy[],int n) {
	double temp=0.0;
	for (int i = 0; i < n; i++) {
		temp = arr[i];
		arr_copy[i] = temp;
	}
	for (int i = 0; i < size; i++) {
		printf("源数组数据为:%lf\n", arr[i]);
	}
	printf("------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < size; i++) {
		printf("复制后的数组一数据为:%lf\n",arr_copy[i]);
	}
	printf("------------------------------------------------------------------------------------------------\n");
}
void copy_arr2(const double arr[], double arr_copy[], int n) {
	int i = 0;
	double temp = 0.0;
	double* ptr,*ptr_copy;
	ptr = arr;
	ptr_copy = arr_copy;
	while(i<n) {
		temp = *ptr;
		*ptr_copy = temp;
		ptr++;
		ptr_copy++;
		i++;
	}
	ptr = arr;
	ptr_copy = arr_copy;
	for (int i = 0; i < size; i++) {
		printf("复制后的数组二数据为:%lf\n",*ptr_copy++);
	}
	printf("------------------------------------------------------------------------------------------------\n");
}

void copy_arr3(const double arr[], double arr_copy[], double *ptr) {
	double temp = 0.0;
	double* ptr_1;
	int i = 0;
	ptr_1 = arr;
	_Bool result=1;
	while (result) {
		if (ptr_1 - ptr == 0) {
			temp = arr[i];
			arr_copy[i] = temp;
			result =0;
		}
		else {
			temp = arr[i];
			arr_copy[i] = temp;
			i++;
			ptr_1++;
		}
	}
	for (i = 0; i < size; i++) {
		printf("复制后的数组三数据为:%lf\n", arr_copy[i]);
	}
	printf("------------------------------------------------------------------------------------------------\n");
}


int printer_classwork_2(void) {
	double source[size]= { 1.1,2.2,3.3,4.4,5.5};
	double target1[size]={ 0.0 }, target2[size] = { 0.0 }, target3[size] = { 0.0 };
	double* ptr;
	ptr = &source[4];
	copy_arr1(source,target1,size);
	copy_arr2(source, target2, size);
	copy_arr3(source, target3, ptr);
}

int max_return_(int num[]) {
	int temp = 0;
	int* ptr;
	ptr = num;
	for (int i = 0; i < size; i++) {
		if (temp < *ptr) {
			temp = *ptr;
		}
		ptr++;
	}
	printf("max num is %d\n", temp);
}

int printer_classwork_3(void) {
	int num[size] = {6,2,3,1,5};
	max_return_(num);
}

int index_return(double *ptr) {
	double temp = 0.0;
	int i = 0;
	int max_index=0;
	for (; i < size; i++) {
		if (temp < *ptr) {
			temp = *ptr;
			max_index=i;
		}
		ptr++;
	}
	return max_index;
}

int printer_classwork_4(void) {
	double num[size] = { 1.1,12.0,3.1,1.2,0.5 };
	int max_index = 0;
	max_index=index_return(num);
	printf("max num index is %d\n", max_index);
}

double differ_return(double* ptr) {
	double max = 0.0,min=0.0;
	int i = 0;
	int max_index = 0;
	for (; i < size; i++) {
		if (max < *ptr) {
			max = *ptr;
		}
		ptr++;
	}
	ptr--;
	min = max;
	for (i=0; i < size; i++) {
		if (min > *ptr) {
			min = *ptr;
		}
		ptr--;
	}
	ptr--;
	return max-min ;
}

int printer_classwork_5(void) {
	double num[size] = { 1.1,12.0,6.0,1.2,5.5 };
	double differ = 0;
	differ = differ_return(num);
	printf("differ is %lf\n", differ);
}

int reverse_order(double arr[]) {
	double temp,temp1;
	int i,j;
	_Bool flag=1;
	printf("倒序前的数组数据为:");
	for (int z= 0; z < size; z++) {
		printf("%.1f  ", arr[z]);
	}
	printf("\n");
	i = size-1;
	j = 0;
	while (flag) {
		if (i == j) {
			break;
		}
		else {
			temp = arr[i];
			temp1 = arr[j];
			arr[j] = temp;
			arr[i] = temp1;
		}
		i--;
		j++;
	}
	printf("倒序后的数组数据为:");
	for (int z= 0; z < size; z++) {
		printf("%.1f  ", arr[z]);
	}
	printf("\n");
}

int printer_classwork_6(void) {
	double num[size] = { 1.1,12.0,6.0,1.2,5.5 };
	reverse_order(num);
}

int copy_arr4(const double(*ptr)[size], double(*ptr1)[size], int i,int j) {
	double temp=0.0;
	printf("源数组数据为:\n");
	for (int k = 0; k < i; k++) {
		for (int z = 0; z < j; z++) {
			printf("%.1f  ", *(*(ptr + k) + z));
		}
		printf("\n");
	}
	printf("复制前的数组数据为:\n");
	for (int k = 0; k < i; k++) {
		for (int z = 0; z < j; z++) {
			printf("%.1f  ", *(*(ptr1 + k) + z));
		}
		printf("\n");
	}
	for (int k = 0; k < i; k++) {
		for (int z = 0; z < j; z++) {
			temp = *(*(ptr + k) + z);
			*(*(ptr1+k)+z)= temp;
		}
	}
	printf("复制后的数组数据为:\n");
	for (int k = 0; k < i; k++) {
		for (int z = 0; z < j; z++) {
			printf("%.1f  ", *(*(ptr1 + k) + z));
		}
		printf("\n");
	}
}

int printer_classwork_7(void) {
	double num[size][size] = {
		{1.1,2.2,3.3,4.4,5.5},
		{1.1,2.2,3.3,4.4,5.5},
		{1.1,2.2,3.3,4.4,5.5},
		{1.1,2.2,3.3,4.4,5.5},
		{1.1,2.2,3.3,4.4,5.5}
	};
	double num1[size][size] = {0.0};
	copy_arr4(num,num1,size,size);
}

int copy_arr5(double arr[],double copy_arr[],int m,int n) {
	double temp = 0.0;
	double* ptr,* ptr1;
	ptr = arr;
	ptr1 = copy_arr;
	printf("源数组数据为:");
	for (int i = 0; i < m; i++) {
		printf("%.1f  ", *ptr++);
	}
	printf("\n");
	printf("复制前数组二数据为:");
	for (int i = 0; i < n; i++) {
		printf("%.1f  ", *ptr1++);
	}
	printf("\n");
	ptr = arr;
	ptr1 = copy_arr;
	for (int i=0; i < m; i++) {
		if (i >=2&&i<=4) {
			temp = *ptr;
			*ptr1 = temp;
			ptr1++;
		}
		ptr++;
	}
	ptr = arr;
	ptr1 = copy_arr;
	printf("复制后数组二数据为:");
	for (int i = 0; i < n; i++) {
		printf("%.1f  ", *ptr1++);
	}
	printf("\n");
}

int printer_classwork_8(void) {
	double num1[7] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7 };
	double num2[3] = { 0.0 };
	copy_arr5(num1, num2, 7,3);
}

int show_arr(double(*ptr)[size], double(*ptr1)[size], int m) {
	printf("复制后的数组二数据为:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < size; j++) {
			printf("%.1f  ", *(*(ptr1 + i) + j));
		}
		printf("\n");
	}
}

int copy_arr6(double(*ptr)[size],double (*ptr1)[size], int m,int n) {
	double temp = 0.0;
	printf("源数组数据为:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < size; j++) {
			printf("%.1f  ", *(*(ptr + i) + j));
		}
		printf("\n");
	}
	printf("复制前的数组二数据为:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < size; j++) {
			printf("%.1f  ", *(*(ptr1 + i) + j));
		}
		printf("\n");
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < size; j++) {
			temp=*(*(ptr+i)+j);
			*(*(ptr1 + i) + j)=temp;
		}
	}
	show_arr(ptr,ptr1,n);
}

int printer_classwork_9(void) {
	double num1[size][size] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7 };
	double num2[7][size] = { 0.0 };
	copy_arr6(num1, num2, size,7);
}

int calculate_arr(double(*ptr)[2], double(*ptr1)[2], double(*ptr2)[2], int m, int n) {
	double sum=0.0;
	printf("数组一数据为:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%.1f  ", *(*(ptr + i) + j));
		}
		printf("\n");
	}
	printf("数组二数据为:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%.1f  ", *(*(ptr1 + i) + j));
		}
		printf("\n");
	}
	printf("计算前的数组三数据为:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%.1f  ", *(*(ptr2 + i) + j));
		}
		printf("\n");
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			sum = *(*(ptr + i) + j) + *(*(ptr1 + i) + j);
			*(*(ptr2 + i) + j) = sum;
		}
	}
	printf("计算前的数组三数据为:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%.1f  ", *(*(ptr2 + i) + j));
		}
		printf("\n");
	}
}

int printer_classwork_10(void) {
	double num1[3][2] = { 1.1,2.2,3.3,4.4,5.5,6.6 };
	double num2[3][2] = { 1.1,2.2,3.3,4.4,5.5,6.6 };
	double num3[3][2] = { 0.0 };
	calculate_arr(num1, num2, num3,3, 2);
}

int double_arr_value(int(*ptr)[size], int m) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < size; j++) {
			*(*(ptr + i) + j) = *(*(ptr + i) + j) * 2;
		}
	}
}

int show_arr_value(int(*ptr)[size],int m) {
	printf("源数组数据为:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d  ", *(*(ptr + i) + j));
		}
		printf("\n");
	}
	double_arr_value(ptr, m);
	printf("计算后数组数据为:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d  ", *(*(ptr + i) + j));
		}
		printf("\n");
	}
}

int printer_classwork_11(void) {
	int num[3][size] = { 
		{1,2,3,4,5} ,{4,5,6,7,8}, {7,8,9,10,11}
	};
	show_arr_value(num,3);
}

int calculate_years_rainfall(float(*ptr)[months], int year, int month, float subtot, float total) {
	printf("monthly averages:\n\n");
	printf("Jeb \t Feb \t Mar \t Apr \t May \t Jun \t Jul \t Aug \t Sep \t Oct \t Nov \t Dec\n");
	for (month = 0, total = 0.0; month < months; month++) {
		for (year = 0, subtot = 0.0; year < years; year++) {
			subtot += *(*(ptr + year) + month);
		}
		printf("%.1f \t ", subtot / years);
		total += subtot;
	}
}

int calculate_months_rainfall(float(*ptr)[months], int year, int month, float subtot, float total) {
	printf(" \t year \t rainfall (inches)\n");
	for (year = 0, total = 0.0; year < years; year++) {
		for (month = 0, subtot = 0.0; month < months; month++) {
			subtot += *(*(ptr + year) + month);
		}
		printf(" \t %d \t %.1f\n", 2010 + month, subtot);
		total += subtot;
	}
	printf("The yearly average is %.1f inches.\n\n", total / years);
}

int rain_func(void) {
	const float rainfall_num[years][months] = {
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
		{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
		{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
		{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
		{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,3.2}
	};
	int year=0, month=0;
	float subtot=0.0, total=0.0;
	float(*ptr)[months];  //结合律
	ptr = rainfall_num;
	calculate_months_rainfall(ptr, year, month, subtot, total);
	calculate_years_rainfall(ptr, year, month, subtot, total);
	printf("\n");
	printf("\n");
}
int printer_classwork_12(void) {
	rain_func();
}



int User_input(double user_input[3][5]) {
	printf("请输入15个小数:");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%lf", &user_input[i][j]);
		}
	}
	printf("\n");
}

int calculate_average(double user_input[3][5],double temp,double sum, double average_temp,int i,int j) {
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++) {
			temp += user_input[i][j];
			sum += user_input[i][j];
		}
		average_temp = temp / j;
		printf("第%d组数据的平均值为%lf\n", i, average_temp);
		temp = 0;
	}
	printf("所有的数据平均值为%lf\n", sum / i);
}

int calaulate_max(double user_input[3][5],double max,int i,int j) {
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++) {
			if (max < user_input[i][j]) {
				max = user_input[i][j];
			}
		}
	}
	printf("最大值为:%lf\n", max);
}

int users_input(void) {
	int i, j;
	i = j = 0;
	double user_input[3][5] = { 0.0 };
	double average_temp=0.0;
	double temp=0.0;
	double sum=0.0;
	double max=0.0;
	User_input(user_input);
	printf("源数组数据为:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%lf  ", user_input[i][j]);
		}
		printf("\n");
	}
	calculate_average(user_input, temp, sum, average_temp, i, j);
	calaulate_max(user_input, max, i, j);
}

int printer_classwork_13(void) {
	users_input();
}