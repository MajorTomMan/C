#include <stdio.h>
#include <string.h>
#include <float.h>
#define density 62.4

int study4(void) {
	float weight, volume;
	int size, letters;
	char name[40];
	printf("hi!,whats your first name?\n");
	scanf(" %s", name);
	printf("%s,whats your weight in pounds?\n", name);
	scanf("%f", &weight);
	size = sizeof(name);
	letters = strlen(name);
	volume = weight / density;
	printf("well, %s,your volume is %2.2f cubic feet.\n",
		name,volume);
	printf("also,your first name has %d letters, \n", 
		letters);
	printf("and we have %d bytes to store it .\n", size);
	return 0;

}

int string_classwork1(void) {
	char Fristname[40];
	char Secondname[40];
	printf("hi,让我们看一下你的姓名是什么吧,先输入姓名(请使用空格分隔姓和名):\n");
	scanf(" %s %s", Fristname,Secondname);
	printf("你的姓名是:%s %s\n",Fristname,Secondname);
	return 0;
}
int string_classwork2(void) {
	char Fristname[40];
	char Secondname[40];
	int size_F,size_S;
	printf("hi,让我们看一下你的姓名长度是什么吧,先输入姓名(请使用空格分隔姓和名):\n");
	scanf(" %s %s", Fristname, Secondname);
	printf("你的姓名是:\"%s %s\"\n", Fristname, Secondname);
	printf("你的姓名是:\"%+20s %s\"\n", Fristname, Secondname);
	printf("你的姓名是:\"%s %-20s\"\n", Fristname, Secondname);
	size_F = strlen(Fristname);
	size_S = strlen(Secondname);
	printf("你的姓名是:\"%+*s %-*s\"\n",size_F+3,Fristname,size_S+3,Secondname);//未完成
	return 0;
}


int string_classwork3() {
	float fl_1, fl_2;
	printf("hi,让我们看看两个浮点数的输出吧,先输入第一个浮点数,使用空格分隔第二个浮点数:\n");
	scanf("%f %f", &fl_1, &fl_2);
	printf("the input is %f or %e\n", fl_1,fl_1);
	printf("the input is %f or %e\n", fl_2, fl_2);
	return 0;
}

int string_classwork4() {
	char cn[40];
	float tall;
	printf("hi,请输入你的身高和体重吧,先输入姓名,再用空格分隔后输入身高:\n");
	scanf("%s %f", cn, &tall);
	printf("%s you are is %1.2e metre tall!\n", cn,tall);
	return 0;
}

int string_classwork5() {
	float mbs, mb,times;
	printf("hi,输入你要下载的文件大小和下载速度吧,让我们看看这个文件要多久才能下载完,先输入文件大小(单位为MB),再用空格分隔以后输入下载速度(单位是MBs):\n");
	scanf("%f %f", &mb, &mbs);
	mb = 2e23*mb; 
	mbs = 2e23 * mbs;
	times = mb / mbs;
	printf("你要下载的文件大小是%1.2eMB,你的下载速度是%1.2eMBs,下载时间需要%fs\n",mb,mbs,times);
	return 0;
}

int string_classwork6() {
	char Fristname[40];
	char Secondname[40];
	int F_length,S_length;
	printf("hi,输入自己的姓名吧,先输入姓,再输入名,中间用空格分隔:");
	scanf("%s %s", Fristname, Secondname);
	F_length = strlen(Fristname);
	S_length = strlen(Secondname);
	printf("%s %s\n%*d %*d\n",Fristname,Secondname,F_length, F_length, S_length, S_length);
	printf("%s %s\n%-*d %-*d\n", Fristname, Secondname, F_length, F_length, S_length, S_length);
	return 0;
}

int string_classwork7(void) {
	double db = 1.0 / 3.0;
	float fl = 1.0 / 3.0;
	printf("小数点后6位:%1.6e,小数点后12位:%1.12e,小数点后16位:%1.16e\n",db,db,db);
	printf("小数点后6位:%1.6e,小数点后12位:%1.12e,小数点后16位:%1.16e\n", fl,fl,fl);
	printf("小数点后6位:%1.6e,小数点后12位:%1.12e,小数点后16位:%1.16e\n", FLT_DIG, FLT_DIG, FLT_DIG);
	printf("小数点后6位:%1.6e,小数点后12位:%1.12e,小数点后16位:%1.16e\n", DBL_DIG, DBL_DIG, DBL_DIG);
}