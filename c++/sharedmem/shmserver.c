/* This program is of client  
   A client writes a message m of type 1 into shared memory by acquiring sizeof(m) bytes from S. A client can write several messages into shared memory at one time.But as soon as a client completes writing, control is given to server to read a message from the shared memory

 */

#define NUMSEMS 2
#define SIZEOFSHMEM 1024

#include "message.h"

int main(int argc, char *argv[])
{
	//Need to get access to the shared memory by using shmget
	//Need to use semaphores for provide locking mechanism
	void         *shm_address;
	int semid, shmid, rc;
	message m;
	struct sembuf operations[2];
	struct shmid_ds shmid_struct;
	//key is nothing but unique id thats associcated with shared memory
	//This is key is known only to processes that shared the shared memory
	key_t semkey, shmkey;
	semkey = ftok(SEMKEYPATH,SEMKEYID);
	shmkey = ftok(SHMKEYPATH,SHMKEYID);

	while(1){
		semid = semget( semkey, NUMSEMS, 0666 | IPC_CREAT | IPC_EXCL);
		if(semid < 0){
			printf("SystemCall failed Error no is %s\n",strerror(errno));
			if(EEXIST == errno){
				semid = semget( semkey, NUMSEMS, 0666);
			}
		}
		shmid = shmget(shmkey, SIZEOFSHMEM, 0666| IPC_CREAT | IPC_EXCL);
		if(shmid < 0){
			printf("SystemCall failed Error no is %s\n",strerror(errno));
			if(EEXIST == errno){
				shmid = shmget(shmkey, SIZEOFSHMEM, 0666);
			}
		}


		shm_address = shmat(shmid, NULL, 0);
		/* Set the structure passed into the semop() to first wait   */
		/* for the second semval to equal 1, then decrement it to    */
		/* allow the next signal that the client writes to it.       */
		/* Next, set the first semaphore to equal 1, which means     */
		/* that the shared memory segment is busy.                   */
		printf("Ready for client jobs\n");
		operations[0].sem_num = 1;/* Operate on the second sem     */
		operations[0].sem_op = -1;/* Decrement the semval by one   */
		operations[0].sem_flg = 0;/* Allow a wait to occur         */
		operations[1].sem_num = 0;/* Operate on the first sem      */
		operations[1].sem_op =  1;/* Increment the semval by 1     */
		operations[1].sem_flg = IPC_NOWAIT;/* Do not allow to wait    */

		rc = semop( semid, operations, 2 );
		memcpy(&m, (char *)shm_address, sizeof(m));
		printf("Total is %d\n",m.a+m.b);

		/* Signal the first semaphore to free the shared memory.     */
		operations[0].sem_num = 0;
		operations[0].sem_op  = -1;
		operations[0].sem_flg = IPC_NOWAIT;

		printf(" before semop\n");
		rc = semop( semid, operations, 1);
	}
	rc = semctl( semid, 1, IPC_RMID );

	rc = shmdt(shm_address);
	rc = shmctl(shmid, IPC_RMID, &shmid_struct);
	return 0;
}

