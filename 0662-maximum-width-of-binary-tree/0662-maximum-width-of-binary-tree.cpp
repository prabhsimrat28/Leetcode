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



    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode * , long long>> q;
        q.push({root,1});
        long long width=0;
        while(!q.empty())
        {
            int n=q.size();
            long long left=0;
            long long right=0;
            long long offset=q.front().second;
            for(int i=0;i<n;i++)
            {
                TreeNode *node=q.front().first;
                long long val=q.front().second-offset;
                q.pop();
                if(i==0)
                {
                    left=val;
                }
                if(i==n-1)
                {
                    right=val;
                }
                if(node->left)
                {
                    q.push({node->left,2*val});
                }
                if(node->right)
                {
                    q.push({node->right,2*val+1});
                }
            }
            width=max(width,right-left+1);     
        }
        return width;
    }
};