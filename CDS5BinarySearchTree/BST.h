//
// Created by A01229895 on 09/06/2019.
//

#ifndef CDS5BINARYSEARCHTREE_BST_H
#define CDS5BINARYSEARCHTREE_BST_H

#include <stdbool.h>


typedef int T;
typedef unsigned int uint;
typedef struct TreeNode {
    T data;
    uint key;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;
} TreeNode;

typedef struct BTree {
    struct TreeNode* root;
    int size;
} BTree;

BTree* create_tree();                                                 //create the BTree that stores nodes
void clear_tree(BTree* b_tree);
static void clear_subtrees(TreeNode* root);
static void private_print_tree(TreeNode* root, int space);
void print_tree(BTree* b_tree);
bool is_empty_tree(BTree* b_tree);
bool contains_key(uint key, BTree* b_tree);
static TreeNode* create_tnode(T item, uint key);                        //initializes Tree node
uint insert_mtnode(T item, uint key, BTree* b_tree);                 //add node to Binary Tree with a manual-typed key
uint insert_atnode(T item, BTree* b_tree);                            //add node to Binary Tree with auto-generated key, returns key
static uint generate_key();
static TreeNode* search_tnode(uint with_key, TreeNode* starting_tnode);
T get_tnode_data(uint key, BTree* b_tree);                            //retrieves matches of key
void remove_tnode(uint key, BTree* b_tree);                          //removes first key-match
static void private_remove(TreeNode* remove, TreeNode* replace, BTree* b_tree);
TreeNode* tree_minimum(TreeNode* node);                            //returns minimum node in a tree starting from key-match; if key is 0 start from root
TreeNode* tree_maximum(TreeNode* node);
T tnode_predecessor(uint key, BTree* b_tree);                       //returns predecessor in a tree starting from key-match node; if key is 0 start from root
T tnode_successor(uint key, BTree* b_tree);


#endif //CDS5BINARYSEARCHTREE_BST_H+96
