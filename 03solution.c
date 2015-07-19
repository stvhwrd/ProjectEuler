#include <stdio.h>

int main(void){
	long num = 600851475143;	//the number in question
	long gpf = num;		//the initial greatest prime factor will be assumed to be the original value of num

	int i = 2;	//start the index at the first prime number

	while(i < gpf){	//while the factor is less than the remaining number
		if(gpf % i == 0){	//if the factor truly divides the number
			while(gpf % i == 0){	//then reduce the number by as many of these factors as possible
				gpf /= i;
			}
		}
		i ++;	//increment i to check the next number (from 2 to 3 to 4...etc)
	}
	printf("%ld\n", gpf);	// print the result
	return 1;	//exit program
}
