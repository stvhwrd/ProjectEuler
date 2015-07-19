#include <stdio.h>
#include <stdlib.h>

int isPali(int a){
	char paliChars[6];
	itoa(a, paliChars, 10);
	for(int i = 0; i < 3; i++){
		if(paliChars[i] != paliChars[6 - i]){
			return 0;
		}	// this has a limitation of working only on 6 digit products, so 100*100 for example wouldn't work
	}
	return 1;
}


int main(void){
	int num1 = 999;
	int num2 = 999;
	int paliNum = 0;


	while(num1 >= 100){
		for(num2; num2 >= 100; num2--)
		paliNum = num1 * num2;

		if(isPali(paliNum)){
			printf("the highest palindrome is %d", paliNum);
			return 1;
		}
		num1--;
	}
	return 1;	//exit program
}
