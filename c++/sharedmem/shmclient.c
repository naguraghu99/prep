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
	//key is nothing but unique id thats associcated with shared memory
	//This is key is known only to processes that shared the shared memory
	key_t semkey, shmkey;
	semkey = ftok(SEMKEYPATH,SEMKEYID);
	shmkey = ftok(SHMKEYPATH,SHMKEYID);

	semid = semget( semkey, NUMSEMS, 0666);
	shmid = shmget(shmkey, SIZEOFSHMEM, 0666);

	shm_address = shmat(shmid, NULL, 0);
	while(1){
		m.type = 0;
		m.slno = 0;
		m.pid = getpid();
		m.slno++;
		int a,b;
		printf("Enter a: ");
		scanf("%d",&a);
		m.a = a;
		printf("\nEnter b: ");
		scanf("%d",&b);
		m.b = b;

		//acquire the semaphore and copy the message to the shared memory
		operations[0].sem_num = 0;/* Operate on the first sem      */
		operations[0].sem_op =  0;/* Wait for the value to be=0    */
		operations[0].sem_flg = 0;/* Allow a wait to occur         */
		operations[1].sem_num = 0;/* Operate on the first sem      */
		operations[1].sem_op =  1;/* Increment the semval by one   */
		operations[1].sem_flg = 0;/* Allow a wait to occur         */
		printf("Before semop\n");
		rc = semop( semid, operations, 2 );
		printf("after semop\n");
		memcpy((char *)shm_address,&m, sizeof(m));

		operations[0].sem_num = 0;/* Operate on the first sem      */
		operations[0].sem_op =  -1;/* Decrement the semval by one   */
		operations[0].sem_flg = 0;/* Allow a wait to occur         */

		operations[1].sem_num = 1;/* Operate on the second sem     */
		operations[1].sem_op =  1;/* Increment the semval by one   */
		operations[1].sem_flg = 0;/* Allow a wait to occur         */

		rc = semop( semid, operations, 2 );
	}
	rc = shmdt(shm_address);
	return 0;
}

