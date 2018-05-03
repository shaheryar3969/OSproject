#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

int n=10000;
int array[10000];
int no_of_thread=10;
pthread_t pid[10];
int size=1000; 

void func1 (void * var);
void printarr(int array[]){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}

int main(){
	int i,j,temp;
	srand(time(NULL));
	clock_t start,end;
	for(i=0;i<n;i++)
		array[i]=rand() % 1000;  //randomly filling array
	start=clock();
	for(i=0;i<10;i++){
		j=i*size;
		pthread_create(&pid[i],0,func1,(void*)j);
	}
	int k;
	for(k=0;k<no_of_thread;k++){
		pthread_join(pid[k],NULL);
	}
	end=clock();
	printf("Time Taken: %lf ",(double)end-start);
	//printarr(array);
}

void func1 (void * var){
	int k=(int)var;
	int i,j,temp;
	
	for(i=k+1;i<k+size;i++){
			for(j=0;j<i;j++){
				if(array[j]>array[i]){
					temp=array[i];
					array[i]=array[j];
					array[j]=temp;
				}
			}
		}
}
