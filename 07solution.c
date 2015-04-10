#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

const int LIMIT = 10001;

/**
Problem 7
=========


   By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
   that the 6th prime is 13.

   What is the 10 001st prime number?

   
   Answer: 8c32ab09ec0210af60d392e9b2009560
*/

int checkPrime(int n) {  
// from "cracking the coding interview" page 98, method for checking primality, slightly optimized to check only sqrt(n)
  if (n < 2){
    return false;
  }
  int root = (int) sqrt(n);
  for(int i = 2; i <= root; i++){
    if (n % i == 0){
      return false;
     }
  }
  return true;
}

int main(void){
  int numPrimes = 1, candidate = 2;    // starting from 2 and including it as the first (#1) prime

    while(numPrimes < LIMIT){   // until we find the 10 001st prime
          candidate++;            // check every integer for prime
      if(checkPrime(candidate)){  // enumerate every prime we find
        numPrimes++;
      }
    }
    
    printf("%d\n\n", candidate);
   	return 0;
   }