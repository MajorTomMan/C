#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include "../h_use/starfolk.h"
#define size 12
#define MaxTitle 40
#define MaxAutle 40
#define MaxBks 100
#define CSIZE 4
#define Seats_n 12

extern struct bem Bem;

struct name {
	char first[30];
	char last[30];
};
struct bem {
	int limbs;
	struct name title;
	char type[30];
};

 struct month_name {
	char m_names[size];
	char m_abbrevations[size];
	int m_days;
	int m_numbers;
};
static struct month_name years[12];

static char month_names[12][12] = {
	"January","February","March",
	"April","May","June","July",
	"August","September","October",
	"November","December"
};
static char month_abbrevations[12][12] = {
	"Jan", "Feb", "Mar", "Apr",
	"May", "Jun", "Jul", "August",
	"Sep", "Oct", "Nov", "Dec"
};
static int month_days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
static int month_numbers[12] = {1,2,3,4,5,6,7,8,9,10,11,12};


struct book {
	char title[MaxTitle];
	char author[MaxAutle];
	float value;
	int id;
};


struct name_n {
	char fname[40];
	char mname[40];
	char lname[40];
};

struct social_insurance {
	int s_number;
	struct name_n Name;
};
struct social_insurance s_data[5];


struct grade {
	float language_score;
	float math_score;
	float scient_score;
};

struct students {
	struct name Name;
	struct grade Grade;
	float Average;
};


int struct_review_3(void) {
	//定义结构模板
}

int struct_review_4(void) {
	int month=1;
	struct month_name * ptr;
	ptr = years;
	int i = 0;
	printf("请输入每个月的名字,缩写,天数以及是数字月份\n");
	while (month <13) {
		printf("请输入%d月的名字:", month);
		scanf("%s", &(ptr+i)->m_names);
		printf("请输入%d月的缩写:", month);
		scanf("%s", &(ptr + i)->m_abbrevations);
		printf("请输入%d月的天数:", month);
		scanf("%d", &(ptr + i)->m_days);
		printf("请输入%d月的数字月份:", month);
		scanf("%d", &(ptr + i)->m_numbers);
		month++;
		i++;
	}
	printf("-----------------------------------------------\n");
	i = 0;
	month = 1;
	while (month <13 ) {
		printf("这是%d月的名字:", month);
		printf("%s\n", (ptr + i)->m_names);
		printf("这是%d月的缩写:", month);
		printf("%s\n", (ptr + i)->m_abbrevations);
		printf("这是%d月的天数:", month);
		printf("%d\n", (ptr + i)->m_days);
		printf("这是%d月的数字月份:", month);
		printf("%d\n", (ptr + i)->m_numbers);
		i++;
		month++;
		printf("-----------------------------------------------");
	}
}

int return_days(int m_number) {
	struct month_name* ptr;
	ptr = years;
	int sum = 0;
	for (int i = 0; i < m_number; i++) {
		sum += (ptr+i)->m_days;
	}
	return sum;
}
int struct_review_5(void) {
	struct month_name* ptr;
	ptr = &years;
	int m_number;
	int sum;
	for (int i = 0; i < 13; i++) {
		(ptr + i)->m_days = 30;
	}
	printf("请用数字输入月份:");
	scanf("%d", &m_number);
	sum=return_days(m_number);
	printf("一年中直到该月的天份一共有:%d\n", sum);
}

int struct_review_6(void) {
	int i=0;
	typedef struct lens {
		float foclen;
		float fstop;
		char brand[30];
	}LENS;
	LENS camera[10];
	camera[2].foclen = 500.0;
	camera[2].fstop = 2.0;
	strcpy(camera[2].brand,"Remarkatar");
	printf("%f %f %s\n", camera[2].foclen, camera[2].fstop, camera[2].brand);
	//LENS camera[10] = { [2] = {500,2,"Remarkatar"} };
}

int show_bem(const struct bem *ptr) {
	printf("%s %s is a %d-limbed %s\n", ptr->title.first, ptr->title.last,ptr->limbs,ptr->type);
}

int struct_review_7(void) {
	struct bem Bem={
		6,
		{"Berbnazel","Gwolkapwolk"},
		"Arcturan"
	};
	show_bem(&Bem);
}

int struct_review_9(void){
	struct car {
		char car_name[size];
		double horsepower;
		double EPA;
		double wheelbase;
		int years;
	}Car;
}

struct gas {
	float distance;
	float gals;
	float mpg;
}Gas;

int struct_gets_value(struct gas *ptr) {
	int mpg;
	mpg = ptr->distance / ptr->gals;
	return mpg;
}

