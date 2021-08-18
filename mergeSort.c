#include <stdio.h>


void mergeSort(int slot[], int n, int m);
void merge(int slot[], int n, int m);

int main() {
    
    int i,n;
    printf("Number of #s: ");
    scanf("%d",&n);
    int slot[n];
    printf("Enter #s to be sorted: ");
    for(i = 0; i < n; i++)
        scanf("%d", &slot[i]);
    
    mergeSort(slot,0,n-1);
    
    printf("After Sorting: ");
    for(i = 0; i < n; i++)
        printf("%d ", slot[i]);
    printf("\n");
    return 0;
}

void mergeSort(int slot[], int n, int m){
    //base case
    if(m <= n)
        return;
    else if (m-n > 1){ // list w 2 or more members
        int mid = (n+m)/2;
        mergeSort(slot,n, mid);
        mergeSort(slot,mid+1, m);
    }
    merge(slot,n,m);
}

void merge(int slot[], int n, int m){
    //no need merge list if m and n is pointing to same element
    if(m <= n)
        return;
    int i;
    
    // div the list into halves (alr sorted halves)
    int a = n, b = ((n+m)/2) +1;
    
    while(b>a){
        //cmp 1st elements of both halves (1 key cmp)
        if(slot[a] < slot[b])
            a++;
        else if (slot[a] > slot[b]){
            //bring 1b to the front of 1a and push the rest backwards
            int temp = slot[b];
            //shifting backwards
            for(i = b-1; i >= a; i--)
                slot[i+1] = slot[i];
            slot[a] = temp;
        }
        else{ //1a == 1b
            //if there are last elements
            if(slot[a] == slot[b])
                break; //since they alr in sorted position, dunnid do anything else once u cffm they are ==
            else{
                //bring 1b to the back of 1a and push the rest backwards
                int temp = slot[b];
                //shifting backwards
                for(i = b-1; i >= a+1; i--)
                    slot[i+1] = slot[i];
                slot[a+1] = temp;
            }
        }
    }
    
}
