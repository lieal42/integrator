#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "time.h"

#define EXPECTED_ARGS 2
#define SAMPLES 1e7
#define SEED (argc == EXPECTED_ARGS) ? strtoull(argv[1], NULL, 10) : time(0)

int size = 40;
int cardNumber = 10;
int success = 0;


void createDeck(int*);
void swap(int*, int*);
void shuffle(int[]);
int game(int[]);

int main(int argc, char **argv) {

  unsigned long long int seed = SEED;

  fprintf(stderr, "Seed: %llu\n", seed);

  srand48(seed);

  int i;
  int * deck;
  deck = malloc(size*sizeof(int));
  if (deck == NULL) {
    fprintf(stderr, "error while allocating memory. Exiting...\n");
    return EXIT_FAILURE;
  }
  createDeck(deck);
  for (i = 0; i < SAMPLES; i++) {
    shuffle(deck);
    success += game(deck);
  }
  printf("Prob: %lf\n", (double)success / SAMPLES * 100);

  return EXIT_SUCCESS;
}

void createDeck(int *deck) {
  int i;
  for (i = 0; i < size; i++) {
    deck[i]  = (i % cardNumber) + 1;
  }
  shuffle(deck);
}

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void shuffle(int arr[]) {
  int i;
  for (i = size - 1; i > 0; i--) {
    int j = lrand48() % (i + 1);
    swap(&arr[ i ], &arr[ j ]);
  }
}

int game(int arr[]) {
  int i;
  for (i = 0;i < size;i++) {
    if (((i % 3) + 1) == arr[ i ]) {
      return (0);
    }
  }
  return (1);
}
