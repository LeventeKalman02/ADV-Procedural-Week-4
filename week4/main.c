#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	long bookNum;
	char title[30];
	char author[25];
	double price;
}bookT;

void mainMenu(bookT* bookDetails, int size, int menuOpt, int numOfBooks);
void addBook(bookT* bookDetails, int size);
void displayBook(bookT* bookDetails, int size);
void searchBook(bookT* bookDetails, int size);
void editBook(bookT* bookDetails, int size);

void main() {
	int numOfBooks;
	bookT* library;
	int init;

	mainMenu(library, numOfBooks);

	//initialising the library
	for (int i = 0; i < numOfBooks; i++) {
		(library + i)->bookNum = 0;
		strcpy((library + i)->title, "");
		strcpy((library + i)->author, "");
		(library + i)->price = 0;
	}

	/*printf("Please enter the number of books in the list\n");
	scanf("%d", &numOfBooks);*/


	library = (bookT*)malloc(numOfBooks * sizeof(bookT));

	
	//calling functions
	displayBook(library, numOfBooks);

}

void mainMenu(bookT* bookDetails, int size, int menuOpt, int numOfBooks) {


	//menu loop 
	while ( menuOpt =! -1) {
		printf("Please enter 1 to search a book, 2 to add a book, 3 to edit a book or -1 to Exit: ");
		scanf("%d", &menuOpt);

		if (menuOpt == 1) {
			searchBook(bookDetails, numOfBooks);
		}
		else if (menuOpt == 2) {
			addBook(bookDetails, numOfBooks);
		}
		else if (menuOpt == 3) {
			editBook(bookDetails, numOfBooks);
		}
		else {
			printf("The number you have entered is invalid, please enter a correct option!\n");
			menuOpt = 0;
		}

		printf("Please enter 1 to search a book, 2 to add a book, 3 to edit a book or -1 to Exit: ");
}

void addBook(bookT* bookDetails, int size) {

	for (int i = 0; i < size; i++) {
		
	}
}

void displayBook(bookT* bookDetails, int size) {

}

void searchBook(bookT* bookDetails, int size) {

}

void editBook(bookT* bookDetials, int size) {

}