#include <iostream>
#include <string.h>
using namespace std;
template <typename T> 
T **AllocateDynamicArray( int nRows, int nCols)
{
      T **dynamicArray;

      dynamicArray = new T*[nRows];
      for( int i = 0 ; i < nRows ; i++ )
      dynamicArray[i] = new T [nCols];

      return dynamicArray;
}

template <typename T>
void FreeDynamicArray(T** dArray)
{
      delete [] *dArray;
      delete [] dArray;
}

int main()
{
      char **my2dArr = AllocateDynamicArray<char>(4,4);
      int c = 63;
      for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
			my2dArr[i][j] = 'a';
		}
	}
      for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
			cout<<my2dArr[i][j]<<endl;
		}
	}
  
      FreeDynamicArray<char>(my2dArr);
      return 0;
}

