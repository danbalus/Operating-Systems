#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "a2_helper.h"
#include <pthread.h> 
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <semaphore.h>

//int k,i;
//#define NTHREADS 5
//pthread_t thread_id[NTHREADS];
//pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
//pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;

pthread_t thread1, thread2, thread3, thread4, thread5;
pthread_t thread1_s, thread2_s, thread3_s, thread4_s;

int vec[37], vec8[5], vec7[6];
int sem_id, sem_id2;
pthread_t th[37], th8[5], th7[6];
//struct sembuf op = {0, 0, 0};

void P(int semId, int semNr)
{
	struct sembuf op = {semNr, -1, 0};
	semop(semId, &op, 1);
}

void V(int semId, int semNr)
{
	struct sembuf op = {semNr, 1, 0};
	semop(semId, &op, 1);
}

void* execThread1(void* threadName)
{
    
    int* nr_thread = (int*) malloc (sizeof(int));
    //char* tmp;
     	
	  
	  
    if(strcmp(threadName, "1") == 0)
    {
		//pthread_mutex_lock( &mutex1 );
    	
    	
		//for(;;)
    	//{
    		info(BEGIN, 7 ,1);
    		pthread_create(&thread3, NULL, execThread1, "3");
    		//pthread_cond_signal(&cond);
    	//}
		//pthread_mutex_unlock( &mutex1 );

    }
    else if(strcmp(threadName, "2") == 0)
    {
    	info(BEGIN, 7 ,2);
    	
    }
    else if(strcmp(threadName, "3") == 0)
    {
    	//pthread_mutex_lock( &mutex1 );
    	//for(;;)
    	//{
    		//pthread_cond_wait(&cond, &mutex1);
    		info(BEGIN, 7 ,3);
    	//}
    	
    	
    	//pthread_mutex_unlock( &mutex1 );

    }
    
    else if(strcmp(threadName, "4") == 0)
    {
    	info(BEGIN, 7 ,4);
    }
    else if(strcmp(threadName, "5") == 0 )
    {
    	P(sem_id2, 0);
    	info(BEGIN, 7 ,5);
    }
	
    *nr_thread = atoi(threadName);
    
    
    return nr_thread;
}

/*
void thread_function_create()
{//
	//pthread_mutex_lock( &mutex1 );
	//pthread_cond_signal(&cond);
	//pthread_create(&thread1, NULL, execThread1, "1");
	//pthread_create(&thread2, NULL, execThread1, "2");
	//pthread_create(&thread3, NULL, execThread1, "3");
	//pthread_create(&thread4, NULL, execThread1, "4");
	////pthread_create(&thread5, NULL, execThread1, "5");
	//
	if (pthread_create(&thread1, NULL, execThread1, "1")!=0) 
	{
		printf("eroare thread1");
		exit(1);
	}
	//pthread_mutex_unlock( &mutex1 );
		    	
	if (pthread_create(&thread2, NULL, execThread1, "2")!=0) {
		printf("eroare thread2");
		exit(1);
	}
		    	
	//if (pthread_create(&thread3, NULL, execThread1, "3")!=0) {
	//	printf("eroare thread3");
	//	exit(1);
	//}
	//pthread_cond_wait(&cond, &mutex1);
		    	
	if (pthread_create(&thread4, NULL, execThread1, "4")!=0) {
		printf("eroare thread4");
		exit(1);
	}
		    	
	if (pthread_create(&thread5, NULL, execThread1, "5")!=0) {
		printf("eroare thread5");
		exit(1);
	}

	pthread_join(thread5, NULL);

	info(END, 7, 5);
	V(sem_id2, 1);

	pthread_join(thread3, NULL);
	info(END, 7, 4);
		        
	pthread_join(thread4, NULL);
	info(END, 7, 2);
		        
	pthread_join(thread2, NULL);
	info(END, 7, 3);

	pthread_join(thread1, NULL);             
	info(END, 7, 1);
	//pthread_mutex_unlock( &mutex1 );
}


*/

//pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

	
/*
	void *thread_function2(void* indice)
	{
		int* nr_thread = (int*) malloc (sizeof(int));
		char* ii=((char*) indice);
		nr_thread = atoi(ii);
	   //pthread_mutex_lock( &mutex1 );
	   info(BEGIN, 7, *nr_thread);
	   printf("\nnr_thread:%d\n",*nr_thread);
	  // pthread_mutex_unlock( &mutex1 );
	   return nr_thread;
	}

//void* thFunction(void* arg) {
//	int* val = (int*) arg;
//}

void thread_function()
{
	
	//int i;
	//for(i = 0; i < NTHREADS; i++)
	//{
	//	k = i + 1;
	  	pthread_create( &thread1, NULL, thread_function2, "1" );
	    pthread_create( &thread2, NULL, thread_function2, "2" );
	    pthread_create( &thread3, NULL, thread_function2, "3" );
	    pthread_create( &thread4, NULL, thread_function2, "4" );
	    pthread_create( &thread5, NULL, thread_function2, "5" );
	//}
	///for(int j = 0; j < NTHREADS; j++)
	//{
	//    pthread_join( thread_id[j], NULL);
	//    info(END, 7, j+1);
	//}
}
//printf("Thread with argument %d\n", *val);
*/
/*
#define MAX_TH  36

pthread_mutex_t lock;
pthread_cond_t cond;

int N, M;


int thNo = 0;
void* limitedArea()
{
    //int th_id = *((int*) arg);
    
    // Check if entrance in the limited area is allowed
    if (pthread_mutex_lock(&lock) != 0) {
    	perror("Cannot take the lock");
    	exit(4);
    }

    while (thNo > M) // if already M inside, the wait
		if (pthread_cond_wait(&cond, &lock) != 0) 
		{
			perror("Cannot wait for condition");
			exit(6);
		}
    

    thNo++;
	
    if (pthread_mutex_unlock(&lock) != 0) 
    {
    	perror("Cannot release the lock");
    	exit(5);
    }


    printf("The no of threads in the limited area is: %d\n", thNo);
    //usleep(100);

	
    // Check if exit from the limited area is allowed
    if (pthread_mutex_lock(&lock) != 0) {
    	perror("Cannot take the lock");
    	exit(4);
    }
    //if(thNo == M)

    thNo--;

    // signal that a new place is available
    if (pthread_cond_signal(&cond)  != 0) {
    	perror("Cannot signal the condition waiters");
    	exit(7);
    }
    
    //info(END,4,thNo);
    if (pthread_mutex_unlock(&lock) != 0) {
    	perror("Cannot release the lock");
    	exit(5);
    }

    return NULL;
}
void bariera()
{
	 N = 36;
	    M = 6;

	    // Create the lock to provide mutual exclusion for the concurrent threads
	    if (pthread_mutex_init(&lock, NULL) != 0) {
	    	perror("Cannot initialize the lock");
	    	exit(2);
	    }
		
	    if (pthread_cond_init(&cond, NULL) != 0) {
	    	perror("Cannot initialize the condition variable");
	    	exit(3);
	    }

	    int i;
	    pthread_t th[MAX_TH];
	    //int th_args[MAX_TH];
	    
	    // Create the N threads
	    for (i=1; i <= N; i++) {
	        //th_args[i] = i;
	        info(BEGIN, 4, i);
	        if (pthread_create(&th[i], NULL, limitedArea, NULL)) {
	            perror("cannot create threads");
	            exit(4);
	        }
	    }

	    // Wait for the termination of the N threads created
	    for (i = 1; i <= N; i++) {
	        pthread_join(th[i], NULL);
	    }
	    for (i = 1; i <= N; i++) {
	        info(END, 4, i);
	    }

	    // Remove the lock
	    if (pthread_mutex_destroy(&lock) != 0) {
	    	perror("Cannot destroy the lock");
	    	exit(8);
	    }
		
	    if (pthread_cond_destroy(&cond) != 0) {
	    	perror("Cannot destroy the condition variable");
	    	exit(9);
	    }
}
*/

