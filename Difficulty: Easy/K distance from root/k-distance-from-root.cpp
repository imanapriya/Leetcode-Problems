/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
  
    void solve(Node* root, int k, vector<int>& ans) {
        if(root == NULL) return;
        
        if(k == 0) {
            ans.push_back(root->data);
            return;
        }
        
        solve(root->left, k - 1, ans);
        solve(root->right, k - 1, ans);
    }
  
    vector<int> Kdistance(Node *root, int k) {
        vector<int> ans;
        solve(root, k, ans);
        return ans;
    }
};