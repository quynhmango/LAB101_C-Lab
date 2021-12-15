#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

int checkInput(char*Msg, int Min, int Max){
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
void checkLetter(int n);
int main(){
	//Enter the size of the array
	int n = checkInput("Please enter size of array: ", 1, INT_MAX);
	int i, a[n];
	
	//Generate random elements in array
	srand(time(NULL));
	printf("New array: \n");
	for (i=0;i<n;i++){
		a[i] =rand()%123;
		printf("[%d]: %d\n",i,a[i]);
	}
	
	//Find letters corresponding to the integer equivalent of letters
	printf("\nFind letters corresponding to the integer equivalent of letter\n");
	for(i=0; i<n;i++){
		printf("Element [%d]: ",i);
		checkLetter(a[i]);
	}
} 

void checkLetter(int n){
	if (n >=65 && n<=90 || n>=97 && n <=122){
			printf("%c\n", n);
		} else printf ("%d\n",n);
}