/*
void* execThread2(void* threadName)
{
    
    int* nr_thread = (int*) malloc (sizeof(int));
     
    if(strcmp(threadName, "1") == 0)
    {
    	info(BEGIN, 8 ,1);
    	info(END, 8 ,1);
    }
    else if(strcmp(threadName, "2") == 0)
    {
    	info(BEGIN, 8, 2);
    	info(END, 8 ,2);
    }
    else if(strcmp(threadName, "3") == 0)
    {
    	P(sem_id2, 1);
    	info(BEGIN, 8, 3);
    	info(END, 8 ,3);
    }
    
    else if(strcmp(threadName, "4") == 0)
    {
    	info(BEGIN, 8, 4);
    	info(END, 8 ,4);
    	V(sem_id2, 0);

    }
	
    *nr_thread = atoi(threadName);
    
    
    return nr_thread;
}

void semafor()
{
		pthread_create( &thread1_s, NULL, execThread2, "1" );
	    pthread_create( &thread2_s, NULL, execThread2, "2" );
	    pthread_create( &thread3_s, NULL, execThread2, "3" );
	    pthread_create( &thread4_s, NULL, execThread2, "4" );
}


*/
void* functie_proces_4(void* args)
{
	int i = *((int*) args);
	P(sem_id, 0);
	info(BEGIN, 4, i);
	info(END, 4, i);
	V(sem_id, 0);
	return NULL;
}

void* functie_proces_8(void* args)
{
	int i = *((int*) args);
	//P(sem_id, 0);
	//if( i == 4)
	//{
	//	P(sem_id2, 0);
	//}
	if( i == 4)
	{
		//P(sem_id2, 0);
		info(BEGIN, 8, 4);
		info(END, 8, 4);
		V(sem_id2, 0);
	
	}
	
	else if( i == 3)
	{
		P(sem_id2, 1);
		info(BEGIN, 8, 3);
		info(END, 8, 3);
		//V(sem_id2, 1);
	}
	else
	{
		info(BEGIN, 8, i);
		info(END, 8, i);
	}

	return NULL;
}

void* functie_proces_7(void* args)
{
	int i = *((int*) args);
	//P(sem_id, 0);
	if (i == 1)
	{
		info(BEGIN, 7, i);
		
		vec7[3] = 3;
		pthread_create(&th7[3], NULL, functie_proces_7, &(vec7[3]));

	}
	else if(i == 3)
	{
		info(BEGIN, 7, i);
		info(END, 7, i);
		info(END, 7, 1);
	}
	else if( i == 5)
	{
		P(sem_id2, 0);
		//printf("\n\n\n\nintra aici\n\n\n");
		info(BEGIN, 7, i);
		info(END, 7, i);
			V(sem_id2,1 );
		
	}
	else
	{
		info(BEGIN, 7, i);
		info(END, 7, i);
	}
	//if( i == 5)
	//{
		//V(sem_id2, 1);
	//}
	
	//V(sem_id, 0);
	return NULL;
}
//struct sembuf op = {0, 0, 0};


