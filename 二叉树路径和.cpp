/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<vector<int>> ans;
public:
    void dfs(TreeNode* root, int sum, int num, vector<int> ivec){
        sum += root->val;
        ivec.push_back(root->val);
        if(sum > num) {
            sum -= root->val;
            ivec.pop_back();
            return;
        }
        if(sum == num) {
            ans.push_back(ivec);
            return;
        }
        if(root->left) dfs(root->left, sum, num, ivec);
        if(root->right) dfs(root->right, sum, num, ivec);
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(!root) return ans;
        vector<int> ivec;
        dfs(root, 0, target, ivec);
        return ans;
    }
};
