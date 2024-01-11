/*
Ques: 1026. Maximum Difference Between Node and Ancestor
Link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
Medium

Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.
A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
*/
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
    int maxDiff(TreeNode*root, int maxV, int minV){
        if(!root){
            return abs(maxV-minV);
        }
        minV = min(minV,root->val);
        maxV = max(maxV,root->val);

        return max(maxDiff(root->left,maxV,minV), maxDiff(root->right,maxV,minV));
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int maxV = INT_MIN;
        int minV = INT_MAX;

        return maxDiff(root,maxV,minV);
    }
};
