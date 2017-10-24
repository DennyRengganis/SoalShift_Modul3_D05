#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t p1;
pthread_t p2;
int scorep1=0,scorep2=0,mines[2][17];
char* player1;
char* player2;
int status=0,flag1=0,flag2=0;

void point(){
printf("Point dari %s adalah : %d\n",player1,scorep1);
printf("Point dari %s adalah : %d\n",player2,scorep2);
}

void* turnp1(void *arg){
	while(flag1<10){
	while(status==1){

	}
	flag1++;
	printf("flag1 : %d\n",flag1);
	status=1;
	}
	return NULL;
}

void* turnp2(void *arg){
	while(flag2<10){
	while(status==0){

	}
	flag2++;
	printf("flag2 : %d\n",flag2);
	status=0;
	}
	return NULL;
}

int main(){
	printf("Masukkan Nama pemain pertama dan pemain kedua  : ");
	scanf("%s %s", player1,player2);
//	getchar();
//	printf("Masukkan Nama pemain kedua :" );
//	scanf("%s", player2);
//	getchar();

	pthread_create(&(p1),NULL,&turnp1, NULL);
	pthread_create(&(p2),NULL,&turnp2, NULL);

	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
}
 
