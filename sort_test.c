#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

void sort_test(void sort_func(int[], int));

int main() {
  puts("Selection sort test:");
  sort_test(selection_sort);
  putchar('\n');
  puts("Shell sort test:");
  sort_test(shell_sort);
  return 0;
}

void sort_test(void sort(int[], int)) {
  srand(time(NULL));
  int arr_rand[5];
  for (int i = 0; i < 5; i++) {
    arr_rand[i] = rand() % 100;
  }
  int r = 2;
  int t = 3;

  puts("Initial array:");
  print_arr(arr_rand, 5);

  sort(arr_rand, 5);

  puts("Sorted array:");
  print_arr(arr_rand, 5);

  const int n1 = 5;
  int arr1[] = {5, 4, 3, 2, 1};
  puts("Initial array:");
  print_arr(arr1, n1);

  sort(arr1, n1);

  puts("Sorted array:");
  print_arr(arr1, n1);

  const int n2 = 5;
  int arr2[] = {22, 34, 65, 88};
  puts("Initial array:");
  print_arr(arr2, n2);

  sort(arr2, n2);

  puts("Sorted array:");
  print_arr(arr2, n2);
}
