#include <gtest/gtest.h>
#include "tree.h"

static char result[100];
static int idx;

static void visit(char c) {
    result[idx++] = c;
}

TEST(TreeTest, InitEmpty) {
    Tree t;
    TreeInit(&t);
    EXPECT_EQ(TreeRoot(&t), nullptr);
}

TEST(TreeTest, CreateTree) {
    Tree t;
    TreeInit(&t);
    
    TreeNode* root = TreeNodeCreate('A');
    TreeNode* b = TreeNodeCreate('B');
    TreeNode* c = TreeNodeCreate('C');
    
    TreeSetLeft(root, b);
    TreeSetRight(root, c);
    t.root = root;
    
    EXPECT_EQ(TreeRoot(&t), root);
    EXPECT_EQ(TreeLeftChild(root), b);
    EXPECT_EQ(TreeRightChild(root), c);
    
    TreeFree(&t);
}

TEST(TreeTest, Preorder) {
    Tree t;
    TreeInit(&t);
    
    TreeNode* root = TreeNodeCreate('A');
    TreeNode* b = TreeNodeCreate('B');
    TreeNode* c = TreeNodeCreate('C');
    TreeNode* d = TreeNodeCreate('D');
    
    TreeSetLeft(root, b);
    TreeSetRight(root, c);
    TreeSetRight(b, d);
    t.root = root;
    
    idx = 0;
    TreePreorder(root, visit);
    result[idx] = '\0';
    
    EXPECT_STREQ(result, "ABDC");
    
    TreeFree(&t);
}

TEST(TreeTest, Inorder) {
    Tree t;
    TreeInit(&t);
    
    TreeNode* root = TreeNodeCreate('A');
    TreeNode* b = TreeNodeCreate('B');
    TreeNode* c = TreeNodeCreate('C');
    
    TreeSetLeft(root, b);
    TreeSetRight(root, c);
    t.root = root;
    
    idx = 0;
    TreeInorder(root, visit);
    result[idx] = '\0';
    
    EXPECT_STREQ(result, "BAC");
    
    TreeFree(&t);
}

TEST(TreeTest, Postorder) {
    Tree t;
    TreeInit(&t);
    
    TreeNode* root = TreeNodeCreate('A');
    TreeNode* b = TreeNodeCreate('B');
    TreeNode* c = TreeNodeCreate('C');
    
    TreeSetLeft(root, b);
    TreeSetRight(root, c);
    t.root = root;
    
    idx = 0;
    TreePostorder(root, visit);
    result[idx] = '\0';
    
    EXPECT_STREQ(result, "BCA");
    
    TreeFree(&t);
}