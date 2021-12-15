#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int input(){
	int n;
	char c;
	while (1) {
		scanf("%d%c",&n,&c);fflush(stdin);
		if (c=='\n'&& n>0) break;
		else printf("Enter an integer: ");
	}
	return n;
}
int main(){
	int size, i, j, k; //k: new value added
	char c;
	
	//Enter size of array and the elements in the array
	printf("Please enter size of array : ");
	size = input();
	int a[size];
	for (i=0; i<size; i++){
		printf("Element[%d]: ",i);
		a[i]= input();	
	}
	
	//Print out array after sorting ascending
	int temp;
	printf("The array after sorting : \n");
	for (i= 0; i< size; i++){
		for (j= i+1; j<size; j++){
			if (a[j]<a[i]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (i= 0; i< size; i++)	
		printf("%d ", a[i]);
		
	//Enter new value	
	printf("\nPlease enter new value: ");
	scanf("%d", &k);
	size += 1;
	int pos;
	//the added element is smaller than the smallest element in the array
	if (k <= a[0]) pos=0;
	//the added element is larger than the largest element in the array
	else if (k >= a[size-2]) pos= size-1;
	//the added element is in the middle of the array
		else {
			for (i= 1; i< size-2; i++){ 
				if (a[i]<= k && k< a[i+1]){ 
					pos = i+1;
					break;
				}
			}
		}
	
	for (i= size-1; i> pos; i--)	a[i]= a[i-1];
	a[pos]= k;
	
	//Print out new array	
	printf("New array : \n");
	for (i=0; i<size; i++) 
		printf("%d ",a[i]);
return 0;
}

