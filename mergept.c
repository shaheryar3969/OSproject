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
clock_t start,end;
int array[10000];
srand(time(NULL));
int i;
for(i=0;i<2500;i++)
{
array[i]=rand()%250;
}
for(i=2500;i<5000;i++)
{
array[i]=rand()%250+250;
}
for(i=5000;i<7500;i++)
{
array[i]=rand()%250+500;
}
for(i=7500;i<10000;i++)
{
array[i]=rand()%250+750;
}




struct sss val[4];
int s=0,e=2500;
for(i=0;i<4;i++){
val[i].p=array;
val[i].s=s;
val[i].e=e;
s=s+2500;
e=e+2500;

}
pthread_t pid[4];
start=clock();
for(i=0;i<4;i++){
pthread_create(&pid[i],NULL,mergesort,(void *)&val[i]);
}
for(i=0;i<4;i++){
pthread_join(pid[i],NULL);
}
end=clock();
printf("Time Taken:%d",(double)end-start);
/*printf("\n\nSorted array:\n");
for(i=0;i<10000;i++)
{
printf(" %d",array[i]);
}
printf("\n\n");*/
}
