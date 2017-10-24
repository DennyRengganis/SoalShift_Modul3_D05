#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t p1;
pthread_t p2;
int scorep1=0,scorep2=0,mines[2][17];
char player1[100];
char player2[100];
int status=0,k,l,tanda=0,lubang,isi,tebak;

void point(){
printf("Point dari %s adalah : %d\n",player1,scorep1);
printf("Point dari %s adalah : %d\n",player2,scorep2);
}

void* turnp1(void *arg){
	while(scorep1<10){
		while(status==1){

		}
		if(status==999){
			return NULL;
		}
	for(k=0;k<2;k++){
		for(l=0;l<16;l++){
			if(mines[k][l]==1){
				tanda++;
				}
			}
		}
	if(tanda==32){
		break;
		}
	printf("%s pilih banyak lubang yang akan di isi(hanya bisa mengisi maksimal 4 lubang)\n",player1);
	scanf("%d",&lubang);
	for(k=1;k<=lubang;k++){
		printf("pilih nomor lubang yang akan diisi");
		scanf("%d",&isi);
		mines[0][isi]=1;
		}
	printf("%s pilih lubang yang akan di tebak",player2);
	for(k=1;k<=4;k++){
		scanf("%d",&tebak);
		if(mines[0][tebak]==1) scorep1++;
		else scorep2++;
		}
	point();
	status=1;
	}
	printf("Permainan Selesai\n");
	point();
	if(scorep1>scorep2){
	printf("Pemain pertama %s menang\n",player1);
	}
	else if(scorep2>scorep1){
	printf("Pemain kedua %s menang\n",player2);
	}
	else{
	printf("Permainan seri\n");
	}
	status=999;
	return NULL;
}

void* turnp2(void *arg){
	 while(scorep2<10){
                while(status==0){

                }
                if(status==999){
                        return NULL;
                }
        for(k=0;k<2;k++){
                for(l=0;l<16;l++){
                        if(mines[k][l]==1){
                                tanda++;
                                }
                        }
                }
        if(tanda==32){
                break;
                }
        printf("%s pilih banyak lubang yang akan di isi(hanya bisa mengisi maksimal 4 lubang)\n",player2);
        scanf("%d",&lubang);
        for(k=1;k<=lubang;k++){
                printf("pilih nomor lubang yang akan diisi");
                scanf("%d",&isi);
                mines[1][isi]=1;
                }
        printf("%s pilih lubang yang akan di tebak",player1);
	 for(k=1;k<=4;k++){
                scanf("%d",&tebak);
                if(mines[1][tebak]==1) scorep2++;
                else scorep1++;
                }
	point();
        status=0;
        }
        printf("Permainan Selesai");
        point();
        if(scorep1>scorep2){
        printf("Pemain pertama %s menang\n",player1);
        }
        else if(scorep2>scorep1){
        printf("Pemain kedua %s menang\n",player2);
        }
        else{
        printf("Permainan seri\n");
        }
        status=999;
	return NULL;
}

int main(){
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<16;j++){
			mines[i][j]=0;
		}
	}

	printf("Masukkan Nama pemain pertama dan pemain kedua  : ");
	scanf("%s %s", player1,player2);

	pthread_create(&(p1),NULL,&turnp1, NULL);
	pthread_create(&(p2),NULL,&turnp2, NULL);

	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	return 0;
}
 
