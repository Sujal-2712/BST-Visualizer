#include <iostream>
#include <queue>
using namespace std;

#define COUNT 5

// TreeNode structure to represent each node in the BST
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Binary Search Tree (BST) class
class BST {
private:
    TreeNode* root;

    // Helper function to insert a key recursively
    TreeNode* insertRecursive(TreeNode* node, int key) {
        if (node == nullptr) {
            return new TreeNode(key);
        }

        if (key < node->key) {
            node->left = insertRecursive(node->left, key);
        } else if (key > node->key) {
            node->right = insertRecursive(node->right, key);
        } else {
            // Handle duplicate keys (overwrite existing node)
            node->key = key;
        }

        return node;
    }

    // Helper function to find the node with the minimum key value
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Helper function to delete a key recursively
    TreeNode* deleteRecursive(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->key) {
            root->left = deleteRecursive(root->left, key);
        } else if (key > root->key) {
            root->right = deleteRecursive(root->right, key);
        } else {
            // Node to delete found
            // Case 1: Node with only one child or no child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 2: Node with two children
            TreeNode* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteRecursive(root->right, temp->key);
        }
        return root;
    }

    // Helper function to print the tree in 2D
    void print2DUtil(TreeNode* root, int space) {
        if (root == nullptr)
            return;

        space += COUNT;

        print2DUtil(root->right, space);

        cout << endl;
        for (int i = COUNT; i < space; i++)
            cout << " ";
        cout << root->key << "\n";

        print2DUtil(root->left, space);
    }

public:
    BST() : root(nullptr) {}

    // Function to insert a key into the BST
    void insert(int key) {
        root = insertRecursive(root, key);
    }

    // Function to remove a key from the BST
    void remove(int key) {
        root = deleteRecursive(root, key);
    }

    // Function to perform in-order traversal of the BST
    void inorderTraversal() {
        inorderRecursive(root);
        cout << endl;
    }

    // Function to visualize the BST in 2D
    void visualizeTree() {
        print2DUtil(root, 0);
        cout << endl;
    }

    // Helper function for in-order traversal
    void inorderRecursive(TreeNode* node) {
        if (node != nullptr) {
            inorderRecursive(node->left);
            cout << node->key << " ";
            inorderRecursive(node->right);
        }
    }
};

int main() {
    BST bst;
    int input, insert, removeKey;

    while (true) {
        cout << endl << endl;
        cout << " Binary Search Tree Operations " << endl;
        cout << " ----------------------------- " << endl;
        cout << " 1. Insertion/Creation " << endl;
        cout << " 2. Printing (In-order Traversal) " << endl;
        cout << " 3. Deletion " << endl;
        cout << " 4. Visualize the Tree " << endl;
        cout << " 5. Exit " << endl;
        cout << " Enter your choice : ";
        cin >> input;
        system("cls");

        switch (input) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> insert;
                bst.insert(insert);
                break;
            case 2:
                cout << "In-order Traversal: ";
                bst.inorderTraversal();
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> removeKey;
                bst.remove(removeKey);
                break;
            case 4:
                cout << "Visualizing the Tree: ";
                cout<<endl;
                bst.visualizeTree();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
