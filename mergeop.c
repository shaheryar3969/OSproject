#include<semaphore.h>
#include<stdio.h>
#include<omp.h>
#include<time.h>
#include<stdlib.h>
# define size 1000 // size for data set to be sorted

void merge(int *p,int a,int b){
int i,j;
#pragma omp parallel num_threads(4)
{
#pragma omp for schedule(dynamic)
for(i=a;i<=b;i++){
if
(i<size)
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

clock_t start,end;
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
start=clock();
mergesort(array,0,size);
end=clock();
printf("Time taken: %d",(double)end-start);
printf("\n\nSorted array:\n");
for(i=0;i<size-2;i++)
{
//if(array[i]<array[i+1]&& array[i]<array[i+2])
printf(" %d\n",array[i]);
}

}
