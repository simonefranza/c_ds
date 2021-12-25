#include <stdio.h>
#include "heap.h"

int main() {
  int arr[] = {100,36,17,7,25,19,3,2,1};
  Heap *heap = createHeapFromData(arr, 9, MAX_HEAP);
  printHeap(heap);
  while(!isEmpty(heap)) {
    printf("Popped %d\n", pop(heap));
    printHeap(heap);
  }
  Heap *heap2 = createHeapFromData(arr, 9, MIN_HEAP);
  printHeap(heap2);
  while(!isEmpty(heap2)) {
    printf("Popped %d\n", pop(heap2));
    printHeap(heap2);
  }
  Heap *heap3 = createHeap(1, MAX_HEAP);
  for(int i = 0; i < 9; i++) {
    printHeap(heap3);
    heap3 = push(heap3, arr[i]);
  }
  printHeap(heap3);
  Heap *heap4 = createHeap(1, MIN_HEAP);
  for(int i = 0; i < 9; i++) {
    printHeap(heap4);
    heap4 = push(heap4, arr[i]);
  }
  printHeap(heap4);
  return 0;
}
