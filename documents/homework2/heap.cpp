#include <iostream>
#include "heap.h"
using namespace std;

template<class elemType>
void arrayListType<elemType>::heapify(int low, int high)
{
  int largeIndex;
  elemType temp = list[low]; //copy the root node of the subtree
  largeIndex = 2 * low + 1; //index of the left child
  while (largeIndex <= high)
  {
    if (largeIndex < high)if (list[largeIndex]< list[largeIndex + 1])
      largeIndex = largeIndex + 1; //index of the largest child
    if (temp > list[largeIndex]) //subtree is already in a heap
      break;
    else{list[low]= list[largeIndex]; //move the larger child to the root
         low = largeIndex; //go to the subtree to restore the heap
         largeIndex = 2 * low + 1;}
        }//end while
  
  list[low]= temp; //insert temp into the tree, that is, list
}//end heapify

template <class elemType>
void arrayListType<elemType>::buildHeap()
{
  for (int index = length / 2 - 1; index >= 0; index--)
    heapify(index, length - 1);
}

int main(){

}
