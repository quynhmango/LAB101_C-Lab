//Sum Even Odd program
//C.S.P0030
//done
#include<stdio.h>
#include<limits.h>
//Check input
int checkInput(char*Msg, int Min, int Max){
	int number, check;
	char ch;
	do {
		printf("%s", Msg);
		fflush(stdin);//delete buffer
		check = scanf("%d%c", &number, &ch);
		if (check==2 && ch=='\n'){
			if (number >= Min && number <= Max) break;
			else printf("Out of range, please enter %d-%d\n", Min, Max);
		} else printf("Invalid input, Please enter an integer number\n");
	}while(1);
	return number;
}
int main(){
	printf("Sum Even Odd program\n");
	//Enter the size of the array
	int n = checkInput("Please enter size of array: ", 1, INT_MAX);
	int i, a[n];
	
	printf("Input elements: \n");
	for (i=0;i<n;i++){
	//Enter the elements in the array
		printf("\tElement %d=",i+1);
		a[i] = checkInput("",INT_MIN,INT_MAX); 
	}
	int Even=0, Odd=0;
	
	//Sum of even and odd numbers in an array
	for (i=0; i<n;i++){
		if (a[i]%2==0 && a[i]>0){
			Even += a[i];
		} 
		if (a[i]%2 !=0 && a[i]>0){
			Odd += a[i];
		}
	}
	printf("Sum of Even=%d", Even);
	printf("\nSum of Odd=%d", Odd);
}
