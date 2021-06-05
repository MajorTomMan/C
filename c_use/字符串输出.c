#include <stdio.h>
#include<string.h>
#include <ctype.h>
char* s_gets_get(char* str, int n) {
	char* ret_val;
	ret_val = fgets(str, n, stdin);
	if (ret_val) {
		while (*str != '\n' && *str != '\0') 
			str++;
		if (*str == '\n') 
			*str = '\0';
		else 
			while (getchar() != '\n') 
				continue;
	}
	return ret_val;
}

int string_output_review_9(void) {
	char* str;
	char ch[100] = "if i want to be batter then i must to learn more knowleage";
	str=s_gets_get(ch, 100);
	printf("输出内容为:%s\n", str);
}

int strlength(char* str) {
	int i=0;
	while (*str++ != '\0') {
		i++;
	}
	return i;
}

int string_output_review_10(void) {
	int i=0;
	i=strlength("If i dont want to leave my home,i will stay in here on all of my life");
	printf("这句话有%d个字母\n", i);
}

char* s_gets_get_overwritten(char* str, int n) {
	char* ret_val;
	char *find;
	ret_val = fgets(str, n, stdin);
	if (ret_val) {
		find = strchr(str, '\n');
		if (find) {
			*find = '\0';
		}
		else {
			while (getchar() != '\0')
				continue;
		}
	}
	return ret_val;
}

int string_output_review_11(void) {
	char* str;
	str = s_gets_get("if i have much more money then will be batter", 40);
	while (1) {
		printf("输出内容是%c\n", *str++);
		if (*str == '\0') {
			break;
		}
	}
}

char* isSpace(char* str) {
	while (*str) {
		if(*str!=' '){
			str++;
		}
		else {
			return str;
		}
	}
	*str = NULL;
	return str;

}

int string_output_review_12(void) {
	char* str;
	char ch[40] = "sad";
	str = isSpace(ch);
	printf("输出内容为:%d\n", *str);
}

int isequal(char* str1, char* str2) {
	char ch1[40]="";
	char ch2[40]="";
	char* str3, * str4;
	str3 = ch1;
	str4 = ch2;
	while (*str1) {
		if (*str1 >= 'A' && *str1 <= 'Z') {
			*str3 = *str1 + ' ';
			str3++;
			str1++;
		}
		else {
			*str3 = *str1;
			str3++;
			str1++;
		}
	}
	while (*str2) {
		if (*str2 >= 'A' && *str2 <= 'Z') {
			*str4 = *str2+' ';
			str4++;
			str2++;
		}
		else {
			*str4 = *str2;
			str4++;
			str2++;
		}
	}
	if (strcmp(ch1, ch2)) {
		return 1;
	}
	else {
		return 0;
	}
}	

int string_output_review_13(void) {
	if (isequal("yeah so sad", "YEAH SO SAD")) {
		printf("这是两个不同的字符串\n");
	}
	else {
		printf("这是两个相同的字符串\n");
	}
}

void get_input(char* str1) {
	char ch[40]="";
	char* str2;
	str2=ch;
	gets(str1);
	while (*str1) {
		*str2 = *str1;
		str1++;
		str2++;
	}
	str2 = ch;
	printf("数组中的内容为:");
	while (*str2) {
		printf("%c", *str2);
		str2++;
	}
	printf("\n");
}

int string_output_classwork_1(void) {
	char ch[40]="";
	printf("请输入一段话:");
	get_input(ch);
}

void get_input_n(char* str,int n) {
	int i = 0;
	char* ret_val;
	ret_val=fgets(str,n,stdin);
	if (ret_val) {
		while(*ret_val) {
			if (*ret_val == '\n' || *ret_val == '\t' || *ret_val == ' ') {
				*ret_val = '\0';
			}
			else {
				ret_val++;
			}
		}
	}
	printf("数组中的内容为:");
	printf("%s", str);
}

int string_output_classwork_2(void) {
	char ch[40]="";
	printf("请输入一段话:");
	get_input_n(ch, 7);
}

int word_check(char* str) {
	char* str1;
	char* ret_val;
	char ch[10]="";
	int i = 0;
	str1 = ch;
	ret_val = fgets(str, 99, stdin);
	if (ret_val) {
		while (*ret_val==' ') {
			ret_val++;
		}
		while (*ret_val) {
			if (*ret_val != ' '&&*ret_val!= '\n') {
				*str1 = *ret_val;
				str1++;
				ret_val++;
			}
			else {
				*ret_val = '\0';
				break;
			}
		}
	}
	str1 = ch;
	printf("第一个单词是:");
	while (*str1) {
		printf("%c", *str1++);
	}
	printf("\n");
}
int string_output_classwork_3(void) {
	char ch[40] = "";
	printf("请输入一段话:");
	word_check(ch);
}

int word_check_n(char* str,int n) {
	char* str1;
	char* ret_val;
	char ch[10] = "";
	int i = 0;
	str1 = ch;
	ret_val = fgets(str, n, stdin);
	if (ret_val) {
		while (*ret_val == ' ') {
			ret_val++;
		}
		while (*ret_val) {
			if (*ret_val != ' ' && *ret_val != '\n') {
				*str1 = *ret_val;
				str1++;
				ret_val++;
			}
			else {
				*ret_val = '\0';
				break;
			}
		}
	}
	str1 = ch;
	printf("第一个单词是:");
	while (*str1) {
		printf("%c", *str1++);
	}
	printf("\n");
}
int string_output_classwork_4(void) {
	char ch[40] = "";
	printf("请输入一段话:");
	word_check_n(ch,99);
}

char  word_find(char* str, char single_word) {
	char* str1;
	str1 = str;
	while (*str1) {
		if (*str1 == single_word) {
			return str1;
		}
		else {
			str1++;
		}
	}
	str1 = NULL;
	return str1;
}

int string_output_classwork_5(void) {
	char ch[40] = "";
	char* str;
	printf("请输入一段话:");
	gets(ch);
	str=word_find(ch, 'a');
	if (strcmp(str,'a') !=0){
		printf("未找到字符\n");
	}
	else {
		printf("找到字符%c\n", str);
	}
}
