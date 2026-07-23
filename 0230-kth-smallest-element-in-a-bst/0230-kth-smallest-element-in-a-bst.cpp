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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *>st;
        st.push(root); 
        TreeNode *t=root;
        t=t->left;
        while(t || !st.empty())
        {
            while(t!=NULL)
            {
                st.push(t);
                t=t->left;
            }

            t=st.top();
            st.pop();
            k--;
            if(k==0)
            {
                return t->val;
            }
            t=t->right;
        }
        return -1;
    }
};