#include<stdio.h>

int main()
{
    FILE *p;
    char array[20][256];
    p = popen("grep print server.c", "r");

    if(!p) {
        fprintf(stderr, "Error opening pipe.\n");
        return 1;
    }
    int i=0;
    while(!feof(p)) {
        fgets(array[i],256,p);
	i++;
    }
   
   int j = 0;
   while(j < i){
    	printf("%s",array[j]);
	j++;
    }

    if (pclose(p) == -1) {
        fprintf(stderr," Error!\n");
        return 1;
    }

    return 0;
}
