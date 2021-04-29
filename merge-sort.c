#include "stdio.h"
#include "stdlib.h"
#include "time.h"

/*
 * Fill list with N random doubles.
 * It doesn't do anything with memory allocation.
 */
void fill_list(const unsigned N, double *list) {
  // initialise random number generator
  srand(time(NULL));

  // fill array
  for (int i = 0; i < N; ++i) {
    const double r = (double)rand() / RAND_MAX;
    list[i] = r;
  }
}

// function to swap elements
void swap(double *a, double *b) {
  double t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
unsigned partition(double array[], unsigned low, unsigned high) {

  // select the rightmost element as pivot
  double pivot = array[high];

  // pointer for greater element
  int i = low-1;

  // traverse each element of the array
  // compare them with the pivot
  for (unsigned j = low; j < high; j++) {
    if (array[j] <= pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);

  // return the partition point
  return (i + 1);
}

/*
 * Recursive implementation of sort using quick sort.
 */
void quick_sort(double array[], unsigned low, unsigned high) {
  if (low < high) {

    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    unsigned pi = partition(array, low, high);

    if(pi > 0) {
      // recursive call on the left of pivot
      quick_sort(array, low, pi - 1);
    }

    // recursive call on the right of pivot
    quick_sort(array, pi + 1, high);
  }
}

/*
 * Sort elements of list into increasing order.
 */
void sort(unsigned N, double* list) {
  quick_sort(list, 0, N-1);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "please call: %s {N}\n", argv[0]);
    return 1;
  }

  // extract command line argument
  const unsigned N = atoi(argv[1]);

  // create and allocate list
  double *list;
  list = malloc(N * sizeof(double));

  // fill with random values
  fill_list(N, list);

  // sort
  sort(N, list);

  // print if small enough
  if (N < 10) {
    for (int i = 0; i < N; ++i) {
      printf(" %f", list[i]);
    }
    printf("\n");
  }

  // clean up memory
  /* free(list); */
  return 0;
}
