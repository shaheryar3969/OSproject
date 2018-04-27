#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

int n=1000;
int array[1000];
int no_of_thread=10;
pthread_t pid[10];
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
	int num=n/no_of_thread;
	j=0;
	for(i=1;i<n;i++){
		if(num==0)	{
			num=n/no_of_thread;
			j++;
		}
		pthread_create(&pid[j],0,func1,i);
	
		num--;
	}
	int k;
	for(k=0;k<no_of_thread;k++){
		pthread_join(pid[k],NULL);
	}
	end=clock();
	printf("Time Taken:%d %lf ",j,(double)end-start);
	//printarr(array);
}

void func1 (void * var){
	int i=(int)var;
	int j,temp;
	for(j=0;j<i;j++){
				if(array[j]>array[i]){
					temp=array[i];
					array[i]=array[j];
					array[j]=temp;
				}
			}
}
