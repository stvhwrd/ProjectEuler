#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


/**
Problem 9
=========


   A Pythagorean triplet is a set of three natural numbers, a < b < c, for
   which,

                                a^2 + b^2 = c^2

   For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

   There exists exactly one Pythagorean triplet for which a + b + c = 1000.
   Find the product abc.


   Answer: 24eaa9820350012ff678de47cb85b639
*/


int sum = 0;

int
squareOf(int n)
{
    return n * n;
}

int
hypoteneuseOf(int a, int b)
{
    return sqrt(squareOf(a) + squareOf(b));
}

int
isPythagoreanTriple(int a, int b, int c)
{
    if(a < b && b < c)
    {
        if(squareOf(a) + squareOf(b) == squareOf(c))
        {
            return true;
        }
    }
    return false;
}


int
main(void)
{
    int runStart = 0;

    printf("Enter the (integer) sum of target Pythagorean triple (example: 1000):  ");

    scanf("%d", &sum);

    for(int i = 0; i < sum; i++)
    {
        for(int j = (i + 1); j < sum; j++)
        {
            double k = hypoteneuseOf(i,j);
            if(isPythagoreanTriple(i,j,k) && (i + j + k == sum))
            {
                printf("%d * %d * %d == %d\n", i, j, (int) k, (i * j * (int) k));
            }
        }
    }
  return EXIT_SUCCESS;
}
