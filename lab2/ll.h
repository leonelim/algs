#ifndef LL_H
#define LL_H
#include <stdbool.h>

struct Node {
  int payload;
  struct Node *next;
};

typedef struct Node Node;

Node *init_linked_list();
void append_linked_list(Node *node, int x);
Node *search_linked_list(Node *node, int x);
void print_linked_list(Node *node);

#endif // !TEST_H
