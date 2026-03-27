#include "tree.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  Node *tree = insert_node(NULL, 2);
  insert_node(tree, 1);
  insert_node(tree, 3);
  insert_node(tree, 4);
  puts("postorder:");
  postorder(tree);
  puts("");
  puts("preorder:");
  preorder(tree);
  puts("");
  puts("inorder:");
  inorder(tree);
  puts("");

  delete_node(tree, 4);
  puts("preorder after delete:");
  preorder(tree);
  puts("");
  delete_node(tree, 3);
  puts("preorder after delete:");
  preorder(tree);
  puts("");
  delete_node(tree, 1);
  puts("preorder after delete:");
  preorder(tree);
  puts("");
  free_tree(tree);
  tree = insert_node(NULL, 0);
  for (int i = 1; i < 5; ++i) {
    insert_node(tree, i);
  }
  puts("degenerate tree:");
  puts("postorder:");
  postorder(tree);
  puts("");
  puts("preorder:");
  preorder(tree);
  puts("");
  puts("inorder:");
  inorder(tree);
  puts("");
  free_tree(tree);

  tree = build_perfectly_balanced_tree(6);
  puts("preorder:");
  preorder(tree);
  puts("");
  puts("inorder:");
  inorder(tree);
  puts("");
  insert_node(tree, 7);
  insert_node(tree, 8);
  puts("preorder:");
  preorder(tree);
  puts("");

  Node *node = search_node(tree, 7);
  if (node != NULL) {
    printf("%d found in the tree\n", node->payload);
  } else {
    printf("%d not found in the tree\n", 7);
  }

  node = search_node(tree, 9);
  if (node != NULL) {
    printf("%d found in the tree\n", node->payload);
  } else {
    printf("%d not found in the tree\n", 9);
  }

  return 0;
}
