#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	long bookNum;
	char title[30];
	char author[25];
	float price;
}bookT;

void init(bookT* bookDetails, int size);
void adminMenu(bookT* bookDetails, int size);
void guestMenu(bookT* bookDetails, int size);
void addBook(bookT* bookDetails, int size);
void searchBook(bookT* bookDetails, int size);
void editBook(bookT* bookDetails, int size);
void saveBooks(bookT* bookDetails, int size);
bool adminLogin();


void main() {
	FILE* fp;
	bookT* library;
	int numOfBooks;
	int login = 0;


	while (login != 1 && login != 2) {
		//ask for the user status
		printf("Would you like to login as either (1) Admin or (2)Guest?: \n");
		scanf("%d", &login);
	}	
	//loads the program as an Admin user
	if (login == 1) {
		bool valid = adminLogin();

		if (valid == true) {
			int dbChoice = 0;
			printf("Enter 1 to load a previous book DB or Enter 2 to create a new DB\n");
			scanf("%d", &dbChoice);

			//loads the database if choice entered == 1
			if (dbChoice == 1) {
				fp = fopen("bookDB.txt", "r");

				if (fp == NULL) {
					printf("Cannot open file");
				}
				else {
					fscanf(fp, "%d", &numOfBooks);

					library = (bookT*)malloc(numOfBooks * sizeof(bookT));

					for (int i = 0; i < numOfBooks; i++) {						
						fscanf(fp, "%ld %s %s %f", &(library + i)->bookNum, &(library + i)->title, &(library + i)->author, &(library + i)->price);
					}
					fclose(fp);

					adminMenu(library, numOfBooks);
				}
			}
			// creates a new book DB if choice entered == 2
			else if (dbChoice == 2) {
				printf("Please enter the number of books you would like to have:\n");
				scanf("%d", &numOfBooks);

				library = (bookT*)malloc(numOfBooks * sizeof(bookT));

				//initialising the library
				init(library, numOfBooks);

				//calls the admin menu function
				adminMenu(library, numOfBooks);
			}
		}
	}
	//loads the program as a guest user
	else if (login == 2) {
		fp = fopen("bookDB.txt", "r");

		if (fp == NULL) {
			printf("Cannot open file");
		}
		else {
			fscanf(fp, "%d", &numOfBooks);

			library = (bookT*)malloc(numOfBooks * sizeof(bookT));

			for (int i = 0; i < numOfBooks; i++) {						
				fscanf(fp, "%ld %s %s %f", &(library + i)->bookNum, &(library + i)->title, &(library + i)->author, &(library + i)->price);
			}
			fclose(fp);

			guestMenu(library, numOfBooks);
		}
	}
}

//password verification
bool adminLogin() {
	FILE* fp;

	char buff[100];
	char passWord[100] = "";
	int passCheck = 4;

	fp = fopen("login.txt", "r");

	if (fp == NULL) {
		printf("Cannot open file");
		return false;
	}
	else { //compares the string in the file to the entered string to check if the entered password is correct
		fscanf(fp, "%s", buff);

		for (int i = 0; i < passCheck; i++) {
			printf("Please enter the password:\n");
			scanf("%s", passWord);
			if (!strcmp(buff, passWord)) {//checks if what you entered matches the string in the file
				printf("You have entered the correct password!\n\n");
				return true;
			}
			else {
				printf("The password you have entered is incorrect!\n"); //error if incorrect password is entered						
			}

			if (i == 2) {
				printf("\nYou have tried too many times and have been locked out of your account!\n"); //program ends if you enter the wrong password 3 times for the admin login
				break;
			}
		}
		return false;
	}
}

//initialize the library
void init(bookT* bookDetails, int size) {	
	for (int i = 0; i < size; i++) {
		(bookDetails + i)->bookNum = 0;
		strcpy((bookDetails + i)->title, "");
		strcpy((bookDetails + i)->author, "");
		(bookDetails + i)->price = 0;
	}
}

//save the file
void saveBooks(bookT* bookDetails, int size) {
	FILE* fp;

	fp = fopen("bookDB.txt", "w");

	if (fp == NULL) {
		printf("Cannot open file!\n");
	}
	else {
		fprintf(fp, "%d\n", size);

		for (int i = 0; i < size; i++) {
			if ((bookDetails + i)->bookNum != 0) {//populates the file if there is a book in the array 
				fprintf(fp, "%ld %s %s %.2f\n", (bookDetails + i)->bookNum, (bookDetails + i)->title, (bookDetails + i)->author, (bookDetails + i)->price);
			}
			else {//populates the file with "empty" if that index of the array has no book
				fprintf(fp, "%ld %s %s %.2f", (bookDetails + i)->bookNum, "Empty", "Empty", 0.00);
			}
		}
		fclose(fp);
		printf("Your file has been saved!\n");
	}
}

//enters the menu for the admin
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
			saveBooks(bookDetails, size);
		}
		else {
			printf("The number you have entered is invalid, please enter a correct option!\n");
			menuOpt = 0;
		}

		/*printf("\nPlease enter 1 to search a book, 2 to add a book, 3 to edit a book or -1 to Exit: ");
		scanf("%d", &menuOpt);*/
	}
}

//guest menu 
void guestMenu(bookT* bookDetails, int size) {

	int menuOpt = 0;

	//menu loop 
	while (menuOpt != -1) {
		printf("\nPlease enter 1 to search a book, 2 to add a book, 3 to Save current books or -1 to Exit: \n");
		scanf("%d", &menuOpt);

		if (menuOpt == 1) {
			searchBook(bookDetails, size);
		}
		else if (menuOpt == 2) {
			addBook(bookDetails, size);
		}
		else if (menuOpt == 3) {
			saveBooks(bookDetails, size);
		}
		else {
			printf("The number you have entered is invalid, please enter a correct option!\n");
			menuOpt = 0;
		}
	}
}

//adds a book to the array
void addBook(bookT* bookDetails, int size) {
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
			return;
		}
	}
	printf("Sorry the library is full\n");
}

//searches for a book and displays the details based on the book number
void searchBook(bookT* bookDetails, int size) {
	long findBooknum;

	printf("Please enter the book number of the book that you want to find:\n");
	scanf("%ld", &findBooknum);

	for (int i = 0; i < size; i++)
	{
		if ((bookDetails + i)->bookNum == findBooknum) {
			printf("Book Number: %ld\nBook Title: %s\nBook Author: %s\nBook Price: %.2f\n", (bookDetails + i)->bookNum, (bookDetails + i)->title, (bookDetails + i)->author, (bookDetails + i)->price);
			return;
		}
	}
	printf("The book could not be found!\n");
	
}

//allows user to edit a a book based on the book number
void editBook(bookT* bookDetails, int size) {
	long findBook;

	printf("\nPlease enter the book number of the book that you want to edit:\n");
	scanf("%ld", &findBook);

	for (int i = 0; i < size; i++)
	{
		if ((bookDetails + i)->bookNum == findBook) {
			printf("Please enter the new book number you want for the book\n");
			scanf("%ld", &(bookDetails + i)->bookNum);
			printf("Please enter the new title you want for the book\n");
			scanf("%s", &(bookDetails + i)->title);
			printf("Please enter the new author you want for the book\n");
			scanf("%s", &(bookDetails + i)->author);
			printf("Please enter the new price you want for the book\n");
			scanf("%lf", &(bookDetails + i)->price);
			return;
		}
	}
	//throws error if the book number could not be found
	printf("The book number %ld could not be found!\n", findBook);
}