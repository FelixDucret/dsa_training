#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key, int val) : key(key), val(val), left(nullptr), right(nullptr) {}
};


class TreeMap {
private:
    TreeNode* root;

    TreeNode* findMin(TreeNode* node) {
        if(node == nullptr) {
            return node;
        }

        while(node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* removeHelper(TreeNode* node, int key) {
        if(node == nullptr) {
            return node;
        }

        if(key > node->key) {
            node->right = removeHelper(node->right, key);
        } else if(key < node->key) {
            node->left = removeHelper(node->left, key);
        } else {
            if(node->left == nullptr) {
                return node->right;
            } else if(node->right == nullptr) {
                return node->left;
            } else {
                TreeNode* minNode = findMin(node->right);
                node->key = minNode->key;
                node->val = minNode->val;
                node->right = removeHelper(node->right, minNode->key);
            }
        }
        return node;
    }

    void inorderTraversal(TreeNode* root, vector<int>& result) {
        if(root != nullptr) {
            inorderTraversal(root->left, result);
            result.push_back(root->key);
            inorderTraversal(root->right, result);
        }
    }

public:
    TreeMap() {
        root = nullptr;
    }

    void insert(int key, int val) {
        TreeNode* newNode = new TreeNode(key, val);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        TreeNode* curr = root;

        while(true) {
            if(key < curr->key) {
                if(curr->left == nullptr) {
                    curr->left = newNode;
                    return;
                }
                curr = curr->left;
            } else if(key > curr->key) {
                if(curr->right == nullptr) {
                    curr->right = newNode;
                    return;
                }
                curr = curr->right;
            } else {
                curr->val = val;
                return;
            }
        }

    }

    int get(int key) {
        TreeNode* current = root;
        while(current != nullptr) {
            if(key < current->key) {
                current = current->left; 
            }
            else if(key > current->key) {
                current = current->left;
            }
            else {
                return current->val;
            }
        }
        return -1;
    }

    int getMin() {
        TreeNode* minNode = findMin(root);
        if(minNode == nullptr) {
            return -1;
        }
        return minNode->val;
    }

    int getMax() {
        if(root == nullptr) {
            return -1;
        }
        TreeNode* current = root;
        while(current->right != nullptr) {
            current = current->right;
        }
        return current->val;
    }

    void remove(int key) {
        root = removeHelper(root, key);
    }

    vector<int> getInorderKeys() {
        vector<int> result;
        inorderTraversal(root, result);
        return result;
    }
};
