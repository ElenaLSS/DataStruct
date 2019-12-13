//二叉树的层次遍历  queue
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
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int cnt;
        TreeNode* tmp;
        while(!q.empty())
        {
            cnt=q.size();   //当前层有cnt个节点
            vector<int> subans;
            while(cnt--)
            {
                tmp=q.front();
                q.pop();
                subans.push_back(tmp->val);
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            ans.push_back(subans);
        }
        return ans;
    }
};
