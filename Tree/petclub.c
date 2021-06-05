#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "Tree.h"

char Tree_Menu(void);
void addpet(Tree* pt);
void droppet(Tree* pt);
void showpet(const Tree* pt);
void findpet(const Tree* pt);
void printitem(Item item);
void uppercase(char* str);
char* s_gets_Tree(char* st, int n);

int Tree_main(void) {
	Tree pets;
	char choice;
	InitializeTree(&pets);
	while ((choice = Tree_Menu()) != 'q') {
		switch (choice) {
		case 'a':addpet(&pets); break;
		case 'l':showpet(&pets); break;
		case 'f':findpet(&pets); break;
		case 'n':printf("%d pets in club\n",TreeItemCount(&pets)); break;
		case 'd':droppet(&pets); break;
		default:puts("Switching error");
		}
	}
	Traverse_TREE(&pets);
	DeleteAll(&pets);
	puts("Bye.");
	return 0;
}

char Tree_Menu(void) {
	char ch;
	puts("Nerfville pet club Membershipp program");
	puts("Enter the letter corresponding to your choice");
	puts("a) add a pet \t l)show list of pets");
	puts("n) number of pets\t f)find pets");
	puts("d) delete a pet \t q)quit");
	while ((ch = getchar()) != EOF) {
		while (getchar() != '\n') {
			continue;
		}
		ch = tolower(ch);
		if (strchr("alrrfndq", ch) != NULL) {
			break;
		}
		else {
			puts("Please enter an a,l,f,n,d or q:");
		}
	}
	if (ch == EOF) {
		ch = 'q';
	}
	return ch;
}

void addpet(Tree* pt) {
	Item temp;
	if (TreeIsFull(pt)) {
		puts("No room in the club");
	}
	else {
		puts("Please enter name of pet:");
		s_gets_Tree(temp.petname, SLEN);
		puts("Please enter pet kind:");
		s_gets_Tree(temp.petkind, SLEN);
		uppercase(temp.petname);
		uppercase(temp.petkind);
		Tree_AddItem(&temp, pt);
	}
}

void showpet(const Tree* pt) {
	if (TreeIsEmpty(pt)) {
		puts("No entries!");
	}
	else {
		Tree_Traverse(pt, printitem);
	}
}

void printitem(Item item) {
	printf("Pet:%-19s Kind:%-19s\n", item.petname, item.petkind);
}
void findpet(const Tree* pt) {
	Item temp;
	if (TreeIsEmpty(pt)) {
		puts("No entries!");
		return;
	}
	puts("Please enter name of pet you wish to find:");
	s_gets_Tree(temp.petname, SLEN);
	puts("Please enter pet kind:");
	s_gets_Tree(temp.petkind, SLEN);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("%s the %s,", temp.petname, temp.petkind);
	if (InTree(&temp, pt)) {
		printf("is a member.\n");
	}
	else {
		printf("is not a member.\n");
	}
}

void droppet(Tree* pt) {
	Item temp;
	if (TreeIsEmpty(pt)) {
		puts("No entries:");
		return;
	}
	puts("Please enter name of pet you wish to delete:");
	s_gets_Tree(temp.petname, SLEN);
	puts("Please enter pet kind:");
	s_gets_Tree(temp.petkind, SLEN);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("%s the %s,", temp.petname, temp.petkind);
	if (DeleteItem(&temp, pt)) {
		printf("is dropped from the club.\n");
	}
	else {
		printf("is not a member.\n");
	}
}

void uppercase(char* str) {
	while (*str) {
		*str = toupper(*str);
		str++;
	}
}


char* s_gets_Tree(char* str, int n) {
	char* ret_val;
	char* find;
	ret_val = fgets(str, n, stdin);
	if (ret_val) {
		find = strchr(str, '\n');
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