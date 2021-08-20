//Q2

#include <stdio.h>

void smalLarg(int A[], int m, int n);
    
int main() {
    
    int i,n;
    printf("Number of #s: ");
    scanf("%d",&n);
    int slot[n];
    printf("Enter #s to be sorted: ");
    for(i = 0; i < n; i++)
        scanf("%d", &slot[i]);
    
    smalLarg(slot, 0, n-1);
    
    printf("Smallest #: %d\n", slot[0]);
    printf("Largest #: %d\n", slot[n-1]);
    
    return 0;
}



void smalLarg(int A[], int m, int n){
    
    //base case
    if(m>=n)
        return;
    
    //divide the array
    int mid = (n+m)/2;
    smalLarg(A, m, mid);
    smalLarg(A, mid+1, n);
    
    int temp;
    
    /*cmp first elem of each sub array
     place smallest @ the first*/
    if(A[mid+1] < A[m]){
        //swap
        temp = A[mid+1];
        A[mid+1] = A[m];
        A[m] = temp;
    }
    
    /*cmp last elem of each sub array
     place largest @ last*/
    if(A[n] < A[mid]){
        //swap
        temp = A[mid];
        A[mid] = A[n];
        A[n] = temp;
    }
}
