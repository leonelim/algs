#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

Node *linked_list_init(int x) {
  Node *node = malloc(sizeof(Node));
  node->payload = x;
  node->next = NULL;
  return node;
}

void linked_list_add(Node *node, int x) {
  Node *new_node = malloc(sizeof(Node));
  while (node->next != NULL) {
    node = node->next;
  }
  new_node->payload = x;
  new_node->next = NULL;
  node->next = new_node;
}

void linked_list_print(Node *node) {
  for (; node != NULL; node = node->next) {
    printf("%d ", node->payload);
  }
  putchar('\n');
}
