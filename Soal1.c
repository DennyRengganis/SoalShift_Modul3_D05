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

void pembeli(int* jmlh){
	int jenis,jumlah,pilih,i;
	char nsenjata[100];
	while(1){
		menupembeli();
		scanf("%d",&pilih);
		if(pilih==1){
			for(i=0;i<6;i++){
				printf("%s %d\n",senjata[i],jmlh[i]);
			}
		}
		else if(pilih==2){
			printf("Tuliskan nama senjata yang akan dibeli dan berapa jumlahnya ?\n");
			scanf("%s %d",nsenjata,&jumlah);
			printf("\n");
			if(strcmp(nsenjata,"MP4A1")==0){
				if(jmlh[0]>=jumlah) jmlh[0]-=jumlah;
				else printf("Jumlah stok tidak cukup\n");
			}
			else if(strcmp(nsenjata,"PM2-V1")==0){
				if(jmlh[1]>=jumlah) jmlh[1]-=jumlah;
				else printf("Jumlah stok tidak cukup\n");
			}
                        else if(strcmp(nsenjata,"SPR-3")==0){
                                if(jmlh[2]>=jumlah) jmlh[2]-=jumlah;
                                else printf("Jumlah stok tidak cukup\n");
                        }
                        else if(strcmp(nsenjata,"SS2-V5")==0){
                                if(jmlh[3]>=jumlah) jmlh[3]-=jumlah;
                                else printf("Jumlah stok tidak cukup\n");
                        }
                        else if(strcmp(nsenjata,"SPG1-V3")==0){
                                if(jmlh[4]>=jumlah) jmlh[4]-=jumlah;
                                else printf("Jumlah stok tidak cukup\n");
                        }
                        else if(strcmp(nsenjata,"MINE")==0){
                                if(jmlh[5]>=jumlah) jmlh[5]-=jumlah;
                                else printf("Jumlah stok tidak cukup\n");
                        }
		}
		else{
			printf("tolong masukkan input sesuai menu");
		}
	}
}

void penjual(int* jmlh){
	int jenis,jumlah,pilih,i;
        char nsenjata[100];
        while(1){
                menupenjual();
                scanf("%d",&pilih);
                if(pilih==1){
                        for(i=0;i<6;i++){
                                printf("%s %d\n",senjata[i],jmlh[i]);
                        }
                }
                else if(pilih==2){
                        printf("Tuliskan nama senjata yang akan ditambah stoknya dan berapa jumlahnya ?\n");
                        scanf("%s %d",nsenjata,&jumlah);
                        printf("\n");
			if(strcmp(nsenjata,"MP4A1")==0){
				jmlh[0]+=jumlah;
			}
			else if(strcmp(nsenjata,"PM2-V1")==0){
				jmlh[1]+=jumlah;
			}
                        else if(strcmp(nsenjata,"SPR-3")==0){
                                jmlh[2]+=jumlah;
                        }
                        else if(strcmp(nsenjata,"SS2-V5")==0){
                                jmlh[3]+=jumlah;
                        }
                        else if(strcmp(nsenjata,"SPG1-V3")==0){
                                jmlh[4]+=jumlah;
                        }
                        else if(strcmp(nsenjata,"MINE")==0){
                                jmlh[5]+=jumlah;
                        }
		}
		else{
			printf("tolong masukkan input sesuai menu\n");
		}
	}
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
	if(peran==1){
		pembeli(value);
	}
	else if(peran==2){
		penjual(value);
	}
	else{
		printf("tolong input sesuai dengan menu\n");
	}
}
