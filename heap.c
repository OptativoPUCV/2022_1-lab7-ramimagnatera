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

  if (pq->size == pq->capac){
    pq->heapArray = (heapElem*) realloc (pq->heapArray, (pq->capac * 2 * sizeof(heapElem))+1);
    pq->capac = pq->capac*2+1;
  }
  
  int cont = pq->size;
  pq->heapArray[cont].data = data;
  pq->heapArray[cont].priority = priority;

  while(pq->heapArray[cont].priority > pq->heapArray[(cont-1)/2].priority){
    heapElem aux;
    aux.priority = pq->heapArray[cont].priority;
    aux.data = pq->heapArray[cont].data;

    pq->heapArray[cont].priority = pq->heapArray[(cont-1)/2].priority;
    pq->heapArray[cont].data = pq->heapArray[(cont-1)/2].data;

    pq->heapArray[(cont-1)/2].priority = aux.priority;
    pq->heapArray[(cont-1)/2].data = aux.data;
    cont = (cont-1)/2;
  }
  pq->size++;
}

void heap_pop(Heap* pq){
  heapElem aux;
  int pos = 0;
  
  pq->heapArray[0] = pq->heapArray[pq->size];
  pq->heapArray[pq->size].priority = 0;
  pq->heapArray[pq->size].data = NULL;
  
  while(pq->heapArray[pos].priority < pq->heapArray[pos*2+1].priority || pq->heapArray[pos].priority < pq->heapArray[pos*2+2].priority){
    
    if(pq->heapArray[pos*2+1].priority < pq->heapArray[pos*2+2].priority){
      aux = pq->heapArray[0];
      pq->heapArray[0] = pq->heapArray[pos*2+2];
      pq->heapArray[pos*2+2] = aux;
      pos = pos*2+2;
    }
    else{
      aux = pq->heapArray[0];
      pq->heapArray[0] = pq->heapArray[pos*2+1];
      pq->heapArray[pos*2+1] = aux;
      pos = pos*2+1;
    }
  }
  pq->size--;
}

Heap* createHeap(){
  Heap * h = (Heap*) malloc(sizeof(Heap));
  h->heapArray = (heapElem*) malloc(3 * sizeof(heapElem));
  
  h->size = 0;
  h->capac = 3;
  return h;
}
