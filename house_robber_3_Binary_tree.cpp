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
public:
    // normal recursion
    int recurse(TreeNode* root){
        if(root==NULL)
            return 0;

        int inc=root->val;
        if(root->left){
            inc+=recurse(root->left->left);
            inc+=recurse(root->left->right);
        }
        if(root->right){
            inc+=recurse(root->right->left);
            inc+=recurse(root->right->right);
        }
        int exc=recurse(root->left)+recurse(root->right);
        return max(inc,exc);
    }
    int rob(TreeNode* root) {
        return recurse(root);
    }
    //top down memorization recursion
    int recurseDPTD(TreeNode* root,unordered_map<TreeNode*,int>& dp){
        if(root==NULL)
            return 0;
        if(dp.count(root))
            return dp[root];
        int inc=root->val;
        if(root->left){
            inc+=recurseDPTD(root->left->left,dp);
            inc+=recurseDPTD(root->left->right,dp);
        }
        if(root->right){
            inc+=recurseDPTD(root->right->left,dp);
            inc+=recurseDPTD(root->right->right,dp);
        }
        int exc=recurseDPTD(root->left,dp)+recurseDPTD(root->right,dp);
        dp[root]=max(inc,exc);
        return dp[root];
    }
    int robDPTD(TreeNode* root) {
        unordered_map<TreeNode*,int> dp;
        return recurseDPTD(root,dp);
    }
};