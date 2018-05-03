#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#define n 10000
#define nothread 4
int arr[n];
pthread_t pid[nothread];

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void printarr(){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}
void bubbleSort(void *var)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
 	for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

int main(){
	clock_t start,end;
	srand(time(NULL));
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
	for(i=0;i<nothread;i++){
		pthread_create(&pid[i],0,bubbleSort,NULL);
	}
	for(i=0;i<nothread;i++)
		pthread_join(pid[i],NULL);
	end=clock();
	printf("Time Taken: %lf ",(double)end-start);
	//printarr();
}
