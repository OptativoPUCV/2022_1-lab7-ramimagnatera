#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
}Heap;

void* heap_top(Heap* pq){
  if(pq->size == 0) return NULL;
  return pq->heapArray[0].data;
}

void heap_push(Heap* pq, void* data, int priority){
  /*
  if (pq->size == pq->capac){
    pq->heapArray = (heapElem*) realloc(pq->heapArray, sizeof())
  }
  */
}

void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap * h = (Heap*) malloc(sizeof(Heap));
  h->heapArray = (heapElem*) malloc(3 * sizeof(heapElem));
  
  h->size = 0;
  h->capac = 3;
  return h;
}
