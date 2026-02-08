/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
public:
    bool isBalanced(TreeNode *root){
    	//your code goes here

        return maxDepth(root)!= -1;
    }

      int maxDepth(TreeNode* root) {
        //your code goes here

        if(root == nullptr){
            return 0;
        }

        int h_left = maxDepth(root->left);

        if(h_left==-1) return -1;
        int h_right = maxDepth(root->right);
        if(h_right==-1)return -1;

        if(abs(h_left - h_right)>1) return -1;
        return 1+max(h_left,h_right);
    }
};
