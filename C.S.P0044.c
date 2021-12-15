#include <stdio.h>
#include <string.h>
#include <ctype.h>

int len = 0; //length
int input(){
	int n;
	char c;
	while (1){
		scanf("%d%c", &n, &c);
		fflush(stdin);
		if (n > 0 && c == '\n')
			break;
		else
			printf("Enter an integer: ");
	}
	return n;
}
//Only 1 element can be added at a time
int add(int arr[]){
	printf("\nEnter new value [%d]= ", len + 1);
	arr[len] = input();
	len++;
}
//Search position
int search(int arr[]){
	int index[50], found=0, j = 0; 
	int i, pos2;//pos 2: pos need search
	printf("Enter the pos you want to find: ");
	scanf("%d", &pos2);
	for (i = 0; i < len; i++){
		//Neu pos2 trung 1 phan tu trong mang
		if (arr[i] == pos2){
			index[j] = i; //luu vi tri trung vao mang moi
			j++;		  //dem so phan tu trung
			found = 1;	  //tim thay
		}
	}
	if (j > 0){
		for (i = 0; i < j; i++){
			printf("\nPosition  = %d", index[i]);
		}
	}
	if (found == 0){
		printf("Not exist");
	}
}
//Output array
int output(int arr[]){
	int i;
	for (i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	if (len == 0){
		printf("No information");
	}
}
//Sort Ascending Array
void ascendingArray(int arr[]){
	int temp, i, j;
	for (i = 0; i < len - 1; i++){
		for (j = i + 1; j < len; j++){
			if (arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void printOutInRange(int arr[]){
	int i, min, max;
	printf("Enter min: ");
	scanf("%d", &min);
	printf("Enter max: ");
	scanf("%d", &max);
	for (i = 0; i < len; i++){
		if (arr[i] > min && arr[i] < max){
			printf("%d ", arr[i]);
		}
	}
}
int main(){
	int choice;
	int arr[50];
	while (1){
		printf("\n--------Menu--------\n");
		printf("1- Add a value\n");
		printf("2- Search a value\n");
		printf("3- Print out the array\n");
		printf("4- Print out values in a range of inputted min and max values, inclusively.\n");
		printf("5- Sort the array in ascending order \n");
		printf("Others- Quit\n");

		printf("Your chose 1-->5: ");
		choice = input();
		switch (choice){
		case 1:
			add(arr);
			break;
		case 2:
			search(arr);
			break;
		case 3:
			output(arr);
			break;
		case 4:
			printOutInRange(arr);
			break;
		case 5:
			ascendingArray(arr);
			output(arr);
			break;
		}
	}
	return 0;
}
