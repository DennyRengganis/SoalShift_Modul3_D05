    #include<stdio.h>
    #include<string.h>
    #include<pthread.h>
    #include<stdlib.h>
    #include<unistd.h>
    #include<stdlib.h>
     
    pthread_t tid[12];
     
    void *carikata(void *arg)
    {
     
    }
     
    int main()
    {
    	char A[8],B;
    	char C[15][15];
    	int input,i;
    	input=0;
    	scanf("%s",&A);
    	while(1)
    	{
    		scanf("%s%c",&C[input], &B);
    		input++;
    		if (B=='\n')
    		break;
    	}
    	for (i=0;i<input;i++) {
    		pthread_create(&(tid[i]),NULL,carikata,(void*) C[i]);
    		pthread_join(tid[i],NULL);
    	}
    	return 0;
    }
