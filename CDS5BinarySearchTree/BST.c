//
// Created by A01229895 on 09/06/2019.
//
#include <malloc.h>
#include <stdlib.h>
#include "BST.h"
#include <limits.h>
#include <stdio.h>

BTree* create_tree() {
    BTree* new_tree = (BTree*) malloc(sizeof(BTree));
    new_tree->size = 0;
    new_tree->root = NULL;
    return new_tree;
}

void clear_tree(BTree* b_tree) {
    clear_subtrees(b_tree->root);
    free(b_tree);
}
static void clear_subtrees(TreeNode* root) {
    if(root != NULL)
    {
        clear_subtrees(root->left);
        clear_subtrees(root->right);
        free(root);
    }
}

void print_tree(BTree* b_tree) { private_print_tree(b_tree->root, 0); }

void padding(char ch, int n) { for (int i = 0; i < n; i++) putchar(ch); }

static void private_print_tree(TreeNode* root, int space) {
    if (root == NULL) {
        padding('\t', space);
        puts( "~" );
    } else {
        private_print_tree(root->right, space + 1);
        padding('\t', space );
        printf("%i:%i\n", root->data, root->key);
        private_print_tree(root->left, space + 1);
    }
}

bool is_empty_tree(BTree* b_tree) { return b_tree->size == 0; }

bool contains_key(uint key, BTree* b_tree) { return search_tnode(key, b_tree->root) != NULL; }

static TreeNode* create_tnode(T item, uint key) {
    TreeNode* new_node = (TreeNode*) malloc(sizeof(TreeNode));
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->key = key;
    new_node->data = item;
    return new_node;
}

uint insert_mtnode(T item, uint key, BTree* b_tree) {
    TreeNode* tnode = create_tnode(item, key);
    b_tree->size++;
    if (b_tree->root == NULL) {                             //insert node as root
        b_tree->root = tnode;
        return tnode->key;
    }
    TreeNode* search_gap = b_tree->root;
    TreeNode* parent = NULL;
    while (search_gap != NULL) {                             //find a leaf to insert tnode: low keys->left, high keys-> right
        parent = search_gap;                                 //reference parent nodes of iteration node
        if (tnode->key < search_gap->key) search_gap = search_gap->left;
        else search_gap = search_gap->right;
    }
    tnode->parent = parent;
    if (tnode->key < parent->key)  parent->left = tnode;
    else parent->right = tnode;
    return tnode->key;
}

uint insert_atnode(T item, BTree* b_tree) { return insert_mtnode(item, generate_key(), b_tree); }

static unsigned int generate_key() {
    uint key = (uint) rand() % UINT_MAX;
    return key;
}

static TreeNode* search_tnode(uint with_key, TreeNode* starting_tnode) {
    if (starting_tnode == NULL) {
        printf("The branch is empty");
        return NULL;
    }
    while (starting_tnode != NULL && with_key != starting_tnode->key) {
        if (with_key < starting_tnode->key && starting_tnode->left != NULL) starting_tnode = starting_tnode->left;
        else if(starting_tnode->right != NULL) starting_tnode = starting_tnode->right;
        else {
            starting_tnode = NULL;
        }
    }
    return starting_tnode;
}

T get_tnode_data(uint key, BTree* b_tree) {
    if (b_tree->size == 0) {
        printf("The tree is empty");
        return -1;
    }
    TreeNode* match = search_tnode(key, b_tree->root);
    if (match == NULL) return -1;
    return match->data;
}

void remove_tnode(uint key, BTree* b_tree) {
    TreeNode* remove = search_tnode(key, b_tree->root);                                 //search node to remove
    if (remove == NULL) return;
    if (remove->left == NULL) private_remove(remove, remove->right, b_tree);            //left child is empty, rise up right branch
    else if (remove->right == NULL) private_remove(remove, remove->left, b_tree);       //right child is empty, rise up left branch
    else {
        TreeNode* replace = tree_minimum(remove->right);
        if (replace->parent != remove) {                                        //replace is not the direct right child of remove
            private_remove(remove, replace->right, b_tree);
            replace->right = remove->right;
            replace->right->parent = replace;
        }
        private_remove(remove, replace, b_tree);                                //replace is direct right child of remove
        replace->left = remove->left;
        replace->left->parent = remove;
    }
    printf("node %i with key %i, has been eliminated.\n", remove->data, remove->key);
    free(remove);
}

static void private_remove(TreeNode* remove, TreeNode* replace, BTree* b_tree) {
    if(remove->parent == NULL) b_tree->root = replace;                          //remove is root
    else if (remove == remove->parent->left) remove->parent->left = replace;    //remove is left child
    else remove->parent->right = replace;                                       //remove is right child
    if (replace != NULL) replace->parent = remove->parent;
}

TreeNode* tree_minimum(TreeNode* node) {
    while (node->left != NULL) node = node->left;
    return node;
}

TreeNode* tree_maximum(TreeNode* node) {
    while (node->right != NULL) node = node->right;
    return node;
}

T tnode_predecessor(uint key, BTree* b_tree) {
    TreeNode* iter_tnode = search_tnode(key, b_tree->root);                               //find starting node
    if (iter_tnode == NULL) return -1;
    if(iter_tnode->left != NULL)
        return tree_maximum(iter_tnode->left)->data;                     //predecessor is largest child of left subtree
    TreeNode* iter_parent = iter_tnode->parent;
    while (iter_parent != NULL && iter_tnode == iter_parent->left) {        //predecessor is first parent who is also left child
        iter_tnode = iter_parent;
        iter_parent = iter_parent->parent;
    }
    if (iter_parent == NULL) return -1;                                     //does not have predecessor
    return iter_parent->data;
}

T tnode_successor(uint key, BTree* b_tree) {
    TreeNode* iter_tnode = search_tnode(key, b_tree->root);                               //find starting node
    if (iter_tnode == NULL) return -1;
    if(iter_tnode->right != NULL)                                                 //successor is smallest child of right subtree
        return tree_minimum(iter_tnode->right)->data;
    TreeNode* iter_parent = iter_tnode->parent;
    while (iter_tnode->parent != NULL && iter_tnode == iter_parent->right) {        //successor is first parent who is also left child
        iter_tnode = iter_parent;
        iter_parent = iter_parent->parent;
    }
    if (iter_parent == NULL) return -1;                                             //does not have successor
    return iter_parent->data;
}