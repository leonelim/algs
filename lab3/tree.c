#include "tree.h"

#include <stdio.h>
#include <stdlib.h>

Node *create_node(int x) {
  Node *node = malloc(sizeof(Node));
  node->payload = x;
  node->right = node->left = NULL;
  return node;
}

Node *delete_node(Node *node) {
  if (node != NULL) {
    free(node);
    delete_node(node->left);
    delete_node(node->right);
  }
  return NULL;
}

Node *search_node(Node *tree, int x) {
  while (tree != NULL) {
    if (tree->payload == x) {
      return tree;
    }
    if (x < tree->payload) {
      tree = tree->left;
    } else {
      tree = tree->right;
    }
  }
  return NULL;
}

Node *bst_insert(Node *root, int key) {
  if (!root)
    return create_node(key);

  Node *parent = NULL;
  Node *cur = root;
  while (cur) {
    parent = cur;
    if (key == cur->payload) {
      return root;
    }
    cur = (key < cur->payload) ? cur->left : cur->right;
  }

  if (key < parent->payload)
    parent->left = create_node(key);
  else
    parent->right = create_node(key);

  return root;
}

Node *find_min(Node *root) {
  if (!root)
    return NULL;
  while (root->left)
    root = root->left;
  return root;
}

/* Удаление узла. Возвращает новый корень поддерева. */
Node *bst_delete(Node *root, int key) {
  if (!root)
    return NULL;

  if (key < root->payload) {
    root->left = bst_delete(root->left, key);
  } else if (key > root->payload) {
    root->right = bst_delete(root->right, key);
  } else {
    /* найден узел для удаления */
    if (!root->left) {
      Node *r = root->right;
      free(root);
      return r;
    } else if (!root->right) {
      Node *l = root->left;
      free(root);
      return l;
    } else {
      /* два потомка: заменить ключ на минимальный в правом поддереве */
      Node *succ = find_min(root->right);
      root->payload = succ->payload;
      root->right = bst_delete(root->right, succ->payload);
    }
  }
  return root;
}

void inorder(Node *root, void (*visit)(int)) {
  if (!root)
    return;
  inorder(root->left, visit);
  visit(root->payload);
  inorder(root->right, visit);
}

void preorder(Node *root, void (*visit)(int)) {
  if (!root)
    return;
  visit(root->payload);
  preorder(root->left, visit);
  preorder(root->right, visit);
}

void postorder(Node *root, void (*visit)(int)) {
  if (!root)
    return;
  postorder(root->left, visit);
  postorder(root->right, visit);
  visit(root->payload);
}

void free_tree(Node *root) {
  if (!root)
    return;
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}

Node *build_balanced_from_sorted_range(int start, int n) {
  if (n <= 0)
    return NULL;
  int mid = n / 2;
  Node *root = create_node(start + mid);
  root->left = build_balanced_from_sorted_range(start, mid);
  root->right = build_balanced_from_sorted_range(start + mid + 1, n - mid - 1);
  return root;
}

Node *build_perfectly_balanced_tree(int n) {
  return build_balanced_from_sorted_range(1, n);
}

void print_key(int key) { printf("%d ", key); }
