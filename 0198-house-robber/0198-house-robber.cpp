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









// ///////////////=================DP Appraoch using top-down concept==================
// class Solution {
// public:

// int Robber(int index, vector<int> &nums, vector<int> &dp)
// {
//     if(index==0)
//     return nums[0];

//     if(index==1)
//     return max(nums[0], nums[1]);

//     if(dp[index]!=-1)
//     return dp[index];

//     return dp[index]=max(nums[index]+Robber(index-2, nums,dp), Robber(index-1, nums,dp));
// }


//     int rob(vector<int>& nums) {
        
//         int n=nums.size();
//         vector<int>dp(n, -1);
//         return Robber(n-1,nums,dp);
//     }
// };







// /////////////////////Bottom-Up Approach=========================
// class Solution {
// public:

// // int Robber(int index, vector<int> &nums, vector<int> &dp)
// // {
// //     if(index==0)
// //     return nums[0];

// //     if(index==1)
// //     return max(nums[0], nums[1]);

// //     return max(nums[index]+Robber(index-2, nums,dp), Robber(index-1, nums,dp));
// // }


//     int rob(vector<int>& nums) {
        
//         int n=nums.size();

//           if(n == 1)
//             return nums[0];

//         vector<int>dp(n,-1);
//         dp[0]=nums[0];
//         dp[1]=max(nums[0], nums[1]);

//         for(int i=2;i<n;i++)
//         {
//             dp[i]= max(nums[i]+dp[i-2], dp[i-1]);
//         }
//         return dp[n-1];
//     }
// };












/////////////Space Optimisation Concept================
class Solution {
public:

    int rob(vector<int>& nums) {
        
        int n=nums.size();

        if(n==1)
        return nums[0];

        if(n==2)
        return max(nums[0], nums[1]);

        vector<int>dp(n,-1);
        // dp[0]=nums[0];
        // dp[1]=max(nums[0], nums[1]);

        int curr, prev=max(nums[0], nums[1]) , prev1=nums[0];

        for(int i=2;i<n;i++)
        {
            curr= max(nums[i]+prev1, prev);
            prev1=prev;
            prev=curr;
        }
        return curr;
    }
};
