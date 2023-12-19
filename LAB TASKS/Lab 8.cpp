#include <iostream>
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    int maxDepth(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        return 1 + max(leftDepth, rightDepth);
    }

    bool isBST(TreeNode* node, int minValue, int maxValue) {
        if (node == nullptr) {
            return true;
        }

        if (node->data < minValue || node->data > maxValue) {
            return false;
        }

        return isBST(node->left, minValue, node->data - 1) &&
               isBST(node->right, node->data + 1, maxValue);
    }

    void postOrderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    int depth() {
        return maxDepth(root);
    }

    bool isBST() {
        return isBST(root, INT_MIN, INT_MAX);
    }

    void traversePostOrder() {
        postOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Add numbers to the tree
    bst.insert(45);
    bst.insert(67);
    bst.insert(22);
    bst.insert(100);
    bst.insert(75);
    bst.insert(13);
    bst.insert(11);
    bst.insert(64);
    bst.insert(30);

    // Delete two nodes
    bst.deleteNode(22);
    bst.deleteNode(75);

    // Determine depth of the tree
    cout << "Depth of the tree: " << bst.depth() << endl;

    // Check if it's a Binary Search Tree
    cout << "Is it a Binary Search Tree? " << (bst.isBST() ? "Yes" : "No") << endl;

    // Traverse using post-order traversal
    cout << "Post-order traversal: ";
    bst.traversePostOrder();

    return 0;
}