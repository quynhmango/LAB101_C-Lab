#include<stdio.h>
#include<limits.h>
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

int main(){
	//Enter size of array and the elements in the array
	int size = checkInput("Please enter size of array: ", 1, INT_MAX);
	int a[size];
	int i, j, k;
	for (i=0;i<size;i++){
		printf("Enter element [%d]: ",i);
		a[i] = checkInput("",INT_MIN,INT_MAX);
	}
	//Print out array
	printf("The original array: \n");
	for (i=0;i<size;i++){
		printf("%d\t",a[i]);
	}
	//Remove duplicate element
	for(i=0; i<size; i++){
        for(j=i+1; j<size; j++){
            if( a[i] == a[j]){
                for(k=j; k<size-1; k++) {
                    a[k] = a[k+1]; 
                }
                size--; 
                j--; //vi tri
            }
        }
    }
 
    //Print the array after removing the duplicate element
    printf(" \nThe array after removing duplicate elements: \n");
	for (i=0;i<size;i++){
		printf("%d\t",a[i]);
	}	
}
