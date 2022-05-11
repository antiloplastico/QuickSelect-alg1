#include <stdio.h>
#include <time.h>


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

int quickSelect(list, left, right, k){
    if (left == right)   return list[right]
    int pivotIndex = partition(list, left, right,pivotIndex);
    if (k == pivotIndex)
        return list[k];
    else if (k < pivotIndex)
        right = pivotIndex - 1;
    else
        left = pivotIndex + 1;
}

int main()
{
    printf("Hello World");

    return 0;
}
