void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selection_sort(int arr[], int size) {
  int i, j;
  int min_ind;
  for (i = 0; i < size - 1; i++) {
    min_ind = i;

    for (j = i + 1; j < size; j++) {
      if (arr[j] < arr[min_ind]) {
        min_ind = j;
      }
    }

    swap(&arr[i], &arr[min_ind]);
  }
}

void shell_sort(int arr[], int size) {
  int gap, i, j;
  for (gap = size / 2; gap > 0; gap /= 2) {
    for (i = gap; i < size; ++i) {
      for (j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap) {
        swap(&arr[j], &arr[j + gap]);
      }
    }
  }
}
