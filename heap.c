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
} Heap;

void* heap_top(Heap* pq){
  
  return NULL;
}

void heap_push(Heap* pq, void* data, int priority){

}

void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap * h = (Heap*) malloc(sizeof(Heap));
  heapElem * harray = (heapElem*) malloc(3 * sizeof(heapElem));
  harray->data = NULL;
  harray->priority = NULL;
  h->size = 0;
  h->capac = 3;
  return h;
}