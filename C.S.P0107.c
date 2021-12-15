#include <stdio.h>
#include <string.h>

// find the substring position in main string function
void findPositionSubInMain(char sub[], char main[]){
	int i, j, count = 0, position = 0;
	for (i = 0; i < strlen(main); i++){
		// compare the character in substring with mainstring
		if((int) main[i] == (int) sub[0]){
			for (j = 1; j < strlen(sub); j++){
				if ((int) main[j + i] == (int) sub[j]){
					count++;
				}
			}
			// find the first position then break
			if(count == strlen(sub) - 1){
				position = i;
				break;
			} else {
				count = 0;
			}
		}
	}
	// output the position of substring if found
	if(count == strlen(sub) - 1){
		printf("Starting position of the substring in the main string: %d", position);
	} else {
		printf("Not found!");
	}
}


int main(){
	char main[100];
	char sub[100];
	printf("Please enter main string: ");
	gets(main);
	printf("Please enter substring: ");
	gets(sub);
	findPositionSubInMain(sub, main);
	return 0;
}
