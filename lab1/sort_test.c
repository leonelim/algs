#include "sort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 5

void sort_test(void sort_func(int[], int));
void print_arr(int arr[], int size);
void print_sort_print(void sort(int[], int), int arr[], int size);

int main() {
  srand(time(NULL));

  puts("Selection sort test:");
  sort_test(selection_sort);

  putchar('\n');

  puts("Shell sort test:");
  sort_test(shell_sort);

  return 0;
}

void print_arr(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  putchar('\n');
}

void sort_test(void sort(int[], int)) {
  int arr_rand[LEN];
  int arr1[LEN] = {5, 4, 3, 2, 1};
  int arr2[LEN] = {22, 34, 65, 88, 100};
  int i;
  for (i = 0; i < LEN; ++i) {
    arr_rand[i] = rand() % 100;
  }
  print_sort_print(sort, arr_rand, LEN);
  print_sort_print(sort, arr1, LEN);
  print_sort_print(sort, arr2, LEN);
}

void print_sort_print(void sort(int[], int), int arr[], int size) {
  puts("Initial array:");
  print_arr(arr, size);

  sort(arr, size);

  puts("Sorted array:");
  print_arr(arr, size);
}
