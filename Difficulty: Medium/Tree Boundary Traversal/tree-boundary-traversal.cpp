/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:

    bool isLeaf(Node* node) {
        return (node->left == NULL && node->right == NULL);
    }

    void addLeftBoundary(Node* root, vector<int>& ans) {
        Node* curr = root->left;

        while(curr) {
            if(!isLeaf(curr))
                ans.push_back(curr->data);

            if(curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addLeaves(Node* root, vector<int>& ans) {
        if(root == NULL) return;

        if(isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }

        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }

    void addRightBoundary(Node* root, vector<int>& ans) {
        Node* curr = root->right;
        vector<int> temp;

        while(curr) {
            if(!isLeaf(curr))
                temp.push_back(curr->data);

            if(curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        // Add in reverse
        for(int i = temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
    }

    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;

        if(root == NULL) return ans;

        // Add root
        if(!isLeaf(root))
            ans.push_back(root->data);

        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);

        return ans;
    }
};