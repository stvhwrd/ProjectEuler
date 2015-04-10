#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

const int LIMIT = 100;
/**
Problem 6
=========


   The sum of the squares of the first ten natural numbers is,

                          1^2 + 2^2 + ... + 10^2 = 385

   The square of the sum of the first ten natural numbers is,

                       (1 + 2 + ... + 10)^2 = 55^2 = 3025

   Hence the difference between the sum of the squares of the first ten
   natural numbers and the square of the sum is 3025 − 385 = 2640.

   Find the difference between the sum of the squares of the first one
   hundred natural numbers and the square of the sum.

   
   Answer: 867380888952c39a131fe1d832246ecc
   */

long int squareOfSum(int limit){
	return (limit*(limit+1)/2)*(limit*(limit+1)/2);		// n(n+1)/2 * n(n+1)/2   <-- famous formula for sum of integers from 1 through n
}

long int sumOfSquares(int limit){	 // recursive algorithm:  n^2 + (n-1)^2 + (n-2)^2 + .... + 2^2 + 1^2
	if(limit == 0){
		return 0;
	}
	return limit*limit + sumOfSquares(limit-1);
}

int main(void){
   	printf("The sum of squares from first %d is %ld\n\n", LIMIT, sumOfSquares(LIMIT));
   	printf("The square of the sum from first %d is %ld\n\n", LIMIT, squareOfSum(LIMIT));
   	printf("The difference between them is %ld\n\n", squareOfSum(LIMIT) - sumOfSquares(LIMIT));
   	return 0;	
   }