int struct_review_10_a(void) {
	struct gas *ptr;
	Gas.distance = 30.3;
	Gas.gals = 23.3;
	Gas.mpg = 0.0;
	Gas.mpg=struct_gets_value(&Gas);
	printf("Mpg is %f\n", Gas.mpg);
}

int struct_gets(struct gas* ptr) {
	ptr->mpg = ptr->distance / ptr->gals;
	return ptr;
}

int struct_review_10_b(void) {
	struct gas* ptr;
	Gas.distance = 30.3;
	Gas.gals = 23.3;
	Gas.mpg = 0.0;
	ptr = struct_gets(&Gas);
	printf("Mpg is %f\n", ptr->mpg);
}

int struct_review_11(void) {
	enum choices { no = 0, yes = 1, maybe = 2 };
}

int struct_review_12(void) {
	/*
	char* (*ptr)(char*, char);
	*/
}

int struct_review_13(void) {
	/*
	double func_1(double,double);
	double func_2(double,double);
	double func_3(double,double);
	double func_4(double,double);
	char (*ptr[4])(double,double);
	ptr[0] =func_1;
	ptr[1] = func_2;
	ptr[2] = func_3;
	ptr[3] = func_4;
	ptr[1](10.0, 2.5);
	(*ptr[1])(10.0, 2.5);
	*/
}

static struct month_name* struct_month_read_data(void) {
	int  i = 0;
	struct month_name* ptr;
	ptr = years;
	for (i = 0; i < 12; i++) {
		strcpy((ptr + i)->m_names, month_names[i]);
		strcpy((ptr + i)->m_abbrevations, month_abbrevations[i]);
		(ptr + i)->m_days = month_days[i];
		(ptr + i)->m_numbers = month_numbers[i];
	}
	return ptr;
}
int added_days(const struct month_name* ptr, int i) {
	int sum = 0;
	while (i >= 0) {
		sum += (ptr + i)->m_days;
		i--;
	}
	return sum;
}
int return_days_month(const char* ptr) {
	int i = 0;
	struct month_name* ptr1;
	ptr1 = struct_month_read_data();
	while (1) {
		if (!strcmp(ptr, (ptr1 + i)->m_names) && i != 13) {
			printf("查询月份找到,统计到该月的月份天数总共为%d\n", (added_days(ptr1, i)));
			break;
		}
		else {
			i++;
		}
	}
}

int struct_classwork_1(void) {
	char ch[40] = "";
	printf("请输入一个月份的拼写:");
	scanf("%s", ch);
	return_days_month(ch);
}

int return_gets_days() {

}

int struct_classwork_2(void) {
	char ch[40] = "";
	printf("请输入一个月份的拼写:");
	scanf("%s", ch);
	return_days_month(ch);
}

char* s_gets_Tree_n(char* str, int n) {
	char* ret_val;
	char* find;
	ret_val = fgets(str, n, stdin);
	if (ret_val) {
		find = strchr(str, n, stdin);
		if (find) {
			*find = '\0';
		}
		else {
			while (getchar() != '\n') {
				continue;
			}
		}
	}
	return ret_val;
}

int show_sort(struct book *ptr,int count) {
	printf("正常输出:\n");
	for (int i = 0; i < count; i++) {
		printf("title was:%s\n", (ptr+i)->title);
		printf("author was:%s\n", (ptr+i)->author);
		printf("value was:%0.2f\n", (ptr+i)->value);
		printf("id was:%d\n", (ptr+i)->id);
	}
	return 0;

}

