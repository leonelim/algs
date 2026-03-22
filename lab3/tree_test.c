#include "tree.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  Node *tree = bst_insert(NULL, 2);
  bst_insert(tree, 1);
  bst_insert(tree, 3);
  bst_insert(tree, 4);
  inorder(tree, &print_key);
  puts("");
  preorder(tree, &print_key);
  puts("");
  postorder(tree, &print_key);
  puts("");
  bst_delete(tree, 4);
  preorder(tree, &print_key);
  puts("");
  bst_delete(tree, 3);
  preorder(tree, &print_key);
  puts("");
  bst_delete(tree, 1);
  preorder(tree, &print_key);
  puts("");
  free_tree(tree);
  tree = bst_insert(NULL, 0);
  for (int i = 1; i < 5; ++i) {
    bst_insert(tree, i);
  }
  puts("ijdwaiad");
  inorder(tree, &print_key);
  puts("");
  preorder(tree, &print_key);
  puts("");
  postorder(tree, &print_key);
  puts("");

  free_tree(tree);
  tree = build_perfectly_balanced_tree(6);
  preorder(tree, &print_key);
  puts("");
  inorder(tree, &print_key);
  puts("");
  bst_insert(tree, 7);
  bst_insert(tree, 8);
  preorder(tree, &print_key);
  puts("");

  Node *node = search_node(tree, 7);
  if (node != NULL) {
    print_key(node->payload);
  } else {
    puts("NULL");
  }

  node = search_node(tree, 9);
  if (node != NULL) {
    print_key(node->payload);
  } else {
    puts("NULL");
  }

  return 0;
}
