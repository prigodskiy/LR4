#include <gtest/gtest.h>
#include "tree.hpp"
#include <string>

TEST(TreeCppTest, InitEmpty) {
    Tree t;
    EXPECT_TRUE(t.isEmpty());
    EXPECT_EQ(t.getRoot(), nullptr);
}

TEST(TreeCppTest, CreateTree) {
    Tree t;
    
    TreeNode* root = new TreeNode('A');
    TreeNode* b = new TreeNode('B');
    TreeNode* c = new TreeNode('C');
    
    t.setRoot(root);
    t.setLeftChild(root, b);
    t.setRightChild(root, c);
    
    EXPECT_EQ(t.getRoot(), root);
    EXPECT_EQ(t.getLeftChild(root), b);
    EXPECT_EQ(t.getRightChild(root), c);
}

TEST(TreeCppTest, Preorder) {
    Tree t;
    
    TreeNode* root = new TreeNode('A');
    TreeNode* b = new TreeNode('B');
    TreeNode* c = new TreeNode('C');
    TreeNode* d = new TreeNode('D');
    
    t.setRoot(root);
    t.setLeftChild(root, b);
    t.setRightChild(root, c);
    t.setRightChild(b, d);
    
    std::string result;
    t.preorder([&result](char c) {
        result += c;
    });
    
    EXPECT_EQ(result, "ABDC");
}

TEST(TreeCppTest, Inorder) {
    Tree t;
    
    TreeNode* root = new TreeNode('A');
    TreeNode* b = new TreeNode('B');
    TreeNode* c = new TreeNode('C');
    
    t.setRoot(root);
    t.setLeftChild(root, b);
    t.setRightChild(root, c);
    
    std::string result;
    t.inorder([&result](char c) {
        result += c;
    });
    
    EXPECT_EQ(result, "BAC");
}

TEST(TreeCppTest, Postorder) {
    Tree t;
    
    TreeNode* root = new TreeNode('A');
    TreeNode* b = new TreeNode('B');
    TreeNode* c = new TreeNode('C');
    
    t.setRoot(root);
    t.setLeftChild(root, b);
    t.setRightChild(root, c);
    
    std::string result;
    t.postorder([&result](char c) {
        result += c;
    });
    
    EXPECT_EQ(result, "BCA");
}

TEST(TreeCppTest, Clear) {
    Tree t;
    
    TreeNode* root = new TreeNode('A');
    TreeNode* b = new TreeNode('B');
    
    t.setRoot(root);
    t.setLeftChild(root, b);
    
    EXPECT_FALSE(t.isEmpty());
    t.clear();
    EXPECT_TRUE(t.isEmpty());
    EXPECT_EQ(t.getRoot(), nullptr);
}

TEST(TreeCppTest, Destructor) {
    {
        Tree t;
        TreeNode* root = new TreeNode('A');
        TreeNode* b = new TreeNode('B');
        t.setRoot(root);
        t.setLeftChild(root, b);
    }
    SUCCEED();
}