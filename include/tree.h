#ifndef TREE_H
#define TREE_H

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TreeNode {
    char label;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    TreeNode* root;
} Tree;

TreeNode* TreeNodeCreate(char label);
void TreeInit(Tree* t);
TreeNode* TreeRoot(Tree* t);
void TreeSetLeft(TreeNode* node, TreeNode* child);
void TreeSetRight(TreeNode* node, TreeNode* child);
TreeNode* TreeLeftChild(TreeNode* node);
TreeNode* TreeRightChild(TreeNode* node);
void TreePreorder(TreeNode* node, void (*visit)(char));
void TreeInorder(TreeNode* node, void (*visit)(char));
void TreePostorder(TreeNode* node, void (*visit)(char));
void TreeFree(Tree* t);

#ifdef __cplusplus
}
#endif

#endif