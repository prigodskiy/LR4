import unittest
import sys
import os

sys.path.insert(0, os.path.dirname(__file__))
from tree import Tree, TreeNode

class TestTree(unittest.TestCase):
    def test_init_empty(self):
        t = Tree()
        self.assertTrue(t.is_empty())
        self.assertIsNone(t.get_root())

    def test_create_tree(self):
        t = Tree()
        root = TreeNode('A')
        b = TreeNode('B')
        c = TreeNode('C')
        t.set_root(root)
        t.set_left(root, b)
        t.set_right(root, c)
        self.assertEqual(t.get_root(), root)
        self.assertEqual(root.left, b)
        self.assertEqual(root.right, c)

    def test_preorder(self):
        t = Tree()
        root = TreeNode('A')
        b = TreeNode('B')
        c = TreeNode('C')
        d = TreeNode('D')
        t.set_root(root)
        t.set_left(root, b)
        t.set_right(root, c)
        t.set_right(b, d)
        res = []
        t.preorder(root, res.append)
        self.assertEqual(res, ['A', 'B', 'D', 'C'])

    def test_inorder(self):
        t = Tree()
        root = TreeNode('A')
        b = TreeNode('B')
        c = TreeNode('C')
        t.set_root(root)
        t.set_left(root, b)
        t.set_right(root, c)
        res = []
        t.inorder(root, res.append)
        self.assertEqual(res, ['B', 'A', 'C'])

    def test_postorder(self):
        t = Tree()
        root = TreeNode('A')
        b = TreeNode('B')
        c = TreeNode('C')
        t.set_root(root)
        t.set_left(root, b)
        t.set_right(root, c)
        res = []
        t.postorder(root, res.append)
        self.assertEqual(res, ['B', 'C', 'A'])

    def test_clear(self):
        t = Tree()
        t.set_root(TreeNode('A'))
        self.assertFalse(t.is_empty())
        t.clear()
        self.assertTrue(t.is_empty())

if __name__ == '__main__':
    unittest.main()