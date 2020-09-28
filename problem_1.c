// Ordered Binary Tree

// A binary tree is a data structure in which each node has at most two children,
// which are referred to as the left child and the right child. Often, binary tree
// implementations have the invariant that its elements appear in order. Your task
// is to implmenet an ordered binary tree in C whose values are integers. Include
// a function with the following prototype:
// void insert(tree_t* tree, int value)

// The insert function should take a pointer to a tree and an integer value, in-
// serting the integer as a leaf node such that the tree’s ordering invariant is main-
// tained. The tree does not need to maintain any other invariants, such as balance.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct tree {
    struct tree * left;
    struct tree * right;
    int value;
} tree_t;

tree_t * new_node(int value) {
    tree_t * tree_node = malloc(sizeof(tree_t));
    tree_node->value = value;
    tree_node->left = NULL;
    tree_node->right = NULL;

    return tree_node;
}

void insert (tree_t * tree, int value) {
    tree_t * node = new_node(value);
     if (tree->value >= value) {
        if (tree->left == NULL) {
            tree->left = node;
        } else {
            insert(tree->left, value);
        }
    } else if (tree->value < value) {
        if (tree->right == NULL) {
            tree->right = node;
        } else {
            insert(tree->right, value);        
        }
    }
}

int main() {
    tree_t * tree = new_node(5);
    assert(tree->value == 5);

    insert(tree, 3);
    assert(tree->left->value == 3);

    insert(tree, 7);
    assert(tree->right->value == 7);

    insert(tree, 4);
    assert(tree->left->right->value == 4);

    insert(tree, 6);
    assert(tree->right->left->value == 6);

    return 0;
}
