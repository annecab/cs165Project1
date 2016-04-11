//
//  doalg.c
//  Project1
//
//  Created by Anne Louise on 4/3/16.
//  Copyright © 2016 Anne Louise. All rights reserved.
//

#include <stdio.h>
//#include "COMPARE.c"
int heapSize;

// Adapted Heapsort psuedocode from http://www.cc.gatech.edu/classes/cs3158_98_fall/heapsort.html

int left(int index){
    return 2 * index + 1; //return each index of the left child
}

int right(int index){
    return 2 * index + 2; //return each index of the right child
}

void minHeapify(int* A, int i){
    /*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
    /*  Inputs:                                                     */
    /*          A   :   int array    array of indices               */
    /*          i   :   int          index or current vertex        */
    /*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
    
    int leftChild = left(i);
    int rightChild = right(i);
    int smallest;
    
    if(leftChild <= heapSize && COMPARE(A[leftChild],A[i]) == 2){
        smallest = leftChild;
    }
    else{
        smallest = i;
    }
    
    if(rightChild <= heapSize && COMPARE(A[rightChild], A[smallest]) == 2 ){
        smallest = rightChild;
    }
    
    if(smallest != i){
        // we are not switching hidden, we are switching indices associated with it
        int temp = A[i];
        A[i] = A[smallest];
        A[smallest] = temp;
        
        minHeapify(A, smallest);
    }
}

void buildMaxHeap(int* A, int n){
    /*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
    /*  Inputs:                                                     */
    /*          A   :   int array   array of indices                */
    /*          n   :   int         number of element in array      */
    /*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
    
    heapSize = n - 1;
    int i;
    for(i = (n - 1) / 2; i >= 0; i--)
        minHeapify(A, i);
    
}

void heapSort(int* A, int n){
    /*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
    /*  Inputs:                                                     */
    /*          A   :   int array   array of indices                */
    /*          n   :   int         number of element in array      */
    /*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
    
    buildMaxHeap(A, n);
    
    int i;
    for(i = n - 1; i > 0; i--)
    {
        int temp = A[heapSize];
        A[heapSize] = A[0];
        A[0] = temp;
        heapSize--;
        minHeapify(A, 0);
    }
    
}

int doalg( int n, int k, int* Best ){
    /*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
    /*  Inputs:                                                     */
    /*          n       :   int     number of elements in array     */
    /*          k       :   int     first k largest elements        */
    /*          BEST    :   int     array of largest elements       */
    /*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
    
    //  initialize an array of indices
    int indices[n];
    int i;
    
    for(i = 0 ; i < n ; i++){
        indices[i] = i+1;
    }
    
    heapSort(indices, n);
    
    // take the Best k from array
    for( i = 0 ; i < k ; i++ ){
        Best[i] = indices[i];
    }
    
    
    return 1;
}