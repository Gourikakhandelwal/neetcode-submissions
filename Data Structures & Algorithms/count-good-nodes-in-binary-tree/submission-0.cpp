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

int cnt=0;
void func(TreeNode* root,int maxi){
    if(root==NULL)return ;
        if(maxi<=root->val){
            cnt++;
            maxi=root->val;
        }
        func(root->left,maxi);
        func(root->right,maxi);
}
    int goodNodes(TreeNode* root) {
        func(root,root->val);
        return cnt;
    }
};
