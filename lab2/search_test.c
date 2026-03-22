#include <stdio.h>

#include "linked_list.h"
#include "search.h"
#include "sort.h"

#define LEN 5

void print_arr(int arr[], int size);

int main() {
  int arr2[LEN] = {5, 4, 3, 2, 1};
  printf("Initial array: ");
  print_arr(arr2, LEN);

  int idx = linear_search(arr2, LEN, 4);
  printf("Element %d index using linear search: %d\n", 4, idx);

  shell_sort(arr2, LEN);
  printf("Sorted array: ");
  print_arr(arr2, LEN);

  idx = binary_search(arr2, LEN, 3);
  printf("Element %d index using binary search: %d\n", 3, idx);

  Node *linked_list = linked_list_init(3);
  linked_list_add(linked_list, 5);
  linked_list_add(linked_list, 4);
  linked_list_add(linked_list, 5);
  printf("Initial linked list:");
  linked_list_print(linked_list);

  Node *node = linked_list_search(linked_list, 4);
  if (node == NULL) {
    puts("Element not found");
  } else {
    printf("Element using linear search in linked list: %d\n", node->payload);
  }
  return 0;
}

void print_arr(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  putchar('\n');
}
