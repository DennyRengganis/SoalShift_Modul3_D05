#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t p1;
pthread_t p2;
int scorep1=0,scorep2=0,mines[2][17];
char* p1;
char* p2;

void point(){
printf("Point dari %s adalah : %d\n",p1,scorep1);
printf("Point dari %s adalah : %d\n",p2,scorep2);
}

void* turnp1(void *arg){
	while(/*kondisimutex*/){
	//mutex
	}
}

void* turnp2(void *arg){
	while(/*kondisimutex*/){
	//mutex
	}

}
int main(){

}
