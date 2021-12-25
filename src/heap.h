typedef enum HEAP_TYPE_ {
  MIN_HEAP,
  MAX_HEAP
} HEAP_TYPE;

typedef struct Heap_ {
  int size;
  int capacity;
  int *data;
  HEAP_TYPE type;
} Heap;

// Creation
Heap *createHeap(int size, HEAP_TYPE type);
Heap *createHeapFromData(int *data, int size, HEAP_TYPE type);

// Basic
int peek(Heap *heap);
Heap *push(Heap *heap, int value);
int pop(Heap *heap);

// Inspection
int isEmpty(Heap *heap);

// Misc
void printHeap(Heap *heap);
