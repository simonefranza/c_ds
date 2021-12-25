#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "heap.h"

// Static functions
static void heapify(Heap *heap);
static void siftDown(int *data, int start, int end, HEAP_TYPE type);
static void siftUp(int *data, int start, int end, HEAP_TYPE type);
static int idxParent(int i);
static int idxLeftChild(int i);

// Creation
Heap *createHeap(int size, HEAP_TYPE type) {
  Heap *heap = (Heap*)calloc(sizeof(Heap), 1);
  heap->size = 0;
  heap->capacity = size;
  heap->data = (int *)calloc(sizeof(int), size);
  heap->type = type;
  return heap;
}

Heap *createHeapFromData(int *data, int size, HEAP_TYPE type) {
  Heap *heap = (Heap*)calloc(sizeof(Heap), 1);
  heap->size = size;
  heap->capacity = size;
  heap->data = (int *)calloc(sizeof(int), size);
  memcpy(heap->data, data, sizeof(int)*size);
  heap->type = type;
  heapify(heap);
  return heap;
}

// Basic
int peek(Heap *heap) {
  return heap->data[0];
}
Heap *push(Heap *heap, int value) {
  if(heap->size == heap->capacity) {
    int *temp = (int*)realloc(heap->data, sizeof(int)*(heap->capacity + 100));
    if(!temp) {
      printf("No more memory\n");
      free(heap);
      return NULL;
    }
    heap->data = temp;
    heap->capacity += 100;
  }
  heap->data[heap->size++] = value;
  siftUp(heap->data, 0, heap->size - 1, heap->type);
  return heap;
}

int pop(Heap *heap) {
  int ret = heap->data[0];
  heap->data[0] = heap->data[heap->size - 1];
  heap->data[heap->size - 1] = 0;
  heap->size--;
  siftDown(heap->data, 0, heap->size - 1, heap->type);
  return ret;
}

// Inspection
int isEmpty(Heap *heap) {
  return heap->size == 0;
}

// Misc
void printHeap(Heap *heap) {
  for(int i = 0; i < heap->size; i++) {
    printf("%d", heap->data[i]);
    if(i < heap->size-1)
      printf(" -> ");
  }
  putchar('\n');
}

// Internals
static void heapify(Heap *heap) {
  int *data = heap->data;
  int size = heap->size;
  int start = idxParent(size - 1);
  while(start >= 0) {
    siftDown(data, start, size - 1, heap->type);
    start--;
  }
}

static void siftDown(int *data, int start, int end, HEAP_TYPE type) {
  int root = start;
  while(idxLeftChild(root) <= end) {
    int child = idxLeftChild(root);
    int swap = root;
    if((type == MAX_HEAP && data[swap] < data[child]) || 
        (type == MIN_HEAP && data[swap] > data[child]))
      swap = child;
    if((type == MAX_HEAP && child + 1 <= end && data[swap] < data[child + 1]) ||
        (type == MIN_HEAP && child + 1 <= end && data[swap] > data[child + 1]))
      swap = child + 1;
    if(swap == root)
      return;
    int temp = data[root];
    data[root] = data[swap];
    data[swap] = temp;
    root = swap;
  }
}

static void siftUp(int *data, int start, int end, HEAP_TYPE type) {
  int child = end;
  while(child > start) {
    int parent = idxParent(child);
    if(!((type == MAX_HEAP && data[parent] < data[child]) ||
      (type == MIN_HEAP && data[parent] > data[child]))) 
      return;
    int temp = data[parent];
    data[parent] = data[child];
    data[child] = temp;
    child = parent;
  }
}

static int idxParent(int i) {
  return floor((i - 1) /2.0);
}

static int idxLeftChild(int i) {
  return 2 * i + 1;
}


