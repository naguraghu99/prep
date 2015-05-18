#include <stdio.h>
int main(void)
{
    int arr[] = {10, 20};
    int *p = arr;
    printf("arr[0] = %d, arr[1] = %d, *p = %d\n", arr[0], arr[1], *p);
    *p++;
    printf("arr[0] = %d, arr[1] = %d, *p = %d\n", arr[0], arr[1], *p);
    return 0;
}

