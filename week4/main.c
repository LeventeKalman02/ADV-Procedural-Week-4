#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int bookNum = 0;
	char title[30];
	char author[25];
	double price;
}bookT;

void addBook(bookT* bookDetails, int size);
void displayBook(bookT* bookDetails, int size);
void searchBook(bookT* bookDetails, int size);
void editBook(bookT* bookDetails, int size);

void main() {
	int numOfBooks = 0;
	bookT* list;
	int menuOpt = 0;

	/*printf("Please enter the number of books in the list\n");
	scanf("%d", &numOfBooks);*/

	//menu loop 
	while (menuOpt == 0) {
		printf("Please enter 1 to search a book, 2 to add a book, 3 to edit a book or -1 to Exit: ");
		scanf("%d", &menuOpt);

		if (menuOpt == 1) {

		}
		else if (menuOpt == 2) {

		}
		else if (menuOpt == 3) {

		}
		else if (menuOpt == -1) {
			exit;
		}
		else {
			printf("The number you have entered is invalid, please enter a correct option!\n");
			menuOpt = 0;
		}
	}

	list = (bookT*)malloc(numOfBooks * sizeof(bookT));

	
	//calling functions
	addBook(list, numOfBooks);

	displayBook(list, numOfBooks);

	searchBook(list, numOfBooks);

	editBook(list, numOfBooks);
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