#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>

void printarr(int array[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}

int main(){
	int i,j,temp;
	int n=10000;
	int array[n];
	srand(time(NULL));
	clock_t start,end;
	for(i=0;i<n;i++)
		array[i]=rand() % 1000;  //randomly filling array
	start=clock();
	#pragma omp parallel num_threads(10) private (i,j,temp)
	{
		#pragma omp for schedule(dynamic,100)
		for(i=1;i<n;i++){
			for(j=0;j<i;j++){
				if(array[j]>array[i]){
					temp=array[i];
					array[i]=array[j];
					array[j]=temp;
				}
			}
		}
	} 
	end=clock();
	printf("Time Taken:%lf ",(double)end-start);
	//printarr(array,n);
}
