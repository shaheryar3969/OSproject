#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>

int n=10000;
int arr[10000] ;
int getMax()
{
    int mx = arr[0];
    int i;
    for (i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void print()
{	
	int i;
    for (i = 0; i < n; i++)
        printf("%d \n",arr[i]);
}

int main()
{
	clock_t start,end;
	srand(time(NULL));
	int exp,i=0;
	for(i=0;i<n;i++)
		arr[i]=rand() % 1000 + 1;  //randomly filling array
    	int m = getMax();
 	start=clock();
 	#pragma omp parallel num_threads(10) private (i,n)
	{
	int number=m;
	#pragma omp for schedule(dynamic,100)
    for (exp=1;number>0; exp*=10){
	number=m/exp;
    	int output[n]; // output array
    	int i, count[10] = {0};
    	for (i = 0; i < n; i++)
        	count[ (arr[i]/exp)%10 ]++;
 		for (i = 1; i < 10; i++)
        	count[i] += count[i - 1]; 
   	    for (i = n - 1; i >= 0; i--)
    	{
        	output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
	        count[ (arr[i]/exp)%10 ]--;
    	}
    	for (i = 0; i < n; i++)
        	arr[i] = output[i];	
}
}
    end=clock();
    printf("Time Taken: %lf ",(double)end-start);
   // print();
    return 0;
}
