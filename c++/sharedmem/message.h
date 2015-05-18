#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
 #include <errno.h>

#define SEMKEYPATH "makefile"  /* Path used on ftok for semget key  */
#define SEMKEYID 1              /* Id used on ftok for semget key    */
#define SHMKEYPATH "makefile"  /* Path used on ftok for shmget key  */
#define SHMKEYID 1              /* Id used on ftok for shmget key    */
typedef struct message{

	int type;
	int pid; //client's pid
	int slno; //incremented for every message
	int a; //any number
	int b; //any number
	int total;//total of a and b, processed by server
} message;
