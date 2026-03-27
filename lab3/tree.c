#include "tree.h"

#include <stdio.h>
#include <stdlib.h>

Node *create_node(int x) {
  Node *node = malloc(sizeof(Node));
  node->payload = x;
  node->right = node->left = NULL;
  return node;
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

Node *insert_node(Node *root, int key) {
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

Node *delete_node(Node *root, int key) {
  if (!root)
    return NULL;

  if (key < root->payload) {
    root->left = delete_node(root->left, key);
  } else if (key > root->payload) {
    root->right = delete_node(root->right, key);
  } else {
    if (!root->left) {
      Node *r = root->right;
      free(root);
      return r;
    } else if (!root->right) {
      Node *l = root->left;
      free(root);
      return l;
    } else {
      Node *succ = find_min(root->right);
      root->payload = succ->payload;
      root->right = delete_node(root->right, succ->payload);
    }
  }
  return root;
}

void inorder(Node *root) {
  if (!root)
    return;
  inorder(root->left);
  printf("%d ", root->payload);
  inorder(root->right);
}

void preorder(Node *root) {
  if (!root)
    return;
  printf("%d ", root->payload);
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node *root) {
  if (!root)
    return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->payload);
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
