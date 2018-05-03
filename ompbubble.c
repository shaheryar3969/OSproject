#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void printarr(int *p,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",p[i]);
}
void bubbleSort(int *var,int n)
{
   int i, j;
   #pragma omp parallel no_threads(4)
   {
   #pragma omp for schedule(dynamic)
   for (i = 0; i < n-1; i++)      
 	for (j = 0; j < n-i-1; j++) 
           if (var[j] > var[j+1])
              swap(&var[j], &var[j+1]);
}
}

int main(){
	int n=10000;
	clock_t start,end;
	srand(time(NULL));
	int arr[n];
	int i;
	for(i=0;i<2500;i++)
		arr[i]=rand()%250;
	for(i=2500;i<5000;i++)
		arr[i]=rand()%250+250;
	for(i=5000;i<7500;i++)
		arr[i]=rand()%250+500;
	for(i=7500;i<10000;i++)
		arr[i]=rand()%250+750;
	start=clock();
	bubbleSort(arr,n);
	end=clock();
	printf("Time Taken: %lf ",(double)end-start);
	//printarr(arr,n);
}
