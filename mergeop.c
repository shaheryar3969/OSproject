#include<semaphore.h>
#include<stdio.h>
#include<omp.h>
#include<time.h>
#include<stdlib.h>
# define size 1000 // size for data set to be sorted
sem_t sem1;
void merge(int *p,int a,int b){
int i,j;
#pragma omp parallel num_threads(4)
{
#pragma omp for schedule(dynamic)
for(i=a;i<=b;i++){
if(i<size)
sem_wait(&sem1);
#pragma omp parallel num_threads(4)
#pragma omp for schedule(dynamic)
for(j=i;j<b+2;j++){
if(j<size)
if(p[i]>=p[j]){
int temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
sem_post(&sem1);
}
wait(NULL);
}
wait(NULL);
}

void mergesort(int *p,int s, int e){
int mid=(s+e)/2;
if(mid>s && mid <e){
mergesort(p,s,mid);
mergesort(p,mid+1,e);
merge(p,s,e);
}
int i;
}

int main(){

sem_init(&sem1,0,1);
int array[size];
srand(time(NULL));
int i;
for(i=0;i<size;i++)
{
array[i]=rand()%1000;
}
printf("Unsorted array:\n");
for(i=0;i<size;i++)
{
//printf(" %d",array[i]);
}
mergesort(array,0,size);

printf("\n\nSorted array:\n");
for(i=0;i<size-2;i++)
{
//if(array[i]<array[i+1]&& array[i]<array[i+2])
printf(" %d\n",array[i]);
}

}

