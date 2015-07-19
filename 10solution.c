#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


/**
Problem 10
==========


   The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

   Find the sum of all the primes below two million.


   Answer: d915b2a9ac8749a6b837404815f1ae25

*/


int
isPrime(int n)
{
// from "cracking the coding interview" page 98, method for checking primality, slightly optimized to check only sqrt(n)
    int root = (int) sqrt(n);

    for(int i = 2; i < root; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int
main(void)
{
    int limit = 2000000;

    int sum = 0;
    for(int i = 2; i < limit; i++)
    {
        if(isPrime(i))
        {
            printf("adding %d\n", i);
            sum += i;
        }
    }
    printf("The sum of prime numbers below %d is: %d\n", limit, sum);
    return EXIT_SUCCESS;
}
