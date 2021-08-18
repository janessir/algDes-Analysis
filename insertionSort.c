#include <stdio.h>


void insertionSort(int slot[], int n);

int main() {
    
    int i,n;
    printf("Number of #s: ");
    scanf("%d",&n);
    int slot[n];
    printf("Enter #s to be sorted: ");
    for(i = 0; i < n; i++)
        scanf("%d", &slot[i]);
    
    insertionSort(slot,n);
    
    printf("After Sorting: ");
    for(i = 0; i < n; i++)
        printf("%d ", slot[i]);
    printf("\n");

    return 0;
}

void insertionSort(int slot[], int n){
    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if(slot[j] > slot[j+1]){
                int temp = slot[j+1];
                slot[j+1] = slot[j];
                slot[j] = temp;
            }
            else break; //break once you find a # smaller than you coz then you alr find the pos to insert + beyonf tt, the list is alr sorted
        }
    }
}
