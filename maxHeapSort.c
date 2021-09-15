#include <stdio.h>
#include <stdlib.h>

//max Heap

static int heapSize; //actual heap size
// n : input array size

//must always take in heapSize and not n else incorrect!
void fixHeap(int H[], int n, int k, int rootI){
    //base case
    if(rootI*2 > n){
        H[rootI] = k;
        return;
    }
    //else
    int largerChildI;
    
    //dtm # of child
    if(rootI*2+1 > n){ //if 1 child
        largerChildI = rootI*2;
    }
    else{ //if 2 child
        largerChildI = H[rootI*2] >= H[rootI*2+1] ? rootI*2 : rootI*2+1;
    }
    
    //cmp children w/ k
    if(k >= H[largerChildI]){
        H[rootI] = k;
        return;
    }
    else{
        H[rootI] = H[largerChildI];
        fixHeap(H, heapSize, k, largerChildI);
    }
}

void deleteMax(int H[], int n, int rootI){
    int k = H[heapSize];
    heapSize--;
    fixHeap(H,heapSize,k,1);
}

void heapifying(int H[], int n, int rootI){
    //base
    if(rootI*2 > n)
        return;
    
    //left
    heapifying(H, n, rootI*2);
    //right
    heapifying(H, n, rootI*2+1);
    //cur
    fixHeap(H, heapSize, H[rootI], rootI); // or can use n instead of heapsort here since heapSize because as of now, heapSize is n as deleteMax is not called
    
}

void heapSort(int H[], int n){
    for(int i = n; i >= 1; i--){
        int curMax = H[1]; //get current max value
        deleteMax(H, n, i);
        H[i] = curMax;
    }
}

int main(){
    
    int n; //size of input array
    
    printf("Input size: ");
    scanf("%d", &n);
    int H[n+1];
    heapSize = n;
    
    //input
    printf("Enter your inputs: ");
    for(int i = 1; i <= n; i++)
        scanf("%d", &H[i]);
    
    //heapifying
    heapifying(H, n, 1);
    printf("\nHeapifying: \n");
    for(int i = 1; i <=n; i++)
        printf("%d ", H[i]);
    printf("\n");
    
    //heapsort
    heapSort(H, n);
    
    //result
    printf("\nAfter sorting: \n");
    for(int i = 1; i <=n; i++)
        printf("%d ", H[i]);
    printf("\n");
    
    return 0;
}
