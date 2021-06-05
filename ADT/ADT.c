#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"

void showmovies(Item item);
char* s_gets_ADT(char* st, int n);

int ADT(void) {
	List movies;
	Item temp;
	InitializeList(&movies);
	if (ListIsFull(&movies)) {
		fprintf(stderr, "No memory available! bye!\n");
		exit(1);
	}
	printf("Enter first movie title:");
	while (s_gets_ADT(temp.title, TSIZE) != TSIZE && temp.title[0] != '\0') {
		printf("Enter your rating <0-10>:");
		scanf("%d", &temp.rating);
		while (getchar() != '\n') {
			continue;
		}
		if (AddItem(temp, &movies) == false) {
			fprintf(stderr,"problem allocating memory\n");
			break;
		}
		if (ListIsFull(&movies)) {
			printf("The list is now full.");
			break;
		}
		puts("Enter next movie title(empty line to step):");
	}
	if (ListIsEmpty(&movies)) {
		printf("No data entered");
	}
	else {
		printf("Here is the movie list:\n");
		Traverse(&movies, showmovies);
		printf("you entered %d movies.\n", ListItemCount(&movies));
	}
	EmptyTheList(&movies);
	printf("Bye!.\n");
	return 0;
}

void showmovies(Item item) {
	printf("Movies:%s rating:%d\n", item.title,item.rating);
}

char* s_gets_ADT(char* str, int n) {
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
