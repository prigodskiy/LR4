#ifndef TREE_HPP
#define TREE_HPP

#include <functional>

class TreeNode {
public:
    char label;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(char lbl);
    ~TreeNode();
};

class Tree {
private:
    TreeNode* root;
    
    void preorder(TreeNode* node, std::function<void(char)> visit) const;
    void inorder(TreeNode* node, std::function<void(char)> visit) const;
    void postorder(TreeNode* node, std::function<void(char)> visit) const;
    
public:
    Tree();
    ~Tree();
    
    void setRoot(TreeNode* node);
    TreeNode* getRoot() const;
    
    void setLeftChild(TreeNode* parent, TreeNode* child);
    void setRightChild(TreeNode* parent, TreeNode* child);
    TreeNode* getLeftChild(TreeNode* parent) const;
    TreeNode* getRightChild(TreeNode* parent) const;
    
    void preorder(std::function<void(char)> visit) const;
    void inorder(std::function<void(char)> visit) const;
    void postorder(std::function<void(char)> visit) const;
    
    void clear();
    bool isEmpty() const;
};

#endif