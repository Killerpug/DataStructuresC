# CDS5BinarySearchTree
Fifth Data Structure on C, a Dynamic key-system implementation of Binary Search Tree whose basic operations run at O(lg n).
A Binary Tree is a node type structure, where each node can have two children nodes linked and so on. The height of the tree is 
the nesting level of childrens that the root/start node has. 
Each node has :
*Key  *LeftChild  *RightChild   *Parent   *Data

The key system, store nodes by key value: 
-each left child(subtree node) key must be less than parent key 
-each right child(subtree node) key must be bigger than parent key.

Basic operations:
Search, Minimum, Maximum, Predecessor, Succesor, insert and delete.

Methods:
BTree* create_tree();                                                 //create the BTree that stores nodes
void clear_tree(BTree* b_tree);
void print_tree(BTree* b_tree);
uint insert_mtnode(T item, uint key, BTree* b_tree);                 //add node to Binary Tree with a manual-typed key
uint insert_atnode(T item, BTree* b_tree);                           //add node to Binary Tree with auto-generated key, returns key
T get_tnode_data(uint key, BTree* b_tree);                            //retrieves matches of key
void remove_tnode(uint key, BTree* b_tree);                          //removes first key-match
TreeNode* tree_minimum(TreeNode* node);                            //returns minimum node in a tree starting from input node
TreeNode* tree_maximum(TreeNode* node);
T tnode_predecessor(uint key, BTree* b_tree);                       //returns predecessor in a tree starting from key-match node
T tnode_successor(uint key, BTree* b_tree);
