#include <stdio.h>

int main(void){

	int evenFib = 2;	// initialized at 2 to include the first
	int sum = 2;	//to return the value of fibonacci number A
	int i = 1;

	while(i <= 4000000)
	{
		sum += 	i;
		i 	= 	sum-i;
		if(sum%2 == 0)
		{
			evenFib += sum;
		}
	}
	printf("%d\n",evenFib);
return 1;	//exit
}
