//C.S.P0046
//Basic Computation Practice.
//done
#include<stdio.h>
#include<limits.h>
#include <stdlib.h>
#include <math.h>
//Check input
int checkInput(int Min, int Max){
	int number, check;
	char ch;//character
	do {
		fflush(stdin);//delete buffer
		check = scanf("%d%c", &number, &ch);
		if (ch=='\n'){ 
			//Check input is in range
			if (number >= Min && number <= Max) 
				break;
			else printf("Out of range, please enter %d-%d\n", Min, Max);
		} 	else printf("Invalid input, Please enter an integer number\n");
	}while(1);
	return number;
}
//Check prime
int Prime(int n){
	int i;
    if(n<2) return 0;
    else{
    	//Only divisible by 1 and itself
    	for(i=2;i<=sqrt(n);i++)
			if(n%i==0) return 0;
	}    
    return 1;
}

//Check first n primes
void firstPrime(){  
    int i=2;//find prime number starts from 2
    int n,count=0;
    printf("Nhap n = ");//enter input
    n = checkInput(1,INT_MAX);//re-enter if not in range
    do{
        if(Prime(i)==1){//i is prime
			printf("%d ",i);//prime: 2->n
            count++;//increase count when i is prime
		}
		i++;
    } 
	while( count<n);//stop when loop = input
}
//Check fibonacci
int fb(int n){
    if(n==1||n==0||n==2||n==3) return n;
   	return fb(n-1)+fb(n-2);// f(n) = f(n-1) + f(n-2)
}
//Check the number is in the sequence fibo
void Fibonaci(){
	int i,n,count=0;
   	printf("n = ");//input
   	scanf("%d",&n);
   	for(i=0;i<=n;i++)
       	if(n==fb(i)){
            printf("%d thuoc day fibonacci",n); 
			return;        
       	}
   	printf("%d khong thuoc day fibonacci",n);
   }
//Sum of numbers in a number
void sumDigit(){
	int a, tong=0;
	printf("Enter an integer: ");
	int n = checkInput(INT_MIN,INT_MAX);
	if (n<0) n = n*(-1);
	if (n<10) printf("\nSum digits: %d",n);
	else {
		while(n>0) {
			a = n%10;//divide by remainder,  123%10 =3
			n = n/10;//divide by integer, 123/10=12
			tong = tong + a;//add sum of surplus is divided
		}
		printf("\nSum digits: %d",tong);
	}
}

int main(){
	do{
		printf("\n1. The first primes\n");
		printf("2. Fibonacci element\n");
		printf("3. Sum of digits\n");
		printf("4. Quit\n");
		printf("Choose an option : ");
		int choice = checkInput(1,4);
		switch (choice){
			case 1: 
				firstPrime();
				break;
			case 2: 
				Fibonaci();
				break;
			case 3:
				sumDigit();
				break;
			case 4: 
				return 0;
			default: 
				printf("Enter integer number from 1-4\n");
				break;
		}
	}while(1);
return 0;
}

