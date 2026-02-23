/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  
    void dfs(Node* root, int hd, int level,
             map<int, pair<int,int>>& mp) {
        
        if(root == NULL) return;
        
        // If this hd is not seen before
        // OR current node is at smaller level
        if(mp.find(hd) == mp.end() || level < mp[hd].second) {
            mp[hd] = {root->data, level};
        }
        
        // Traverse left and right
        dfs(root->left, hd - 1, level + 1, mp);
        dfs(root->right, hd + 1, level + 1, mp);
    }
  
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        map<int, pair<int,int>> mp;
        
        dfs(root, 0, 0, mp);
        
        // Extract result in sorted order of hd
        for(auto it : mp) {
            ans.push_back(it.second.first);
        }
        
        return ans;
    }
};