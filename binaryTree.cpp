/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//中序遍历，Morris写法
class Solution {
public:
    TreeNode* findLeftMostRight(TreeNode* tree){
        TreeNode* cur = tree->left;
        while(cur!=nullptr && cur->right!=nullptr && cur->right!=tree)
            cur = cur->right;
        return cur;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        TreeNode* tmp = nullptr;
        while(root)
        {
            if(!root->left){ //如果左子树是空，记录当前节点并继续遍历右子树
                ans.push_back(root->val);
                root = root->right;
            }else{ //左子树不空
                tmp = findLeftMostRight(root); //找左子树中最右边的节点
                if(tmp->right == root){ //如果最右边节点的right已经指向当前节点，说明已经是第二轮遍历了，左子树都处理完了，则记录当前节点，继续遍历右子树
                    ans.push_back(root->val);
                    tmp->right = nullptr;
                    root = root->right;
                }else{ //没有指向当前节点则说明左子树还没有处理完，继续处理左子树
                    tmp->right = root;
                    root = root->left;
                }
            }
        }
        return ans;
    }
};

//中序遍历，循环写法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur!=nullptr || !s.empty()){ //cur不是空指针的话继续遍历右子树，cur是空指针的话直接提取当前栈顶元素
            while(cur!=nullptr){  //从根节点开始一直找左子树节点，直到找到最左边的叶子节点
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();  //提取栈顶元素
            s.pop();
            ans.push_back(cur->val); //cur的左子树和本身已经记录到ans中
            cur = cur->right; //继续处理cur的右子树
        }
        return ans;
    }
};

//前序遍历，Morris写法
class Solution {
public:
    TreeNode* findLeftMostRight(TreeNode* tree){
        TreeNode* node = tree->left;  //进入左子树
        while(node!=nullptr && node->right!=nullptr && node->right!=tree){
            node = node->right; //循环找左子树的最右边节点，最右边节点的right值要么是nullptr说明到达叶子节点
            //要么是当前树的根节点，说明是第二轮循环到最右边节点
        }
        return node;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* tmp = nullptr;
        if(!root) return ans;
        while(root)
        {
            if(!root->left){   //若左边是空，则直接记录下当前节点值并继续遍历右子树
                ans.push_back(root->val);
                root = root->right;
            }else{  //若左边不是空
                tmp = findLeftMostRight(root); //找到当前左子树中的最右边节点
                if(tmp->right != root){   //若最右边节点的right不是当前节点，说明是第一轮遍历
                    ans.push_back(root->val);  //记录当前节点
                    tmp->right = root;         //将左子树最右边节点的right指向当前节点
                    root = root->left;         //继续遍历左子树
                }else{   //若左子树的最右边节点指向当前节点，说明当前节点以及其左子树都全部处理完了
                    tmp->right = nullptr;  //将左子树的最右边节点的right恢复成nullptr
                    root = root->right;    //继续遍历当前节点的右子树
                }
            }
        }
        return ans;
    }
};

//前序遍历非递归写法 stack
/*
借用栈来实现，先序遍历为 root --> left --> right
每次从栈中提取出来的节点，将root->val放入ans数组中
然后将root->right入栈，再将root->left入栈，这样在出栈的时候将会先提取到root->left
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* tmp;
        while(!s.empty())
        {
            tmp=s.top();
            s.pop();
            ans.push_back(tmp->val);
            if(tmp->right) s.push(tmp->right);
            if(tmp->left)  s.push(tmp->left);
        }
        return ans;
    }
};

//前序遍历  递归写法
class Solution {
public:
    void search(TreeNode* tree){
        ans.push_back(tree->val);
        if(tree->left)
            search(tree->left);
        if(tree->right)
            search(tree->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return ans;
        search(root);
        return ans;
    }
private:
    vector<int> ans;
};

//二叉树的层次遍历  queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int cnt;
        TreeNode* tmp;
        while(!q.empty())   //BFS 广度优先搜索
        {
            cnt=q.size();   //当前层有cnt个节点
            vector<int> subans;  //每层的节点的值存到vector数组中
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
            ans.push_back(subans); //将一位数组加入结果的二维数组中去
        }
        return ans;
    }
};
