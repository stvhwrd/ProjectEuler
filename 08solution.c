#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


/**
Problem 8
=========


     The four adjacent digits in the 1000-digit number that have the greatest
     product are 9 × 9 × 8 × 9 = 5832.

                            73167176531330624919225119674426574742355349194934
                            96983520312774506326239578318016984801869478851843
                            85861560789112949495459501737958331952853208805511
                            12540698747158523863050715693290963295227443043557
                            66896648950445244523161731856403098711121722383113
                            62229893423380308135336276614282806444486645238749
                            30358907296290491560440772390713810515859307960866
                            70172427121883998797908792274921901699720888093776
                            65727333001053367881220235421809751254540594752243
                            52584907711670556013604839586446706324415722155397
                            53697817977846174064955149290862569321978468622482
                            83972241375657056057490261407972968652414535100474
                            82166370484403199890008895243450658541227588666881
                            16427171479924442928230863465674813919123162824586
                            17866458359124566529476545682848912883142607690042
                            24219022671055626321111109370544217506941658960408
                            07198403850962455444362981230987879927244284909188
                            84580156166097919133875499200524063689912560717606
                            05886116467109405077541002256983155200055935729725
                            71636269561882670428252483600823257530420752963450



    Find the thirteen adjacent digits in the 1000-digit number that have the
     greatest product. What is the value of this product?


     Answer: 0f53ea7949d32ef24f9186207600403c
*/

// put the digits into an array. start at index zero and compare 13-consecutive-digit-products
// until we reach the end of the array
// we can also compute 13 digit sums since 13 highest digits would yield highest possible product
// keep track of maxProduct, return maxProduct

const int ARRAY_LENGTH = 1000;

int runSize = 0;

int computeProduct(int numArray[], int firstIndex)
{
    int product = 1;

    // check that we're in range.  We need runSize # of consecutive digits
    if(firstIndex > (1000 - (runSize-1)))
    {
        return 0;
    }
    for(int j = 0; j < runSize; j++)
    {
        product *= numArray[firstIndex + j];
    }
    return product;
}


int main(void){
    char* hugeNumber =   "73167176531330624919225119674426574742355349194934"
                         "96983520312774506326239578318016984801869478851843"
                         "85861560789112949495459501737958331952853208805511"
                         "12540698747158523863050715693290963295227443043557"
                         "66896648950445244523161731856403098711121722383113"
                         "62229893423380308135336276614282806444486645238749"
                         "30358907296290491560440772390713810515859307960866"
                         "70172427121883998797908792274921901699720888093776"
                         "65727333001053367881220235421809751254540594752243"
                         "52584907711670556013604839586446706324415722155397"
                         "53697817977846174064955149290862569321978468622482"
                         "83972241375657056057490261407972968652414535100474"
                         "82166370484403199890008895243450658541227588666881"
                         "16427171479924442928230863465674813919123162824586"
                         "17866458359124566529476545682848912883142607690042"
                         "24219022671055626321111109370544217506941658960408"
                         "07198403850962455444362981230987879927244284909188"
                         "84580156166097919133875499200524063689912560717606"
                         "05886116467109405077541002256983155200055935729725"
                         "71636269561882670428252483600823257530420752963450";

     // Declare a 1000 digit array of integers
     int numArray[ARRAY_LENGTH];

     // cast each character as an integer in the numArray
     for(int i = 0; i < ARRAY_LENGTH; i++)
     {
          numArray[i] = hugeNumber[i] - '0';
     }

    int maxProduct = 0;
    int runStart = 0;

    printf("How many consecutive digits are we interested in? ");
    scanf("%d", &runSize);

    for(int firstIndex = 0; firstIndex < (1000 - (runSize)); firstIndex++){

        int runProduct = computeProduct(numArray, firstIndex);

        if(runProduct > maxProduct)
        {
            maxProduct = runProduct;
            runStart = firstIndex;
        }
    }

    //Clearly print conclusion of calculations:
    printf("\nThe highest product of %d consecutive numbers in the provided %d digit number is %d.\n", \
            runSize, ARRAY_LENGTH, maxProduct);

    printf("\nThe run starts from the integer at index %d and consists of the numbers: \n\n", \
            runStart);

    for(int j = 0; j < runSize; j++)
    {
        printf("%d ", numArray[runStart + j]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