int show_word(struct book* ptr, int count) {
	struct book cpy;
	printf("标题排序输出:\n");
	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {
			if ((ptr + i)->title[0] > (ptr + j)->title[0]) {
				cpy = *(ptr + i);
				*(ptr + i) = *(ptr + j);
				*(ptr + j) = cpy;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		printf("title was:%s\n", (ptr + i)->title);
		printf("author was:%s\n", (ptr + i)->author);
		printf("value was:%0.2f\n", (ptr + i)->value);
		printf("id was:%d\n", (ptr + i)->id);
	}
	return 0;
}

int show_ascending_order(struct book* ptr, int count) {
	struct book cpy;
	printf("价格排序输出:\n");
	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {
			if ((ptr + i)->value > (ptr + j)->value) {
				cpy = *(ptr + i);
				*(ptr + i) = *(ptr + j);
				*(ptr + j) = cpy;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		printf("title was:%s\n", (ptr + i)->title);
		printf("author was:%s\n", (ptr + i)->author);
		printf("value was:%0.2f\n", (ptr + i)->value);
		printf("id was:%d\n", (ptr + i)->id);
	}
	return 0;
}

int manybook(void) {
	struct book library[MaxBks];
	int count = 0;
	int index;
	int id = 0;
	printf("please enter the book title.\n");
	printf("press [enter] at the start of a line to stop\n");
	while (count < MaxBks && s_gets_Tree(library[count].title, MaxTitle) != NULL && library[count].title[0] != '\0') {
		printf("Now enter the author.\n");
		s_gets_Tree(library[count].author, MaxAutle);
		printf("Now enter the value.\n");
		scanf("%f", &library[count].value);
		library[count].id = id++;
		while (getchar() != '\n') {
			continue;
		}
		if (count < MaxBks) {
			printf("Enter the next title.\n");
		}
		count++;
	}
	if (count > 0) {
		printf("here is the list of your books:\n");
		for (index = 0; index < count; index++) {
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
		}
	}
	else {
		printf("No books?too bad.\n");
	}
	show_sort(&library,count);
	show_word(&library, count);
	show_ascending_order(&library, count);
	return 0;
}


int struct_classwork_3(void) {
	manybook();
}


int show_social_insurance(struct social_insurance *ptr) {
	if ((ptr+0)->Name.mname[0]!='\0') {
		printf("%s,%s %c.----%d\n", (ptr+0)->Name.fname, (ptr+0)->Name.lname, (ptr + 0)->Name.mname[0], (ptr+0)->s_number);
	}
	else {
		printf("%s,%s----%d\n", (ptr+0)->Name.fname, (ptr+0)->Name.lname,(ptr+0)->s_number);
	}
	return 0;
}
int struct_classwork_4_a(void) {
	strcpy(s_data[0].Name.mname,"ab");
	strcpy(s_data[0].Name.fname,"ab");
	strcpy(s_data[0].Name.lname,"ab");
	show_social_insurance(&s_data);
	strcpy(s_data[0].Name.mname, "");
	strcpy(s_data[0].Name.fname, "ab");
	strcpy(s_data[0].Name.lname, "ab");
	show_social_insurance(s_data);
}

int struct_classwork_4_b(void) {
	struct social_insurance* ptr;
	ptr = &s_data;
	strcpy((ptr+  0)->Name.mname, "ab");
	strcpy((ptr + 0)->Name.fname, "ab");
	strcpy((ptr + 0)->Name.lname, "ab");
	show_social_insurance(ptr);
	strcpy((ptr + 0)->Name.mname, "");
	strcpy((ptr + 0)->Name.fname, "ab");
	strcpy((ptr + 0)->Name.lname, "ab");
	show_social_insurance(ptr);
}

int gets_input(struct students *ptr,int Size) {
	int i = 0;
	int id = 0;
	printf("请输入学生的姓名:(输入q退出):");
	while (i!=Size) {
		scanf("%s", (ptr + i)->Name.first);
		if (!strcmp(&(ptr + i)->Name.first,"q")) {
			break;
		}
		scanf("%s", (ptr + i)->Name.last);
		printf("请输入学生的语文成绩:");
		scanf("%f", &(ptr + i)->Grade.language_score);
		printf("请输入学生的数学成绩:");
		scanf("%f", &(ptr + i)->Grade.math_score);
		printf("请输入学生的科学成绩:");
		scanf("%f", &(ptr + i)->Grade.scient_score);
		i++;
		id++;
		printf("请输入学生的姓名:(输入q退出):");
	}
	return id;
}

int calculate_studens_average_score(struct students* ptr, int Size) {
	int i = 0;
	float sum=0.0;
	while (i < Size) {
		sum+=(ptr + i)->Grade.language_score;
		sum += (ptr + i)->Grade.math_score;
		sum += (ptr + i)->Grade.scient_score;
		(ptr + i)->Average=sum/3;
		sum = 0.0;
		i++;
	}
	return 0;
}

int show_score(struct students* ptr, int Size) {
	int i = 0;
	int j = 1;
	while (i < Size) {
		printf("第%d位的学生姓名为:%s - %s\n",j, (ptr + i)->Name.first, (ptr + i)->Name.last);
		printf("语文成绩为:%f 数学成绩为:%f  科学成绩为:%f\n", (ptr + i)->Grade.language_score, (ptr + i)->Grade.math_score, (ptr + i)->Grade.scient_score);
		printf("各科平均分为:%f\n", (ptr + i)->Average);
		i++;
		j++;
	}
}

int output_class_score(struct students* ptr, int Size) {
	int i = 0;
	float class_average=0.0;
	while (i < Size) {
		class_average += (ptr + i)->Average;
		i++;
	}
	printf("这个班的各科平均成绩为%f\n", class_average/i);
}

int struct_classwork_5(void) {
	int id = 0;
	struct students  Students[CSIZE];
	id=gets_input(&Students, CSIZE);
	calculate_studens_average_score(&Students, id);
	show_score(&Students, id);
	output_class_score(&Students, id);
	printf("程序结束.\n");
}


struct airplane {
	int seat_num;
	char isassignment[4];
	struct name Name;
};

struct airplane* resets(struct airplane *Airplane_seats) { 
	int j = 0;
	for (int i = 1; i < 13; i++) {
		Airplane_seats[j].seat_num = i;
		strcpy(Airplane_seats[j].isassignment,"no");
		strcpy(Airplane_seats[j].Name.first, " ");
		strcpy(Airplane_seats[j].Name.last, " ");
		j++;
	}
	return Airplane_seats;
}

int show_empty_seats_number(struct airplane* ptr) {
	int count=0;
	int i=0;
	while (i < Seats_n) {
		if (strcmp((ptr + i)->isassignment,"no")) {
			i++;
			continue;
		}
		else {
			count++;
		}
		i++;
	}
	printf("\nthere was %d empty seats\n", count);
}

int show_empty_seats_list(struct airplane* ptr) {
	int i = 0;
	printf("\nthis is empty list:\n");
	while (i < Seats_n) {
		if (strcmp((ptr + i)->isassignment,"no")) {
			i++;
			continue;
		}
		else {
			printf("Seats number:%d Assignment:%s\n", (ptr + i)->seat_num, (ptr + i)->isassignment);
		}
		i++;
	}
	printf("\n");
	return 0;
}

int show_alphabetical_seats_list(const struct airplane* ptr) {
	for (int i = 0; i < 11;i++) {
		printf("Seat Number:%d\n", (ptr + i)->seat_num);
		printf("Name:%s-%s\n", (ptr + i)->Name.first, (ptr + i)->Name.last);
		printf("Assignment:%s\n", (ptr + i)->isassignment);
	}
}

int assign_a_seat(struct airplane* ptr) {
	int flag = 1;
	int i = 0;
	char iscontinue=' ';
	int assign_seatsnum=0;
	while (flag) {
		printf("Enter the seat number you want to choose:");
		scanf("%d", &assign_seatsnum);
		if (assign_seatsnum > 12 || assign_seatsnum < 1) {
			printf("we just have 12 seats.\n");
			goto Status;
		}
		if (strcmp(&(ptr + (assign_seatsnum - 1))->isassignment, "yes")) {
			printf("Enter you first name and last name (use space between first and last):");
			scanf("%s %s", (ptr + (assign_seatsnum - 1))->Name.first, (ptr + (assign_seatsnum - 1))->Name.last);
			strcpy((ptr + (assign_seatsnum - 1))->isassignment, "yes");
			printf("done.\n");
		}
		else {
			printf("this seat was assignment by:%s-%s.\n", (ptr + (assign_seatsnum - 1))->Name.first, (ptr + (assign_seatsnum - 1))->Name.last);
		}
	Status:;
		while (getchar() != '\n') {
			continue;
		}
		printf("assgin continue?(y/n):");
		scanf("%c", &iscontinue);
		if (iscontinue != 'y'&& iscontinue != 'n') {
			printf("pls enter y/n.\n");
			goto Status;
		}
		else if(iscontinue == 'y') {
			continue;
		}
		else {
			flag = 0;
		}
	}
	while (getchar() != '\n') {
		continue;
	}
	printf("\n\n");
	return 0;
}

int delete_a_assignment (struct airplane* ptr){
	int i = 0;
	int flag = 1;
	char iscontinue = ' ';
	int delete_seatsnum=0;
	while (flag) {
		printf("Enter the seat number you want to delete:");
		scanf("%d", &delete_seatsnum);
		if (!strcmp((ptr + (delete_seatsnum - 1))->isassignment, "yes")) {
			strcpy((ptr + (delete_seatsnum - 1))->isassignment, "no");
			strcpy((ptr + (delete_seatsnum - 1))->Name.first, " ");
			strcpy((ptr + (delete_seatsnum - 1))->Name.last, " ");
			printf("done.\n");
		}
		else {
			printf("no need,there was empty.\n");
		}
	Status:;
		while (getchar() != '\n') {
			continue;
		}
		printf("delete continue?(y/n):");
		scanf("%c", &iscontinue);
		if (iscontinue != 'y' && iscontinue != 'n') {
			printf("pls enter y/n.\n");
			goto Status;
		}
		else if (iscontinue == 'y') {
			continue;
		}
		else {
			flag = 0;
		}
	}
	printf("\n\n");
	while (getchar() != '\n') {
		continue;
	}
	return 0;
}
void choose_func(struct airplane*, char);

int airplane_menu(struct airplane* ptr) {
	char choose=' ';
	printf("To choose a function,enter its letter label\n");
	printf("a) show number of empty seats\n");
	printf("b) show list of empty seats\n");
	printf("c) show alphabetical list of seats\n");
	printf("d) assign a customer to a seat assignment\n");
	printf("e) delete a seat assginment\n");
	printf("f) quit\n");
	printf("enter your choose:");
	scanf("%c", &choose);
	choose_func(ptr, choose);
}

void choose_func(struct airplane* ptr, char choose) {
	while (getchar() != '\n') {
		continue;
	}
	switch (choose) {
	case 'a':show_empty_seats_number(ptr), airplane_menu(ptr); break;
	case 'b':show_empty_seats_list(ptr),airplane_menu(ptr); break;
	case 'c':show_alphabetical_seats_list(ptr),airplane_menu(ptr); break;
	case 'd':assign_a_seat(ptr),airplane_menu(ptr); break;
	case 'e':delete_a_assignment(ptr),airplane_menu(ptr); break;
	case 'f':printf("Bye!"); break;
	default:printf("please enter vaild letter\n"), airplane_menu(ptr);
	}
}

int struct_classwork_8(void) {
	struct airplane Airplane_seats[Seats_n];
	struct airplane* ptr;
	ptr=resets(Airplane_seats);
	airplane_menu(ptr);
}


int airplane_menu_n(struct airplane* ptr, int flight_num) {
	char choose = ' ';
	printf("This is the flight number you chose %d\n",flight_num);
	printf("To choose a function,enter its letter label\n");
	printf("a) show number of empty seats\n");
	printf("b) show list of empty seats\n");
	printf("c) show alphabetical list of seats\n");
	printf("d) assign a customer to a seat assignment\n");
	printf("e) delete a seat assginment\n");
	printf("f) quit\n");
	printf("enter your choose:");
	scanf("%c", &choose);
	choose_func(ptr, choose);
}

struct another_airplane {
	int flight_number;
	struct airplane Airplane[Seats_n];
};

int show_another_airplane(struct another_airplane* ptr) {
	int flag = 0;
	int i=0;
	int choose=0;
	printf("\nhere is a fight number lists(enter 0 to exit):\n");
	while (i<4) {
		printf("%d ", (ptr + i)->flight_number);
		i++;
	}
	printf("\n");
	printf("\nwhich your choose:");
	scanf("%d", &choose);
	return choose;
}
int another_airplane_menu(struct another_airplane* another_ptr) {
	int choose=0;
	int i = 0;
	choose=show_another_airplane(another_ptr);
	if (choose) {
		while (i < 4) {
			if ((another_ptr + i)->flight_number == choose) {
				break;
			}
			i++;
		}
		while (getchar() != '\n') {
			continue;
		}
		switch (choose) {
		case 102:airplane_menu_n((another_ptr + i)->Airplane, (another_ptr + i)->flight_number)
			,another_airplane_menu(another_ptr); break;
		case 311:airplane_menu_n((another_ptr + i)->Airplane, (another_ptr + i)->flight_number)
			, another_airplane_menu(another_ptr); break;
		case 444:airplane_menu_n((another_ptr + i)->Airplane, (another_ptr + i)->flight_number)
			, another_airplane_menu(another_ptr); break;
		case 519:airplane_menu_n((another_ptr + i)->Airplane, (another_ptr + i)->flight_number)
			, another_airplane_menu(another_ptr); break;
		default:printf("please enter vaild data"), another_airplane_menu(another_ptr);
		}
	}
	else {
		printf("Bye!\n");
	}
}

struct another_airplane* another_resets(struct another_airplane* another_ptr){
	int j = 0;
	int i = 0;
	int flag = 1;
	struct airplane* ptr;
	int fight_num[4] = { 102,311,444,519 };
	for (int z = 0; z < 4; z++) {
		(another_ptr + z)->flight_number = fight_num[z];
	}
	while (flag) {
		if (i < 4) {
			ptr = (another_ptr + i)->Airplane;
			resets(ptr);
			i++;
		}
		else {
			flag = 0;
		}
	}
	ptr = NULL;
	return another_ptr;
}
int struct_classwork_9(void) {
	struct another_airplane another_Airplane[4];
	struct another_airplane* ptr;
	ptr = another_resets(another_Airplane);
	another_airplane_menu(ptr);
}

