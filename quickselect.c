#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_LINE_SIZE 1000   // maximum size of a line of input
#define max 100

double duration(struct timespec start, struct timespec end) {
    return end.tv_sec - start.tv_sec
         + ((end.tv_nsec - start.tv_nsec ) / (double) 1000000000.0);
}

double getResolution(){
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    do {
        clock_gettime(CLOCK_MONOTONIC, &end);
    } while (duration(start, end) == 0.0);
    return duration(start, end);
}

int scanArray(int *a) {
    // scan line of text
    char line[MAX_LINE_SIZE];
    scanf("%[^\n]", line);

    // convert text into array
    int size = 0, offset = 0, numFilled, n;
    do {
        numFilled = sscanf(line + offset, "%d%n", &(a[size]), &n);
        if (numFilled > 0) {
            size++;
            offset += n;
        }
    } while (numFilled > 0);

    return size;
}

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}
    
int partition(int *arr[], int l, int r){
    int x = arr[r];
    int i = l;
    for(int j=l;j<r;j++){
        if(arr[j]<=x){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[r]);
    return i;
}
int quickSelect(int *list[], int left, int right, int k){
    if (left == right){
        return list[right];
    }   
    int pivotIndex = partition(list, left, right);
    if (k == pivotIndex)
        return list[k];
    else if (k < pivotIndex)
        right = pivotIndex - 1;
    else
        left = pivotIndex + 1;
}

int main(int argc, const char * argv[]){
    int a[1000];
    int n=scanArray(a);
    int k;
    scanf("%d", k);
    int qs = quickSelect(a,0,n-1,k);
    printf("%d ", qs);
    return 0;
}
