#include <iostream>
#include "solution.h"
using namespace std;

//MERGE ARRAYS CODE FROM GFG
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;
 
    // Traverse both array
    while (i<n1 && j <n2)
    {
        // Check if current element of first
        // array is smaller than current element
        // of second array. If yes, store first
        // array element and increment first array
        // index. Otherwise do same with second array
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
 
    // Store remaining elements of first array
    while (i < n1)
        arr3[k++] = arr1[i++];
 
    // Store remaining elements of second array
    while (j < n2)
        arr3[k++] = arr2[j++];
}

//SELF
void createHalves(int h1[], int h2[], int s1, int s2, int original[])
{
    
    for ( int i = 0; i < s1; i++ )
        h1[i] = original[i];
    for ( int j = 0; j < s2; j++ )
        h2[j] = original[s1 + j];    
}


void mergeSort(int input[], int size){
  
    if (size == 0 or size == 1)
        return;
    else
    {
        const int size1 = size/2 ;
        const int size2 = size - (size/2) ;
        
        int half1[size1];
        int half2[size2];
        createHalves(half1, half2, size1, size2, input);
        
        mergeSort(half1, sizeof(half1)/sizeof(int) );
        mergeSort(half2, sizeof(half2)/sizeof(int) );
        
        mergeArrays(half1, half2, size1, size2, input);
    }
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}

