#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main()
{
        int status;
        if (fork() == 0)
        {
                printf("Hello from Child!\n");
                key_t key = ftok("shmfile",65);

                // shmget returns an identifier in shmid
                int shmid = shmget(key,1024,0666|IPC_CREAT);

                // shmat to attach to shared memory
                char *str = (char*) shmat(shmid,NULL,0);

                printf("Write Data : ");
                scanf("%s",str);

                printf("Data written in memory: %s\n",str);

                //detach from shared memory
                shmdt(str);


        }
        else
        {
                wait(&status);
                printf("Hello from Parent!\n");
                key_t key = ftok("shmfile",65);

                // shmget returns an identifier in shmid
                int shmid = shmget(key,1024,0666|IPC_CREAT);

                // shmat to attach to shared memory
                char *str = (char*) shmat(shmid,NULL,0);

                printf("Data read from memory: %s\n",str);

                //detach from shared memory
                shmdt(str);

                // destroy the shared memory
                shmctl(shmid,IPC_RMID,NULL);
        }
        return 0;
}
