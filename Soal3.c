        #include<stdio.h>
        #include<string.h>
        #include<pthread.h>
        #include<stdlib.h>
        #include<unistd.h>
        #include<stdlib.h>
     
        int lohanhealth,kepitinghealth;
        pthread_t tid[2];
     
        void *dec(void *arg)
        {
        	int init;
        	init=(int)arg;
        	if (init==0) {
        		while(lohanhealth>0 && lohanhealth<=100)
        		{
        			sleep(10);
        			lohanhealth=lohanhealth-15;
    			printf("Status Lohan : %d\n",lohanhealth);
    			if (lohanhealth<=0)
    			printf("Lohan Telah Mati\n");    			
    			else if (lohanhealth<=15)
        			printf("Lohan Mulai Lapar\n");
        		}
        	}
        	else {
        		while(kepitinghealth>0 && kepitinghealth<=100)
        		{
        			sleep(20);
        			kepitinghealth=kepitinghealth-10;
    			printf("Status Kepiting : %d\n",kepitinghealth);
    			if (kepitinghealth<=0)
    			printf("Kepiting Telah Mati\n");
        			else if (kepitinghealth<=10)
        			printf("Kepiting Mulai Lapar\n");
        		}
        	}
        }
     
        int main()
        {
        	int status,pilihan;
        	lohanhealth=100;
        	kepitinghealth=lohanhealth;
        	status=pthread_create(&(tid[0]),NULL,dec,(void*) 0);
        	if (status) {
        		printf("Thread Lohan Error\n");
        		exit(EXIT_FAILURE);
        	}
        	status=pthread_create(&(tid[1]),NULL,dec,(void*) 1);
        	if (status) {
        		printf("Thread Kepiting Error\n");
        		exit(EXIT_FAILURE);
        	}
        	while(1)
        	{
        		system("clear");
        		printf("1. Memberi Makan Lohan\n");
        		printf("2. Memberi Makan Kepiting\n");
        		printf("Pilih Nomor : \n");
        		scanf("%d",&pilihan);
        		if (pilihan==1)
        		lohanhealth=lohanhealth+10;
        		else if (pilihan==2)
        		kepitinghealth=kepitinghealth+10;
        		if ((lohanhealth<=0 || lohanhealth>100) && (kepitinghealth<=0 || kepitinghealth>100)) {
        			printf("Lohan dan Kepiting Mati\n");
        			break;
        		}
        	}
        	exit(EXIT_SUCCESS);
        	return 0;
        }
