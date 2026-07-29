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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode *> par;
        queue<TreeNode *> q;
        q.push(root);
        par[root]=NULL;
        while(!q.empty())
        {
            TreeNode *parent=q.front();
            q.pop();
            if(parent->left)
            {
                q.push(parent->left);
                par[parent->left]=parent;
            }
            if(parent->right)
            {
                q.push(parent->right);
                par[parent->right]=parent;
            }
        }

        queue<TreeNode *> targetnode;
        targetnode.push(target);
        unordered_set<TreeNode *> visited;
        visited.insert(target);
        
        
        while(!targetnode.empty())
        {
            if(k==0)
            break;
            int s=targetnode.size();
            for(int i=0;i<s;i++)
            {
                TreeNode *node=targetnode.front();
                targetnode.pop();
                if(node->left && !visited.count(node->left))
                {
                    targetnode.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && !visited.count(node->right))
                {
                    targetnode.push(node->right);
                    visited.insert(node->right);
                }
                TreeNode *p=par[node];
                if(p && !visited.count(p))
                {
                    targetnode.push(p);
                    visited.insert(p);
                }
            }
            k--;
        }

        vector<int> ans;
        while(!targetnode.empty())
        {
            ans.push_back(targetnode.front()->val);
            targetnode.pop();
        }
        return ans;
    }
};