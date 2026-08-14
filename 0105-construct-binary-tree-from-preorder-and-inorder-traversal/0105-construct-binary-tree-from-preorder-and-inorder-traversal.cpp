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


    TreeNode * build(int &pidx,int start,int end,vector<int> &preorder,vector<int> &inorder,unordered_map<int,int> &mp)
    {
        if(start>end)
        {
            return NULL;
        }
        TreeNode *node=new TreeNode(preorder[pidx]);
        int idx=mp[preorder[pidx]];
        pidx++;
        node->left=build(pidx,start,idx-1,preorder,inorder,mp);
        node->right=build(pidx,idx+1,end,preorder,inorder,mp);
        return node;
    }



    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;//val,idx map
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int pidx=0;
        return build(pidx,0,inorder.size()-1,preorder,inorder,mp);
    }
};