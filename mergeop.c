#include<stdio.h>
#include<omp.h>
#include<time.h>
#include<stdlib.h>

void merge(int *p,int a,int b){
int i,j;
#pragma omp parallel num_threads(8)
#pragma omp for schedule(static) nowait
for(i=a;i<b;i++){
#pragma omp parallel num_threads(10)
#pragma omp for schedule(static) nowait
for(j=i;j<b;j++){
if(p[i]>p[j]){
int temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}
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
int array[15];
srand(time(NULL));
int i;
for(i=0;i<15;i++)
{
array[i]=rand()%1000;
}
printf("Unsorted array:\n");
for(i=0;i<15;i++)
{
printf(" %d",array[i]);
}
mergesort(array,0,15);

printf("\n\nSorted array:\n");
for(i=0;i<15;i++)
{
printf(" %d",array[i]);
}

}

