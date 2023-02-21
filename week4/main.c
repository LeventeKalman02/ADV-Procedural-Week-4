#include <stdio.h>
#include <stdlib.h>
typedef struct {
	long bookNum;
	char title[30];
	char author[25];
	double price;
}bookT;

void readBooks(bookT* bookDetails, int size);
void printBooks(bookT* bookDetails, int size);
void searchBooks(bookT* bookDetails, int size);

void main() {
	int numOfBooks;
	bookT* list;

	printf("Please enter the number of books in the list\n");
	scanf("%d", &numOfBooks);

	list = (bookT)*malloc(numOfBooks * sizeof(bookT));
}