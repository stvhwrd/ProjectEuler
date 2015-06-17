#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int sumMultiples(int limit)
{
    int sum = 0;
    
    for(int i = 0; i < limit; i++)
    {
    // using an if-else (instead of if-if) prevents the program from adding multiples of 15 twice (once for 3 and once for 5).
        if(i%3==0)
        {
            sum+=i;
        }           
        else if(i%5==0)
        {
            sum+=i;
        }
    }
    return sum;
}


int main() 
{
    int testCases = 0, limit = 0;
    
    // testCases consumes the first input (in this implementation)
    scanf("%i", &testCases);    

    //as long as we're reading in test cases
    while(scanf("%d", &limit) == 1)
    {
    	// print the sum of 3 and/or 5 multiples less than the specified limit
        printf("%d\n", sumMultiples(limit));
    }
    return 0;
}
