#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
int n=10000;
int arr[10000] ;
int pnum=10;
int size=1000;
pthread_t pid[10];

int getMax()
{
    int mx = arr[0];
    int i;
    for (i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
void countSort(int num,int exp)
{
    int output[size],temp[size]; // output array
    int i,j, count[10] = {0};

    for(i=num,j=0;i<num+size;i++,j++)
		temp[j]=arr[i];
    for (i = 0; i < size; i++)
        count[ (temp[i]/exp)%10 ]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = size - 1; i >= 0; i--)
    {
        output[count[ (temp[i]/exp)%10 ] - 1] = temp[i];
        count[ (temp[i]/exp)%10 ]--;
    }
 
    for (i = 0,j=num; i < size; i++,j++)
        arr[j] = output[i];
}

void radixsort(void * var)
{
    int num=(int)var;
	int m = getMax(arr, n);
	int exp; 
    for (exp = 1; m/exp > 0; exp *= 10)
        countSort(num,exp);
       
}
 

void print()
{	
	int i;
    for (i = 0; i < n; i++)
        printf("%d ",arr[i]);
}
 
int main()
{
	srand(time(NULL));
	clock_t start,end;
	int exp,i,j;
	for(i=0;i<n;i++)
		arr[i]=rand() % 1000 + 1;  //randomly filling array
    start=clock();
	for(i=0;i<pnum;i++){
    	j=i*size;
    	pthread_create(&pid[i],0,radixsort,(void*)j);
	}
	for(i=0;i<pnum;i++){
		pthread_join(pid[i],NULL);
	}
	end=clock();
	printf("Time Taken: %lf ",(double)end-start);
    //print();
    return 0;
}
