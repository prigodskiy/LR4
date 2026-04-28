#include "tree.hpp"

TreeNode::TreeNode(char lbl) : label(lbl), left(nullptr), right(nullptr) {}

TreeNode::~TreeNode() {
    delete left;
    delete right;
}

Tree::Tree() : root(nullptr) {}

Tree::~Tree() {
    clear();
}

void Tree::setRoot(TreeNode* node) {
    root = node;
}

TreeNode* Tree::getRoot() const {
    return root;
}

void Tree::setLeftChild(TreeNode* parent, TreeNode* child) {
    if (parent) parent->left = child;
}

void Tree::setRightChild(TreeNode* parent, TreeNode* child) {
    if (parent) parent->right = child;
}

TreeNode* Tree::getLeftChild(TreeNode* parent) const {
    return parent ? parent->left : nullptr;
}

TreeNode* Tree::getRightChild(TreeNode* parent) const {
    return parent ? parent->right : nullptr;
}

void Tree::preorder(TreeNode* node, std::function<void(char)> visit) const {
    if (node) {
        visit(node->label);
        preorder(node->left, visit);
        preorder(node->right, visit);
    }
}

void Tree::preorder(std::function<void(char)> visit) const {
    preorder(root, visit);
}

void Tree::inorder(TreeNode* node, std::function<void(char)> visit) const {
    if (node) {
        inorder(node->left, visit);
        visit(node->label);
        inorder(node->right, visit);
    }
}

void Tree::inorder(std::function<void(char)> visit) const {
    inorder(root, visit);
}

void Tree::postorder(TreeNode* node, std::function<void(char)> visit) const {
    if (node) {
        postorder(node->left, visit);
        postorder(node->right, visit);
        visit(node->label);
    }
}

void Tree::postorder(std::function<void(char)> visit) const {
    postorder(root, visit);
}

void Tree::clear() {
    delete root; // TreeNode сам удалит поддерево в своём деструкторе
    root = nullptr;
}

bool Tree::isEmpty() const {
    return root == nullptr;
}