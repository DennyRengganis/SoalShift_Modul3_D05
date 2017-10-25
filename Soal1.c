#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

char senjata[6][10]={"MP4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"};

void menupenjual(){
	printf("1. List Senjata\n");
	printf("2. Tambah Stock\n");
	printf("Pilih : ");
}

void menupembeli(){
	printf("1. List Senjata\n");
	printf("2. Beli Senjata\n");
	printf("Pilih : ");	
}

int main(){
	key_t key=1234;
	int *value;
	int peran;
	int shmid=shmget (key,sizeof(int), IPC_CREAT | 0666);
	value=shmat(shmid,NULL,0);
	int role;
	printf("Apakah anda pembeli atau penjual?\n");
	printf("1. Pembeli\n");
	printf("2. Penjual\n");
	printf("Pilih : ");
	scanf("%d",&peran);
}
