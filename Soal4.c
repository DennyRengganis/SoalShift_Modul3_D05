    #include<stdio.h>
    #include<string.h>
    #include<pthread.h>
    #include<stdlib.h>
    #include<unistd.h>
    #include<stdlib.h>
     
    pthread_t tid[32];
     
    void *facto(void *arg)
    {
    	long long int ans,init,i;
    	init=(long long int)arg;
    	ans=1;
    	for (i=2;i<=arg;i++)
    	ans=ans*i;
    	printf("Hasil %lld! = %lld\n",init, ans);
    }
     
    int main()
    {
    	char C[12];
    	char space;
    	int num[52];
    	int input,i,j,status,temp,min,index;
    	input=0;
    	//printf("./faktorial ");
    	scanf("%s",&C);
    	while(1)
    	{
    		scanf("%d%c",&num[input], &space);
    		input++;
    		if (space=='\n')
    		break;
    	}
    	for (i=0;i<input;i++) {
    		min=num[i];
    		index=i;
    		for (j=i+1;j<input;j++) {
    			if (num[j]<min) {
    				index=j;
    				min=num[j];
    			}
    		}
    		temp=num[i];
    		num[i]=num[index];
    		num[index]=temp;
    	}
    	i=0;
    	while(1)
    	{
    		if (i==input)
    		break;
    		status=pthread_create(&(tid[i]),NULL,facto,(void*) num[i]);
    		if (status) {
    			printf("Thread Error\n");
    			exit(EXIT_FAILURE);
    		}
    		i++;
    	}
    	for (i=0;i<input;i++)
    	pthread_join(tid[i],NULL);
    	exit(EXIT_SUCCESS);
    	return 0;
    }
