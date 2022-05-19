#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

#define MAX_LINE_SIZE 10000   // maximum size of a line of input


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

void swapp (int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition3(int *a, int i, int j){
	int pivot=a[i];
	int k = i;
	for (int l=i+1; l<=j; l++){
		if (a[l] < pivot) {
			swapp (&(a[k]), &(a[l]));
			swapp (&(a[k+1]), &(a[l]));
			k++;
		} else {//l > pivot
			//non faccio niente
		}
	}
	return k;
}

void quick3(int *a, int i, int j){ //vettore in 3 parti: a e' il vettore stesso, j fine scansione, i inizio scansione
	if (i < j){
		int c = partition3(a, i, j);
		quick3(a, i, c);
		quick3(a, c+1, j);
	}
}

int main() {
	int a[1010];
	int len = scanArray(a);
	int nth;
	scanf ("%d", &nth);
	
	quick3(a, 0, len-1);
	printf ("%d", a[nth-1]);

}
