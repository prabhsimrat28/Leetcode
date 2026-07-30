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


    void fun(TreeNode *root,unordered_map<int,int> &mp)
    {
        if(root==NULL)
        {
            return;
        }

        fun(root->left,mp);
        mp[root->val]=1;
        fun(root->right,mp);

    }


    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>mp;
        fun(root,mp);
        for(auto it:mp)
        {
            if(mp.find(k-it.first)!=mp.end() && (k-it.first!=it.first))
            {
                return true;
            }
        }
        return false;
    }
};