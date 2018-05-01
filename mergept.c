#include<stdio.h>
#include<pthread.h>
#include<time.h>
#include<stdlib.h>
//implementatio of merge sort using pthread
struct sss{
int *p;
int s;
int e;
};

void merge(int *p,int a,int b){
int i,j;
for(i=a;i<b;i++){
for(j=i;j<b;j++){
if(p[i]>p[j]){
int temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}
}
void mergessort(int *p,int s,int e){

int mid=(s+e)/2;
if(mid>s && mid <e){
mergessort(p,s,mid);
mergessort(p,mid+1,e);
merge(p,s,e);
}
}

void *mergesort(void *ss){
struct sss st=*(struct sss *)ss;
int *p=st.p;
int s=st.s;
int e=st.e;

int mid=(s+e)/2;
if(mid>s && mid <e){
mergessort(p,s,mid);
mergessort(p,mid+1,e);
merge(p,s,e);
}
}

int main(){
int array[20];
srand(time(NULL));
int i;
for(i=0;i<20;i++)
{
array[i]=rand()%1000;
}
for(i=0;i<20;i++)
{
printf(" %d",array[i]);
}
struct sss val[4];
int s=0,e=5;
for(i=0;i<4;i++){
val[i].p=array;
val[i].s=s;
val[i].e=e;
s=s+5;
e=e+5;

}
pthread_t pid[4];
for(i=0;i<4;i++){
pthread_create(&pid[i],NULL,mergesort,(void *)&val[i]);
}
for(i=0;i<4;i++){
pthread_join(pid[i],NULL);
}
merge(array,0,20);
printf("\n\nSorted array:\n");
for(i=0;i<20;i++)
{
printf(" %d",array[i]);
}
printf("\n\n");
}
