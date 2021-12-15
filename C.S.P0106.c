#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
//Check Length Repeat Character
int checkLengthRepeatCharacter(char* input){
	int count[127] = {0};//ASCII
	int i;
	int reallen = strlen(input);//the length of a given string
	for( i=0; i<strlen(input); i++){
		//undistinguished between uppercase and lowercase letters
		count[(int) tolower(input[i])]++;
	}
	//total number of characters in the ASCII
	for(i=0; i<127; i++){
		if(count[i]>1){//check duplicate
			reallen=reallen-count[i]+1;
		}
	}
	return reallen;
}
//get Longest Substring
void getLongestSubstring(char inputstring[50]){
	char result[100];//save string has been changed
	char *p;//original string
	int max, i, j;
	//searches for a separator string within a larger string
	p = strtok(inputstring, " ");
	//copy the old string result to the new string
	strcpy(result, p);
	max = checkLengthRepeatCharacter(p);
	while(p != NULL){
		p= strtok(NULL, " ");
		if(p != NULL){
			int temp;
			temp = checkLengthRepeatCharacter(p);
			if(max < temp){
				max = temp;
				strcpy(result, p);
			}
		}
	}
	printf("The longest substring: %s [%d]", result, max);
}
int main(){
	char input[50];
	printf("Please enter any string: ");
	gets(input);//input string
	getLongestSubstring(input);
	return 0;	
}
