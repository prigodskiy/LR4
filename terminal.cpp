#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

#include "include/queue.h"
#include "include/stack.h"
#include "include/tree.h"

void print_stack(const Stack &stack) {
    if (stack_is_empty(&stack)) {
        std::cout << "(empty)\n";
        return;
    }
    for (int i = 0; i <= stack.top_index; ++i) {
        std::cout << stack.data[i] << " ";
    }
    std::cout << "\n";
}

void print_queue(const Queue &queue) {
    if (queue_is_empty(&queue)) {
        std::cout << "(empty)\n";
        return;
    }
    int index = queue.front_index;
    for (int i = 0; i < queue.count; ++i) {
        std::cout << queue.data[index] << " ";
        index = (index + 1) % QUEUE_MAX_SIZE;
    }
    std::cout << "\n";
}

void print_tree_ascii_helper(const TreeNode *node, const std::string &indent, bool is_left) {
    if (!node)
        return;
    std::cout << indent << (is_left ? "|--" : "'-- ") << node->label << "\n";
    print_tree_ascii_helper(node->left_child, indent + (is_left ? "|  " : "   "), true);
    print_tree_ascii_helper(node->right_child, indent + (is_left ? "|  " : "   "), false);
}

void print_tree_ascii(const Tree &tree) {
    if (tree_is_empty(&tree)) {
        std::cout << "(empty)\n";
        return;
    }
    std::cout << tree.root_node->label << "\n";
    print_tree_ascii_helper(tree.root_node->left_child, "", true);
    print_tree_ascii_helper(tree.root_node->right_child, "", false);
}

static void print_char_callback(char c) { std::printf("%c ", c); }

TreeNode *find_node_by_label(TreeNode *root, char target_label) {
    if (!root)
        return nullptr;
    if (root->label == target_label)
        return root;
    TreeNode *found = find_node_by_label(root->left_child, target_label);
    return found ? found : find_node_by_label(root->right_child, target_label);
}

void print_help_main() {
    std::cout << "s.help - stack operations\n"
              << "q.help - queue operations\n"
              << "t.help - tree operations\n"
              << "exit   - quit terminal\n";
}

void print_help_stack() {
    std::cout << "s.push <N> - push value N to stack\n"
              << "s.pop      - pop top value from stack\n"
              << "s.top      - show top value\n"
              << "s.print    - print stack contents\n";
}

void print_help_queue() {
    std::cout << "q.enq <N>  - enqueue value N\n"
              << "q.deq      - dequeue front value\n"
              << "q.front    - show front value\n"
              << "q.print    - print queue contents\n";
}

void print_help_tree() {
    std::cout << "t.root <C>     - create root with label C\n"
              << "t.left <P> <C> - add left child C to parent P\n"
              << "t.right <P> <C>- add right child C to parent P\n"
              << "t.print        - print tree structure\n"
              << "t.pre/in/post  - print traversal order\n"
              << "t.clear        - clear tree\n";
}

int main() {
    Stack stack;
    stack_init(&stack);
    Queue queue;
    queue_init(&queue);
    Tree tree;
    tree_init(&tree);

    std::cout << "Type 'help' for commands.\n> ";

    std::string input_line;
    while (std::getline(std::cin, input_line)) {
        std::istringstream iss(input_line);
        std::string command;
        iss >> command;

        if (command.empty()) {
            std::cout << "> ";
            continue;
        }
        if (command == "exit")
            break;

        if (command == "help")
            print_help_main();
        else if (command == "s.help")
            print_help_stack();
        else if (command == "q.help")
            print_help_queue();
        else if (command == "t.help")
            print_help_tree();

        else if (command == "s.push") {
            int value;
            iss >> value;
            if (!stack_push(&stack, value))
                std::cout << "[!] Stack is full.\n";
        }
        else if (command == "s.pop") {
            if (!stack_pop(&stack))
                std::cout << "[!] Stack is empty.\n";
        }
        else if (command == "s.top") {
            if (!stack_is_empty(&stack))
                std::cout << stack_top(&stack) << "\n";
            else
                std::cout << "[!] Stack is empty.\n";
        }
        else if (command == "s.print") {
            print_stack(stack);
        }

        else if (command == "q.enq") {
            int value;
            iss >> value;
            if (!queue_enqueue(&queue, value))
                std::cout << "[!] Queue is full.\n";
        }
        else if (command == "q.deq") {
            if (!queue_dequeue(&queue))
                std::cout << "[!] Queue is empty.\n";
        }
        else if (command == "q.front") {
            if (!queue_is_empty(&queue))
                std::cout << queue_front(&queue) << "\n";
            else
                std::cout << "[!] Queue is empty.\n";
        }
        else if (command == "q.print") {
            print_queue(queue);
        }

        else if (command == "t.root") {
            char label;
            iss >> label;
            if (tree.root_node) {
                std::cout << "[!] Root already exists. Use 't.clear' first.\n";
            }
            else {
                tree.root_node = tree_create_node(label);
                std::cout << "Root '" << label << "' created.\n";
            }
        }
        else if (command == "t.left") {
            char parent_label, child_label;
            iss >> parent_label >> child_label;
            TreeNode *parent = find_node_by_label(tree.root_node, parent_label);
            if (!parent)
                std::cout << "[!] Parent '" << parent_label << "' not found.\n";
            else
                tree_set_left(parent, tree_create_node(child_label));
        }
        else if (command == "t.right") {
            char parent_label, child_label;
            iss >> parent_label >> child_label;
            TreeNode *parent = find_node_by_label(tree.root_node, parent_label);
            if (!parent)
                std::cout << "[!] Parent '" << parent_label << "' not found.\n";
            else
                tree_set_right(parent, tree_create_node(child_label));
        }
        else if (command == "t.print") {
            print_tree_ascii(tree);
        }
        else if (command == "t.pre") {
            if (!tree_is_empty(&tree))
                tree_preorder(tree.root_node, print_char_callback);
            else
                std::cout << "(empty)";
            std::cout << "\n";
        }
        else if (command == "t.in") {
            if (!tree_is_empty(&tree))
                tree_inorder(tree.root_node, print_char_callback);
            else
                std::cout << "(empty)";
            std::cout << "\n";
        }
        else if (command == "t.post") {
            if (!tree_is_empty(&tree))
                tree_postorder(tree.root_node, print_char_callback);
            else
                std::cout << "(empty)";
            std::cout << "\n";
        }
        else if (command == "t.clear") {
            tree_free(&tree);
            tree_init(&tree);
            std::cout << "Tree cleared.\n";
        }
        else {
            std::cout << "[?] Unknown command. Type 'help'.\n";
        }
        std::cout << "> ";
    }
    return 0;
}