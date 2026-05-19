#ifndef TREE_H
#define TREE_H

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TreeNode {
    char label;
    struct TreeNode* left_child;
    struct TreeNode* right_child;
} TreeNode;

typedef struct {
    TreeNode* root_node;
} Tree;

TreeNode* tree_create_node(char label);
void tree_init(Tree* tree);
void tree_set_left(TreeNode* parent, TreeNode* child);
void tree_set_right(TreeNode* parent, TreeNode* child);
void tree_preorder(const TreeNode* node, void (*visit)(char));
void tree_inorder(const TreeNode* node, void (*visit)(char));
void tree_postorder(const TreeNode* node, void (*visit)(char));
void tree_free(Tree* tree);
bool tree_is_empty(const Tree* tree);

#ifdef __cplusplus
}
#endif

#endif
