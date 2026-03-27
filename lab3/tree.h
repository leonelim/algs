typedef struct Node {
  int payload;
  struct Node *left, *right;
} Node;

Node *create_node(int x);
Node *search_node(Node *tree, int x);
Node *insert_node(Node *root, int key);
Node *find_min(Node *root);
Node *delete_node(Node *root, int key);
void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);
void free_tree(Node *root);
Node *build_balanced_from_sorted_range(int start, int n);
Node *build_perfectly_balanced_tree(int n);
void print_key(int key);
