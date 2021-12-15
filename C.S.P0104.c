//C.S.P0104
//Check a number can be express as sum of two prime numbers
//16 = 3 + 13
//16 = 5 + 11
//done
#include<stdio.h>
#include <math.h>
int input();
int SoNguyenTo(int n);

int main(){
	int num, i, check=0;
	printf("Enter number: ");
	num=input();
	for(i=2;i<=num/2;i++){
		if(SoNguyenTo(i)==1){
	   		if(SoNguyenTo(num-i)==1){
	   			printf("%d=%d+%d\n",num,i,num-i);
		    	check++;
	   		}
		}
	}
	if(check==0){
		printf("%d is not sum of prime",num);
	}
return 0;
}
//check prime
int SoNguyenTo(int n){
	int i;
    if(n==0||n==1) return 0;//not prime number
    for(i=2;i<=sqrt(n);i++)
		if(n%i==0) return 0;
    return 1;
}
//input data
int input(){
	int n;
	char c;
	while (1) {
		scanf("%d%c",&n,&c);fflush(stdin);
		if (n>0 && c=='\n') break;
		else printf("Enter an integer: ");
	}
	return n;	
}
