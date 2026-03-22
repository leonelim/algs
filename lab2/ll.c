#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "ll.h"

Node *init_linked_list() {
  Node *node = malloc(sizeof(Node));
  node->payload = 0;
  node->next = NULL;
  return node;
}

void append_linked_list(Node *node, int x) {
  Node *new_node = malloc(sizeof(Node));
  while (node->next != NULL) {
    node = node->next;
  }
  new_node->payload = x;
  new_node->next = NULL;
  node->next = new_node;
}

Node *search_linked_list(Node *node, int x) {
  while (node != NULL) {
    if (node->payload == x) {
      return node;
    }
    node = node->next;
  }
  return NULL;
}

void print_linked_list(Node *node) {
  while (node != NULL) {
    printf("%d ", node->payload);
    node = node->next;
  }
  putchar('\n');
}
