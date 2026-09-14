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

TreeNode * ArrayToBST(vector<int>&nums,int start, int end)
{
    if(start>end)
    return nullptr;

    int mid=start+(end-start)/2;
    //TreeNode *root=ans.push_back(arr[mid]);
    TreeNode *root=new TreeNode(nums[mid]);

    root->left=ArrayToBST(nums, start, mid-1);
    root->right=ArrayToBST(nums, mid+1, end);

    return root;
}


    TreeNode* sortedArrayToBST(vector<int>& nums) {

       // vector<int>ans;
        int start=0;
        int end=nums.size()-1;
       return ArrayToBST(nums,start,end);
        //return ans;
    }
};