class TreeNode:
    def __init__(self, label):
        self.label = label
        self.left = None
        self.right = None

class Tree:
    def __init__(self):
        self.root = None

    def set_root(self, node):
        self.root = node

    def get_root(self):
        return self.root

    def set_left(self, parent, child):
        if parent:
            parent.left = child

    def set_right(self, parent, child):
        if parent:
            parent.right = child

    def preorder(self, node, visit):
        if node:
            visit(node.label)
            self.preorder(node.left, visit)
            self.preorder(node.right, visit)

    def inorder(self, node, visit):
        if node:
            self.inorder(node.left, visit)
            visit(node.label)
            self.inorder(node.right, visit)

    def postorder(self, node, visit):
        if node:
            self.postorder(node.left, visit)
            self.postorder(node.right, visit)
            visit(node.label)

    def is_empty(self):
        return self.root is None

    def clear(self):
        self.root = None
