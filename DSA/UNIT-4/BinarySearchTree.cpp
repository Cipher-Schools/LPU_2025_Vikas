#include <iostream>
#include <queue>
using namespace std;

// -------------------- Node Definition --------------------
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// -------------------- Insert in BST --------------------
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// -------------------- Traversals (DFS) --------------------

// Inorder: Left - Node - Right  -> (sorted output for BST)
void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Preorder: Node - Left - Right
void preorderTraversal(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder: Left - Right - Node
void postorderTraversal(Node* root) {
    if (root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// -------------------- Level Order (BFS) --------------------
void levelOrderTraversal(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }
}

// -------------------- Find Minimum in Right Subtree (Inorder Successor) --------------------
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// -------------------- Delete in BST --------------------
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else { // node found
        // Case 1: No children (leaf)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: Only right child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 3: Only left child
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 4: Both children exist
        else {
            Node* successor = findMin(root->right);
            root->data = successor->data;  // copy value
            root->right = deleteNode(root->right, successor->data); // delete duplicate
        }
    }
    return root;
}

// -------------------- Main Function --------------------
int main() {
    Node* root = nullptr;

    int values[] = {10, 5, 15, 2, 7, 20, 4};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; ++i) {
        root = insertNode(root, values[i]);
    }

    cout << "Initial Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Initial Level Order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    // Delete nodes
    cout << "\nDeleting 10...\n";
    root = deleteNode(root, 10);

    cout << "Inorder After Deletion: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Level Order After Deletion: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}

