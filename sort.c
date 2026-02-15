#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selection_sort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int min_ind = i;

    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[min_ind]) {
        min_ind = j;
      }
    }

    swap(&arr[i], &arr[min_ind]);
  }
}

void shell_sort(int arr[], int size) {
  for (int gap = size / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < size; ++i) {
      for (int j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap) {
        swap(&arr[j], &arr[j + gap]);
      }
    }
  }
}

void print_arr(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  putchar('\n');
}
