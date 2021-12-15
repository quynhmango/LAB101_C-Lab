#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>

int main(){
	int i;
	char s[100], news[100];
	char demiter= 95;
	do{
		//Enter String
		printf("Please enter string : ");
		scanf("%[^\n]",&s);
		fflush(stdin);
		//Print old string
		printf("The old string : %s\n",s);
		strcpy(news," ");
		//Browse from bottom to top and concatenate the string after the demiter
		for (i=strlen(s); i>=0; i--){
			if (s[i] == demiter){
				strcat(news, &s[i+1]);  
				strcat(news, "_");
				s[i]=0; // reset
			}
		}
		strcat(news,s);//append new string to old string
		printf("The reversed string : %s\n", news);
		strcpy(s," ");
		strcpy(news," ");
		printf("Press enter to continue another reverse, ESC to exit\n");
		char key=getch();//get input character
		fflush(stdin);//delete buffer
		if (key==27) break;
	}while (1);	
return 0;
}
