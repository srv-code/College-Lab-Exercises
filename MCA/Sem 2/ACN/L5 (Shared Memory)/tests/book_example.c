/*parent_child.c */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>


int main(void)
{
	 int shmid;
	 char *shmPtr;
	 int n;
	 key_t shmkey = ftok(".", 'a');
	 printf("shmkey=0x%x \n", shmkey);
	 
	 if (fork() == 0)
	 {
		 printf("child waiting... \n");
 		 sleep(2); /* UUPS */
		 printf("child woke up... \n");
		 
		 if( (shmid = shmget(shmkey, 32, 0)) == -1 )
		 { 
			exit(1);
		 }
		 printf("Child: shmid=%d \n", shmid);
		 
		 shmPtr = shmat(shmid, 0, 0);
		 printf("Child: shmPtr=%p \n", (void*) shmPtr);
		 
		 if (shmPtr == (char *) -1)
			exit(2);
		 
		 printf ("\nChild Reading ....\n\n");
		 for (n = 0; n < 26; n++)
			putchar(shmPtr[n]);
		 putchar('\n'); 
	 }
	 else
	 {
		 if( (shmid = shmget(shmkey, 32, 0666 | IPC_CREAT)) == -1 )
		 {
			exit(1);
		 }
		 printf("Parent: shmid=%d \n", shmid);
		 
		 shmPtr = shmat(shmid, 0, 0);
		 printf("Parent: shmPtr=%p \n", (void*) shmPtr);
		 
		 if (shmPtr == (char *) -1)
			exit(2);
		 
		 for (n = 0; n < 26; n++)
			shmPtr[n] = 'a' + n;
		 
		 printf ("Parent Writing ....\n\n") ;
		 for (n = 0; n < 26; n++)
			putchar(shmPtr[n]);
		 putchar('\n'); 
		 
		 wait(NULL);
		 shmdt(NULL);
		 
		 if( shmctl(shmid, IPC_RMID, NULL) == -1 )
		 {
			 perror("shmctl");
			 exit(-1);
		 }
	 }
	 exit(0);
} 