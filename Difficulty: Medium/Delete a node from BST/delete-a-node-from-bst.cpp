/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    Node* findMin(Node* root) {
        while(root->left)
            root = root->left;
        return root;
    }
  
    Node* delNode(Node* root, int key) {
        if(!root) return NULL;
        
        if(key < root->data) {
            root->left = delNode(root->left, key);
        }
        else if(key > root->data) {
            root->right = delNode(root->right, key);
        }
        else {
            // Case 1: No child
            if(!root->left && !root->right)
                return NULL;
            
            // Case 2: One child
            else if(!root->left)
                return root->right;
            
            else if(!root->right)
                return root->left;
            
            // Case 3: Two children
            Node* successor = findMin(root->right);
            root->data = successor->data;
            root->right = delNode(root->right, successor->data);
        }
        
        return root;
    }
};