#include <stdio.h>

#include "ll.h"
#include "sort.h"

#define LEN 5

int linear_search(int arr[], int size, int x);
int binary_search(int arr[], int size, int x);
void print_arr(int arr[], int size);

int main() {
  int arr2[LEN] = {22, 34, 65, 88, 100};
  printf("array:");
  print_arr(arr2, LEN);

  int idx = linear_search(arr2, LEN, 34);
  printf("element %d index linear search: %d\n", 34, idx);

  shell_sort(arr2, LEN);
  idx = binary_search(arr2, LEN, 65);
  printf("element %d index using binary search: %d\n", 65, idx);

  Node *head = init_linked_list();
  head->payload = 3;
  append_linked_list(head, 5);
  append_linked_list(head, 4);
  append_linked_list(head, 5);
  printf("linked list:");
  print_linked_list(head);

  Node *node = search_linked_list(head, 4);
  if (node == NULL) {
    puts("not found");
  } else {
    printf("element: %d\n", node->payload);
  }
  return 0;
}

int linear_search(int arr[], int size, int x) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1;
}

int binary_search(int arr[], int size, int x) {
  int low = 0;
  int high = size - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == x) {
      return mid;
    }
    if (arr[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

void print_arr(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  putchar('\n');
}
