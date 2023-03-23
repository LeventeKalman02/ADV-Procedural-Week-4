////this is for the code of the retard
////Hi im the retard! :D
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//
//typedef struct {
//	long bookNum;
//	char title[30];
//	char author[25];
//	double price;
//}bookT;
//
//FILE* loginFile;
//FILE* libraryFile;
//
//bool login();
//
//bookT* loadLibrary();
//bookT* createLibrary();
//void saveLibrary(bookT* library, int size);
//
//void addBook(bookT* library, int size);
//void displayBook(bookT* library, int size);
//void editBook(bookT* library, int size);
//
//void main() {
//	bookT* library;
//	int librarySize = 0;
//	bool isAdmin = login();
//
//	if(isAdmin){
//		//ask for load or create
//		int loadType = 0;
//		printf("\nEnter 1 to load the library. Enter 2 to create a new library: \n");
//		scanf("%d", &loadType);
//
//		if(loadType == 1){
//			library = loadLibrary();
//		}
//		else if(loadType == 2){
//			library = createLibrary();
//		}
//	}
//	else{
//		library = loadLibrary();
//	}
//	librarySize = sizeof(library);
//	
//	int option = 0;
//	while(option != -1){
//		printf("\nMenu:");
//		printf("\n1: Search book");
//		printf("\n2: Add a book");
//		printf("\n3: Edit a book");
//		if(isAdmin){
//			printf("\n4: Save current library");
//		}
//		printf("\n-1: Exit");
//		scanf("%d", &option);
//
//		if(option == 1){
//			displayBook(library, librarySize);
//		}
//		else if(option == 2){
//			addBook(library, librarySize);
//		}
//		else if(option == 3){
//			editBook(library, librarySize);
//		}
//		else if(option == 4 && isAdmin){
//			saveLibrary(library, librarySize);
//		}
//		else{
//			printf("\n\nUNKNOWN OPTION\n\n");
//		}
//	}
//}
//
//bool login(){
//	int type = 0;
//	while(type == 0){
//		//ask for the user status
//		printf("Would you like to login as either (1) Admin or (2)Guest?: \n");
//		scanf("%d", &type);
//
//		if(type != 1 && type != 2){
//			type = 0;
//		}
//		else{
//			char enteredPassword[20];
//			char savedPassword[20];
//			
//			loginFile = fopen("login.txt", "r");
//
//			if (loginFile == NULL) {
//				return false;
//			} else {
//				fscanf(loginFile, "%s", savedPassword);
//				fclose(loginFile);
//
//				printf("Please enter the password\n");
//				scanf("%s", enteredPassword);
//
//				if (strcmp(enteredPassword, savedPassword) == 0) {
//					return true;
//				} else {
//					return false;
//				}
//			}
//		}
//	}
//}
//
//bookT* loadLibrary(){
//	int numberOfBooks;
//	libraryFile = fopen("booksDB.txt", "r");
//    if (libraryFile == NULL) {
//        printf("Sorry the file could not be open");
//    } else {
//        scanf(libraryFile, "%d", &numberOfBooks);
//        bookT* library = (bookT*) malloc(numberOfBooks * sizeof(bookT));
//
//        for (int i = 0; i < numberOfBooks; i++) {
//			scanf(libraryFile, "%d %s %s %d", & (library + i)->bookNum, (library + i)->title, (library + i)->author, (library + i)->price);
//        }
//
//        fclose(libraryFile);
//        return library;
//    }
//	return (bookT * ) malloc(0 * sizeof(bookT));
//}
//
//bookT* createLibrary(){
//	int numberOfBooks;
//	printf("Please enter the number of books in the database\n");
//    scanf("%d", &numberOfBooks);
//
//    //Dynamic Allocation of the book array
//    bookT* library = (bookT * ) malloc(numberOfBooks * sizeof(bookT));
//
//	for (int i = 0; i < numberOfBooks; i++) {
//		(library + i)->bookNum = 0;
//	}
//
//	return library;
//}
//
//void saveLibrary(bookT* library, int size){
//	libraryFile = fopen("bookDB.txt", "w");
//
//	if (libraryFile == NULL) {
//		printf("Could not save the details to file\n");
//	} else {
//		fprintf(libraryFile, "%d\n", size);
//
//		for (int i = 0; i < size; i++) {
//			if ((library + i) -> bookNum != 0) {
//				fprintf(libraryFile, "%d %s %s %f\n", (library + i) -> bookNum, (library + i) -> title, (library + i) -> author, (library + i) -> price);
//			} else {
//				fprintf(libraryFile, "%d %s %s %f\n", (library + i) -> bookNum, "Empty", "Empty", 0.00);
//			}
//		}
//
//		fclose(libraryFile);
//	}
//}
//
//void addBook(bookT* library, int size){
//	for (int i = 0; i < size; i++) {
//		if ((library + i) -> bookNum == 0) {
//			//Read the element of this book into the empty space
//			printf("Please enter the book number\n");
//			scanf("%d", & (library + i)->bookNum);
//
//			printf("Please enter the book name\n");
//			scanf("%s", (library + i)->title);
//
//			printf("Please enter the book author\n");
//			scanf("%s", (library + i)->author);
//
//			printf("Please enter the book price\n");
//			scanf("%f", & (library + i)->price);
//
//			return;
//		}
//	}
//	printf("Database is full\n");
//}
//
//void displayBook(bookT* library, int size){
//	int searchBookNum;
//
//	printf("Please enter the book number you are looking for\n");
//	scanf("%d", & searchBookNum);
//
//	for (int i = 0; i < size; i++) {
//		if ((library + i) -> bookNum == searchBookNum) {
//			printf("Found the book\n");
//			printf("%d %s %s %f\n", (library + i)->bookNum, (library + i)->title, (library + i)->author, (library + i)->price);
//			return;
//		}
//	}
//	printf("The book was not found in the database\n");
//}
//
//void editBook(bookT* library, int size){
//	int searchBookNum;
//
//	printf("Please enter the book number you are looking to edit\n");
//	scanf("%d", & searchBookNum);
//
//	for (int i = 0; i < size; i++) {
//		if ((library + i) -> bookNum == searchBookNum) {
//			printf("Please enter the book price\n");
//			scanf("%f", & (library + i)->price);
//			return;
//		}
//	}
//
//	printf("The book was not found in the database\n");
//}