int main()
{
	//int pid1;
	int pid2;
	int pid3;
	int pid4;
	int pid5;
	int pid6;
	int pid7;
	int pid8;
	int pid9;
	init();
	sem_id = semget(IPC_PRIVATE, 1, IPC_CREAT);
	semctl(sem_id, 0, SETVAL, 6);


	sem_id2 = semget(IPC_PRIVATE, 2, IPC_CREAT| 0600);
	semctl(sem_id2, 0, SETVAL, 1);
	semctl(sem_id2, 1, SETVAL, 1);



	info(BEGIN, 1, 0);//----------------------|1|
	pid2 = fork();
	if( pid2 == 0)
	{
		info(BEGIN,2,0);
		pid6 = fork();
		if(pid6 == 0)
		{
			info(BEGIN, 6, 0);
			info(END, 6, 0);
			exit(1);
		}
	waitpid(pid6, NULL, 0);
	info(END, 2, 0);
	exit(1);
	}

	pid3 = fork();
	if (pid3 == 0)
	{
		info(BEGIN, 3, 0);
		pid5 = fork();
		if (pid5 == 0)
		{
			info(BEGIN, 5, 0);
			pid7 = fork();
			if(pid7 == 0)
			{
				info(BEGIN, 7, 0);

				//pthread_t th1;
				//int arg1 = 1;
				//pthread_create(&th1, NULL, thFunction, &arg1);
				//pthread_join(th1, NULL);
				//thread_function();
				
				//thread_function_create();--buna
				for(int i = 1; i <= 5; i++)
				{
					if (i != 3)
					{
						vec7[i] = i;
						pthread_create(&th7[i], NULL, functie_proces_7, &(vec7[i]));
					}
				}
				for(int i = 1; i <= 5; i++)
				{
					pthread_join(th7[i], NULL);
				}

    	
				pid8 = fork();
				if(pid8 == 0)
				{
					info(BEGIN, 8, 0);

					//semafor();


					for(int i = 1; i <= 4; i++)
					{
						vec8[i] = i;
						pthread_create(&th8[i], NULL, functie_proces_8, &(vec8[i]));
					}
					for(int i = 1; i <= 4; i++)
					{
						pthread_join(th8[i], NULL);
					}
					

					info(END, 8, 0);
					exit(1);
				}
				waitpid(pid8, NULL, 0);
				info(END, 7, 0);
				exit(1);
			}
			waitpid(pid7, NULL, 0);
			info(END, 5, 0);
			exit(1);
		}
		pid9 = fork();
		if (pid9 == 0)
		{
			info(BEGIN, 9, 0);
			info(END, 9, 0);
			exit(1);
		}
		waitpid(pid5, NULL, 0);
		waitpid(pid9, NULL, 0);
		info(END, 3, 0);
		exit(1);
	}
	pid4 = fork();

	if(pid4 == 0)
	{

		info(BEGIN, 4, 0);
		
		//bariera();
	   //////////////////////////////////
		for(int i=1; i<=36; i++)
		{
			vec[i] = i;
			pthread_create(&th[i], NULL, functie_proces_4, &(vec[i]));
		}
		for(int i=1; i<=36; i++)
		{
			pthread_join(th[i], NULL);
		}
		

		info(END, 4, 0);
		exit(1);
	}
	waitpid(pid2, NULL, 0);
	waitpid(pid3, NULL, 0);
	waitpid(pid4, NULL, 0);
	info(END, 1, 0);
	exit(1);
	return 0;
}
/*
int main()
{
	// tester initialization
	// only one time in the main process
		        		//printf("AICI");

	init();
	int pid2 = fork();
	info(BEGIN, 2, 0);//----------------------|2|
	int pid1;
	int pid3;
	int pid4;
	int pid5;
    int pid6;
    int pid7;
    int pid8;
    int pid9;

	if (pid2 == 0)
	{
		pid6 = fork();
		info(BEGIN, 6, 0);//--------------------------|6|
		info(END, 6, 0);  //--------------------------|END 2|
		exit(1);

		waitpid(pid6, NULL, 0);
		info(END, 2, 0);  //--------------------------|END 2|
		exit(1);
	}
	
	else
	{//pid2>0

		pid3 = fork();
		info(BEGIN, 3, 0);//---------------------------------|3|
		if(pid3 == 0)
		{
			pid5 = fork();
			info(BEGIN, 5, 0);//-----------------------------|5|
			if(pid5 == 0)
			{
				pid7 = fork();
				info(BEGIN, 7, 0); //-------------------------|7|
				if (pid7 == 0)
				{
					pid8 = fork();
					info(BEGIN, 8, 0);   //-------------------|8|
	       			info(END, 8, 0); //-----------------------|END 8|
        			exit(1);  
     	    			
				}
				info(END, 7, 0);  //--------------------------|END 7|
				waitpid(pid8, NULL, 0);
				exit(1);
			}
			else
			{//pid5>0
				pid9 = fork();
				info(BEGIN, 9, 0);   //------------------------|9|
	       		info(END, 9, 0); //----------------------------|END 9|
        		exit(1); 
			}
			info(END, 6, 0); //-----------------------|END 6|
			//exit(1);
			info(END, 5, 0);  //-------------------------------|END 5|
			waitpid(pid7, NULL, 0);
			exit(1);

		}
		else
		{//pid3>0

			info(BEGIN, 4, 0); //------------------------|4|
			pid4 = fork();
			if (pid4 > 0)
			{
				pid1 = fork();
				info(BEGIN, 1, 0);   //------------------------|1|
			}
	        info(END, 4, 0);//----------------------------|END 4|
	        exit(1);

		}
		
		waitpid(pid5, NULL, 0);
		waitpid(pid9, NULL, 0);
		info(END, 3, 0);  //-----------------------------------|END 3|
		exit(1);


	}
	

	waitpid(pid2, NULL, 0);
	waitpid(pid3, NULL, 0);
	waitpid(pid4, NULL, 0);
	info(END, 1, 0);  //--------------------------|END 1|
	exit(1);

return 0;
}*/
/*
//---------------------------------------------------------------------------------
//------------------------------------------------------------------------------------	       	
	       	int  pid2 = fork();
	       	if (pid2 == 0)  //--------------------------|6|
	   		{
	       		printf("AICI2");
	       		//exit(0); 
	       		
	        	 
	    	}//-----------------------------------------|END 6|
	   		waitpid(pid2, NULL, 0);
	   		info(END, 2, 0);
	   		exit(1); 

	    }//---------------------------------------------|END 2|

	   	if (pid == 0 ) //----------------------|3|
	   	{
	       	info(BEGIN, 3, 0);
	       	for(int j = 0; j < 2; j++)
        	{
	        	int  pid3 = fork();
	       		if (pid3 == 0 && j == 0)  //------------|5|
		   		{
		       		info(BEGIN, 5, 0);
		       		int  pid5 = fork();
	        		if (pid5 == 0)  //------------------|7|
    				{	        				 
	        			info(BEGIN, 7, 0);
						int  pid7 = fork();
						if (pid7 == 0)  //--------------|8|
	   					{
	       				 
	       					info(BEGIN, 8, 0);
	       					info(END, 8, 0); 
        					exit(1);  
     	    			}//-----------------------------|END 8|

	       				info(END, 7, 0); 
	       				exit(1); 
  
	   				}//---------------------------------|END 7|
				info(END, 5, 0);
				exit(1); 
		    	}//-------------------------------------|END 5|

		    	if (pid3 == 0 && j == 1)//--------------|9|
		   		{
					info(BEGIN, 9, 0);
	       			info(END, 9, 0); 
	       			exit(1);
	    		}//-------------------------------------|END 9|	        	
	    	}
	        	
	        info(END, 3, 0);
	    }//---------------------------------------------|END 3|


	    if (pid == 0) //-----------------------|4|
	   	{
	        //printf("Child (%d): %d\n", i + 1, getpid());
	        //exit(0); 
	        info(BEGIN, 4, 0);
	        info(END, 4, 0);
	        exit(1);
	    } //---------------------------------------------|END 4|
	    //else  
	    //{
	    //	wait(NULL);
	    //}
	}	
    
    waitpid(pid, NULL, 0);
    waitpid(pid3, NULL, 0);
    waitpid(pid4, NULL, 0);
	info(END, 1, 0);//---------------------------------------|END 1|
	exit(1);

}
*/
// inform the tester about (main) process’ start
	//info(BEGIN, 1, 0);
	// other process’ actions

	// create a new process
	//if (fork() == 0) 
	//{
	// inform the tester about process’ start
	//	info(BEGIN, 2, 0);
	// other process’ actions
	// inform the tester about process’ termination
	//	info(END, 2, 0);
	//}
	// inform the tester about (main) process’ termination
	//info(END, 1, 0);
/*
int main ( int argc, char *argv[] )
{
    int i, pid;

for(i = 0; i < 9; i++) {
    pid = fork();
    if(pid < 0) {
        printf("Error");
        exit(1);
    } else if (pid == 0) {
        printf("Child (%d): %d\n", i + 1, getpid());
        exit(0); 
    } else  {
        wait(NULL);
    }
}

}
*/