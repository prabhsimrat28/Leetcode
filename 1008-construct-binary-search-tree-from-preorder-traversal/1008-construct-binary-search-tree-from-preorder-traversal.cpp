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

    TreeNode *fun(vector<int> &preorder,int &i,int low,int high)
    {
        if(i==preorder.size())
        {
            return NULL;
        }
        int val=preorder[i];
  
        if(val<low|| val>high)
        {
            return NULL;
        }

        TreeNode *node=new TreeNode(val);
        i++;
        node->left=fun(preorder,i,low,val);
        node->right=fun(preorder,i,val,high);
        return node;
    }


    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return fun(preorder,i,INT_MIN,INT_MAX);
    }
};