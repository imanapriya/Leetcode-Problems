/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    
    void dfs(Node* root, Node*& pred, Node*& succ, int key) {
        if (!root) return;

        if (root->data < key) {
            pred = root;
            dfs(root->right, pred, succ, key);
        }
        else if (root->data > key) {
            succ = root;
            dfs(root->left, pred, succ, key);
        }
        else {
            if (root->left) {
                Node* t = root->left;
                while (t->right) t = t->right;
                pred = t;
            }
            if (root->right) {
                Node* t = root->right;
                while (t->left) t = t->left;
                succ = t;
            }
        }
    }

    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pred = NULL;
        Node* succ = NULL;
        dfs(root, pred, succ, key);
        return {pred, succ};
    }
};