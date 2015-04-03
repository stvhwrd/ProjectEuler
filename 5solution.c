#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


const int  LIMIT = 20;
/**
Problem 5
=========


   2520 is the smallest number that can be divided by each of the numbers
   from 1 to 10 without any remainder.

   What is the smallest positive number that is evenly divisible by all of
   the numbers from 1 to 20?

   
   Answer: bc0d0a22a7a46212135ed0ba77d22f3a
*/


int checkAnswer(int answer){
	for(int i = 1; i<=LIMIT; i++){
		if(answer%i!=0){
			return 0;
		}
	}
	return 1;
}

int main(void){
	
	printf("What is the smallest positive number that is evenly divisible by all of the numbers from 1 to %d?\n", LIMIT);
	printf("	 - We begin at %d.\n\n", LIMIT);
	// start with the product of every number between 1 and upper limit
	// for x from upper limit to 1: if x is not a prime number, divide product by x
	long int result = LIMIT;
	 for(int i = LIMIT-1; i >= LIMIT/2; i--){	//only need to check the top half of LIMIT since the bottom half will divide evenly into the top half
	 	if(result%i!=0){
	 		printf("	- Since %ld is not divisible by %d, we multiply together for ", result, i);
	 		result*=i;
	 		printf("%ld\n\n", result);
	 	}
	 }

	 //strip out redundant factors (generally a factor of 2 for some reason)
	 for(int j = 2; j<LIMIT; j++){
	 	while(checkAnswer(result/j)){
	 	result /= j;
	 	}
	 }

	 printf("\n\nFinal answer is: %ld, answer has been checked and found to be", result);
	 if(checkAnswer(result)){
	 	printf(" correct.");
	 }
	 else{
	 	printf(" INCORRECT!");
	 }
	return 0;
}