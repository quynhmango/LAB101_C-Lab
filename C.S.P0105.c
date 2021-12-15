#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<ctype.h>
//Using recursion
void reverse(char s[], int begin, int end){ 
	//Swap the first and last two characters
	if (begin<end){
		char ch = s[begin];
		s[begin] = s[end];
		s[end] = ch;
		reverse(s, begin+1, end-1);
	}
}

int main(){
	char s[100];
	printf("Please enter any string: ");
	gets(s);//input string
	int size = strlen(s);//string length
	reverse(s,0, size-1);
	printf("\nResult: %s",s);
}

