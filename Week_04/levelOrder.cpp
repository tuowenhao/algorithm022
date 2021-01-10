/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (NULL == root) return ans;
        queue<TreeNode*> q;
        q.push(root); 

        while (!q.empty()) {
            int size = q.size();
            ans.push_back({});
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                ans.back().push_back(node->val);
                if (node->left != NULL) {
                    q.push(node->left);
                } 
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};
