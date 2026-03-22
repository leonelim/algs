typedef struct Node {
  int payload;
  struct Node *left, *right;
} Node;

Node *create_node(int x);
Node *delete_node(Node *node);
Node *search_node(Node *tree, int x);
Node *bst_insert(Node *root, int key);
Node *find_min(Node *root);
Node *bst_delete(Node *root, int key);
void inorder(Node *root, void (*visit)(int));
void preorder(Node *root, void (*visit)(int));
void postorder(Node *root, void (*visit)(int));
void free_tree(Node *root);
Node *build_balanced_from_sorted_range(int start, int n);
Node *build_perfectly_balanced_tree(int n);
void print_key(int key);
