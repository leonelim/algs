#include "linked_list.h"

#include <stdlib.h>

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

Node *linked_list_search(Node *node, int x) {
  for (; node != NULL; node = node->next) {
    if (node->payload == x) {
      return node;
    }
  }
  return NULL;
}
