#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BST.h"


int main() {
    srand(time(NULL));
    BTree* tree1 = create_tree();
    //for (int i = 0; i < 50; i++) insert_atnode(i, tree1);
    insert_mtnode(1, 10, tree1);
    insert_mtnode(2, 5, tree1);
    insert_mtnode(3, 20, tree1);
    insert_mtnode(4, 3, tree1);
    insert_mtnode(5, 7, tree1);
    insert_mtnode(6, 15, tree1);
    insert_mtnode(7, 25, tree1);
    insert_mtnode(15, 4545, tree1);
    tnode_successor(15, tree1);
    tnode_predecessor(15, tree1);
    print_tree(tree1);
    get_tnode_data(4545, tree1);
    printf("tree is empty?: %d\n", is_empty_tree(tree1));
    remove_tnode(4545, tree1);
    printf("tree has element with key 4545?: %d\n", contains_key(4545, tree1));

    clear_tree(tree1);


    return 0;
}