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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
        {
            return {};
        }
        vector<int> ans;

        map<int,int> m;
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int lvl=q.front().second;
            TreeNode *node=q.front().first;
            q.pop();
            if(m.find(lvl)==m.end())
            {
                m[lvl]=node->val;
            }
            if(node->right)
            {
                q.push({node->right,lvl+1});
            }
            if(node->left)
            {
                q.push({node->left,lvl+1});
            }
        }
        for(auto i:m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};