#include<stdio.h>

void func(int input_size)
{
  int array[input_size];

  printf("sizeof(array) = %lu \n", sizeof(array));
}

int main()
{
  int x;

  printf("Enter the input size : ");
  scanf("%d", &x);

  func(x);

  return 0;
}
