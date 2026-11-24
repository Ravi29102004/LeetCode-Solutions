// /////////////////////===============Recursive Concept Using===================///////////////////

// class Solution {
// public:

// int Robber(int index, vector<int> &nums)
// {
//     if(index==0)
//     return nums[0];

//     if(index==1)
//     return max(nums[0], nums[1]);

//     return max(nums[index]+Robber(index-2, nums), Robber(index-1, nums));
// }


//     int rob(vector<int>& nums) {
        
//         int n=nums.size();
//         return Robber(n-1,nums);
//     }
// };









///////////////=================DP Appraoch using top-down concept==================
class Solution {
public:

int Robber(int index, vector<int> &nums, vector<int> &dp)
{
    if(index==0)
    return nums[0];

    if(index==1)
    return max(nums[0], nums[1]);

    if(dp[index]!=-1)
    return dp[index];

    return dp[index]=max(nums[index]+Robber(index-2, nums,dp), Robber(index-1, nums,dp));
}


    int rob(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>dp(n+1, -1);
        return Robber(n-1,nums,dp);
    }
};