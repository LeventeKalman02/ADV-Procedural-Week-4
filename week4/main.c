#include <stdio.h>
#include <stdlib.h>

#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
	char make[40];
	char model[40];
	float engineSize;
}carT;

void readCars(carT* carRegs, int size);
void printCars(carT* carRegs, int size);
void searchCars(carT* carRegs, int size);


void main()
{
	int numberofCar;
	carT* list;

	printf("Please enter the number of cars in the list\n");
	scanf("%d", &numberofCar);

	list = (carT*)malloc(numberofCar * sizeof(carT));

	readCars(list, numberofCar);

	printCars(list, numberofCar);

	searchCars(list, numberofCar);
}


void readCars(carT* carRegs, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("Please enter the car make\n");
		//scanf("%s", (*(carRegs + i)).make);
		scanf("%s", (carRegs + i)->make);

		printf("Please enter the car model\n");
		scanf("%s", (carRegs + i)->model);

		printf("Please enter the car engine size\n");
		scanf("%f", &(carRegs + i)->engineSize);

	}
}

void printCars(carT* carRegs, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%s %s %d\n", (carRegs + i)->make, (carRegs + i)->model, (carRegs + i)->engineSize);
	}
}

void searchCars(carT* carRegs, int size)
{
	int i;

	float searchSize;

	printf("Please enter the engine size you are looking for\n");
	scanf("%f", &searchSize);

	for (i = 0; i < size; i++)
	{
		if (searchSize == (carRegs + i)->engineSize)
		{
			printf("%s %s %d\n", (carRegs + i)->make, (carRegs + i)->model, (carRegs + i)->engineSize);
		}
	}
}