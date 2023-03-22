#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	long bookNum;
	char title[30];
	char author[25];
	double price;
}bookT;

FILE* books;
FILE* passW;

void adminMenu(bookT* bookDetails, int size);
void addBook(bookT* bookDetails, int size);
void searchBook(bookT* bookDetails, int size);
void editBook(bookT* bookDetails, int size);
void readFile(bookT* bookDetails, int size);
void saveFile(bookT* bookDetails, int size);

void main() {
	bookT* library;
	int numOfBooks = 0;
	int login;	

	library = (bookT*)malloc(numOfBooks * sizeof(bookT));

	//initialising the library
	for (int i = 0; i < numOfBooks; i++) {
		(library + i)->bookNum = 0;
		strcpy((library + i)->title, "");
		strcpy((library + i)->author, "");
		(library + i)->price = 0;
	}

	//ask for the user status
	printf("Would you like to login as either (1) Admin or (2)Guest?: \n");
	scanf("%d", &login);

	//login screen 
	while (login != -1) {
		if (login == 1) {
			passW = fopen("login.txt", "r");
			char buff[100];
			fgets(buff, 100, passW);
			printf("String reads: %s\n", buff);


			if (passW == NULL) {
				printf("Cannot open file");
			}
			else {
				char pass[100] = "";
				printf("Please enter the password:\n");
				scanf("%s", pass);

				if (!strcmp(buff, pass)) {
					printf("You have entered the correct password!\n\n");

					printf("Please enter the number of books you would like to have:\n");
					scanf("%d", &numOfBooks);
					adminMenu(library, numOfBooks);
				}

				

			}
			fclose(passW);

		}
		else if (login == 2) {
			printf("You are logged in as a guest.\n");
		}
		else {
			printf("Invalid Entry!\n");
			login = 0;
		}
		return;
	}			
}

//save the file
void saveFile(bookT* bookDetails, int size) {
	books = fopen("bookDB.txt", "a");

}

void readFile(bookT* bookDetails, int size) {
	books = fopen("bookDB.txt", "r");

	if (books == NULL) {
		printf("Cannot open file");
	}
	else {
		while (!feof(books)) {
			int numInputs = fscanf(books, "%ld %s %s %f", bookDetails->bookNum, &bookDetails->title, &bookDetails->author, &bookDetails->price);
			if (numInputs == numInputs)
			{
				printf("\nBook Number: %ld\nTitle: %s\nAuthor: %s\nHourly Price: %.2f\n",
					bookDetails->bookNum, bookDetails->title, bookDetails->author, bookDetails->price);
			}
		}
		fclose(books);
	}
}

void adminMenu(bookT* bookDetails, int size) {

	int menuOpt = 0;

	//menu loop 
	while (menuOpt != -1) {
		printf("\nPlease enter 1 to search a book, 2 to add a book, 3 to edit a book, 4 to Save current books or -1 to Exit: \n");
		scanf("%d", &menuOpt);

		if (menuOpt == 1) {
			searchBook(bookDetails, size);
		}
		else if (menuOpt == 2) {
			addBook(bookDetails, size);
		}
		else if (menuOpt == 3) {
			editBook(bookDetails, size);
		}
		else if (menuOpt == 4) {
			readFile(bookDetails, size);
		}
		else {
			printf("The number you have entered is invalid, please enter a correct option!\n");
			menuOpt = 0;
		}

		/*printf("\nPlease enter 1 to search a book, 2 to add a book, 3 to edit a book or -1 to Exit: ");
		scanf("%d", &menuOpt);*/
	}
}

void addBook(bookT* bookDetails, int size) {
	int addBook;
	for (int i = 0; i < size; i++) {
		if ((bookDetails + i)->bookNum == 0) {
			printf("Please enter the book number:\n");
			scanf("%ld", &(bookDetails + i)->bookNum);

			printf("Please enter the book name:\n");
			scanf("%s", (bookDetails + i)->title);

			printf("Please enter the book author:\n");
			scanf("%s", (bookDetails + i)->author);

			printf("Please enter the price:\n");
			scanf("%f", &(bookDetails + i)->price);
			addBook = 1;
			break;
		}

		// give error if library is full
		if (addBook == 0) {
			printf("Sorry the library is full\n");
		}
	}
}

void searchBook(bookT* bookDetails, int size) {
	long findBooknum;
	int foundBook = 0;

	printf("Please enter the book number of the book that you want to find:\n");
	scanf("%ld", &findBooknum);

	for (int i = 0; i < size; i++)
	{
		if ((bookDetails + i)->bookNum == findBooknum) {
			printf("Book title: %s\n", (bookDetails + i)->title);
			printf("Book author: %s\n", (bookDetails + i)->author);
			printf("Book price: %.2f\n", (bookDetails + i)->price);

			foundBook = 1;
			break;
		}
	}

	if (foundBook == 0) {
		printf("The book number %ld could not be found!\n", findBooknum);
	}
}

void editBook(bookT* bookDetails, int size) {
	long findBook;
	int found = 0;

	printf("\nPlease enter the book number of the book that you want to edit:\n");
	scanf("%ld", &findBook);

	for (int i = 0; i < size; i++)
	{
		if ((bookDetails + i)-> bookNum == findBook) {
			printf("Please enter the new book number you want for the book\n");
			scanf("%d", &(bookDetails + i)->bookNum);
			printf("Please enter the new title you want for the book\n");
			scanf("%s", &(bookDetails + i)->title);
			printf("Please enter the new author you want for the book\n");
			scanf("%s", &(bookDetails + i)->author);
			printf("Please enter the new price you want for the book\n");
			scanf("%lf",&(bookDetails + i)->price);
			
			found = 1;
			break;
		}
	}

	if (found == 0) {
		printf("The book number could not be found!\n");
	}
}