#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
//Characters that appears the most
//C.S.P0004
int main(){
	char Str[100],c;	
	do{
		int i,max=0;
		//stores the number of occurrences of an element starting from 0
		int alphabet[52]={0};
		printf("Enter a string : ");
       	gets(Str);
		fflush(stdin);
		
		//save the value and the number of occurrences in parallel
		for (i=0;i<strlen(Str);i++){			
			if (Str[i]>=65 && Str[i]<=90)
				alphabet[Str[i]-65]++;								
			else if (Str[i]>=97 && Str[i]<=122) //lowercase letters		
				alphabet[Str[i]-97+26]++;
		}	
		 
		//print out words: from A to z
		for (i=0;i<52;i++){			
			if (alphabet[i] != 0){
				if (i<26)
				 printf("%c ",i+65);
				else if (i>=26) //lowercase letters	
				printf("%c ",i-26+97);	
			}
		}
		printf("\n");
		//print out the number of occurrences
		for (i=0;i<52;i++){
			if (alphabet[i]>max) max=alphabet[i];			
			if (alphabet[i] != 0) 
				printf("%d ",alphabet[i]);	//number of appearance
		}
		
		int j=0;
		if (max==0) printf("No character\n");
		else{
			printf("\nCharacters that appears the most :\n");
			for (i=0;i<52;i++){
				//appearance=max
				if (alphabet[i]==max){
					j=j+1;				
					if (i<26) printf("%c ",i+65);
					else if (i>=26) printf("%c ",i-26+97);//lower case
				}
			}
			printf("\n");
			//print out the maximum number of occurrences
			for (i=1;i<=j;i++) 
			printf("%d ",max);
		}
		printf("\nPress enter to continue, esc to exit: ");
		c=getch();//input value
		if (c==27) break;//esc( escape) = 27
	}while(1);
	
return 0;
}



