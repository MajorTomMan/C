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
	printf("hi,�����ǿ�һ�����������ʲô��,����������(��ʹ�ÿո�ָ��պ���):\n");
	scanf(" %s %s", Fristname,Secondname);
	printf("���������:%s %s\n",Fristname,Secondname);
	return 0;
}
int string_classwork2(void) {
	char Fristname[40];
	char Secondname[40];
	int size_F,size_S;
	printf("hi,�����ǿ�һ���������������ʲô��,����������(��ʹ�ÿո�ָ��պ���):\n");
	scanf(" %s %s", Fristname, Secondname);
	printf("���������:\"%s %s\"\n", Fristname, Secondname);
	printf("���������:\"%+20s %s\"\n", Fristname, Secondname);
	printf("���������:\"%s %-20s\"\n", Fristname, Secondname);
	size_F = strlen(Fristname);
	size_S = strlen(Secondname);
	printf("���������:\"%+*s %-*s\"\n",size_F+3,Fristname,size_S+3,Secondname);//δ���
	return 0;
}


int string_classwork3() {
	float fl_1, fl_2;
	printf("hi,�����ǿ��������������������,�������һ��������,ʹ�ÿո�ָ��ڶ���������:\n");
	scanf("%f %f", &fl_1, &fl_2);
	printf("the input is %f or %e\n", fl_1,fl_1);
	printf("the input is %f or %e\n", fl_2, fl_2);
	return 0;
}

int string_classwork4() {
	char cn[40];
	float tall;
	printf("hi,�����������ߺ����ذ�,����������,���ÿո�ָ����������:\n");
	scanf("%s %f", cn, &tall);
	printf("%s you are is %1.2e metre tall!\n", cn,tall);
	return 0;
}

int string_classwork5() {
	float mbs, mb,times;
	printf("hi,������Ҫ���ص��ļ���С�������ٶȰ�,�����ǿ�������ļ�Ҫ��ò���������,�������ļ���С(��λΪMB),���ÿո�ָ��Ժ����������ٶ�(��λ��MBs):\n");
	scanf("%f %f", &mb, &mbs);
	mb = 2e23*mb; 
	mbs = 2e23 * mbs;
	times = mb / mbs;
	printf("��Ҫ���ص��ļ���С��%1.2eMB,��������ٶ���%1.2eMBs,����ʱ����Ҫ%fs\n",mb,mbs,times);
	return 0;
}

int string_classwork6() {
	char Fristname[40];
	char Secondname[40];
	int F_length,S_length;
	printf("hi,�����Լ���������,��������,��������,�м��ÿո�ָ�:");
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
	printf("С�����6λ:%1.6e,С�����12λ:%1.12e,С�����16λ:%1.16e\n",db,db,db);
	printf("С�����6λ:%1.6e,С�����12λ:%1.12e,С�����16λ:%1.16e\n", fl,fl,fl);
	printf("С�����6λ:%1.6e,С�����12λ:%1.12e,С�����16λ:%1.16e\n", FLT_DIG, FLT_DIG, FLT_DIG);
	printf("С�����6λ:%1.6e,С�����12λ:%1.12e,С�����16λ:%1.16e\n", DBL_DIG, DBL_DIG, DBL_DIG);
}