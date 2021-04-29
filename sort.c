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

/*
 * Sort elements of list into increasing order.
 */
void sort(const unsigned N, double *list) {
  // loop to access each array element
  for (int step = 0; step < N - 1; ++step) {
    // loop to compare array elements
    for (int i = 0; i < N - step - 1; ++i) {

      // compare two adjacent elements
      // change > to < to sort in descending order
      if (list[i] > list[i + 1]) {

        // swapping occurs if elements
        // are not in the intended order
        double temp = list[i];
        list[i] = list[i + 1];
        list[i + 1] = temp;
      }
    }
  }
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
  free(list);
  return 0;
}
