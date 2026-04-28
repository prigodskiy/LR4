#include "tree.h"
#include <stdlib.h>

TreeNode* TreeNodeCreate(char label) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->label = label;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void TreeInit(Tree* t) {
    t->root = NULL;
}

TreeNode* TreeRoot(Tree* t) {
    return t->root;
}

void TreeSetLeft(TreeNode* node, TreeNode* child) {
    if (node) {
        node->left = child;
    }
}

void TreeSetRight(TreeNode* node, TreeNode* child) {
    if (node) {
        node->right = child;
    }
}

TreeNode* TreeLeftChild(TreeNode* node) {
    return node ? node->left : NULL;
}

TreeNode* TreeRightChild(TreeNode* node) {
    return node ? node->right : NULL;
}

void TreePreorder(TreeNode* node, void (*visit)(char)) {
    if (node) {
        visit(node->label);
        TreePreorder(node->left, visit);
        TreePreorder(node->right, visit);
    }
}

void TreeInorder(TreeNode* node, void (*visit)(char)) {
    if (node) {
        TreeInorder(node->left, visit);
        visit(node->label);
        TreeInorder(node->right, visit);
    }
}

void TreePostorder(TreeNode* node, void (*visit)(char)) {
    if (node) {
        TreePostorder(node->left, visit);
        TreePostorder(node->right, visit);
        visit(node->label);
    }
}

static void FreeNode(TreeNode* node) {
    if (node) {
        FreeNode(node->left);
        FreeNode(node->right);
        free(node);
    }
}

void TreeFree(Tree* t) {
    FreeNode(t->root);
    t->root = NULL;
}