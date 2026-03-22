#ifndef LL_H
#define LL_H
#include <stdbool.h>

struct Node {
  int payload;
  struct Node *next;
};

typedef struct Node Node;

Node *linked_list_init(int x);
void linked_list_add(Node *node, int x);
Node *linked_list_search(Node *node, int x);
void linked_list_print(Node *node);

#endif // !TEST_H
