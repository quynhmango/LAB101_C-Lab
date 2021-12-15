//Swap element
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
int checkInput(char*Msg, int Min, int Max) {
	int number, check;
	char ch;
	do {
		printf("%s", Msg);
		fflush(stdin);
		check = scanf("%d%c", &number, &ch);
		if (check==2 && ch=='\n'){
			if (number >= Min && number <= Max) break;
			else printf("Out of range, please enter %d-%d\n", Min, Max);
		} else printf("Invalid input, Please enter an integer number\n");
	}while(1);
	return number;
}


int main(){
	//Enter size of array 
	int size = checkInput("Enter the size of an array: ", 1, INT_MAX);
	int i, a[size];
	
	//Print out array
	printf("\nThe original array: \n");
	srand(time(NULL));
	for (i=0; i<size; i++){
		a[i] = rand()%100;
		printf("%d ",a[i]);
	}
	
	//swap
	printf("\nSwap two elements:\n");
	int m = checkInput("", 0, size);
	int n = checkInput("",0, size);
	
	//If position duplicate
	if(m==n){
		printf("Duplicate");
		
	}else{
		a[m-1] = a[m-1] + a[n-1];//a=a+b
		a[n-1] = a[m-1] - a[n-1];//b=a-b
		a[m-1] = a[m-1] - a[n-1];//a=a-b
	}

	//Array after swapping
	printf("\nArray after swapping:\n");
	for (i=0;i<size;i++){
		printf("%d ", a[i]);
	}
	return 0;	
}

