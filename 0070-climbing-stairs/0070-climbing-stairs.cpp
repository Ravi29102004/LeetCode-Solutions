// class Solution {
// public:

// int count(int i, int n)
// {
//     if(i==n)
//     return 1;

//     if(i>n)
//     return 0;

//     // if(dp[i]!=-1)
//     // return dp[i];

//     return count(i+1,n)+count(i+2,n);
// }


//     int climbStairs(int n) {

//        return count(0,n); 
//     }
// };





///////==========================top-down approach concept using ============================



// class Solution {
// public:

// int count(int i, int n, vector<int> &dp)
// {
//     if(i==n)
//     return 1;

//     if(i>n)
//     return 0;

//     if(dp[i]!=-1)
//     return dp[i];

//     return dp[i] = count(i+1,n,dp)+count(i+2,n,dp);
// }


//     int climbStairs(int n) {

//         vector<int>dp(n+2,-1);

//        return count(0,n,dp); 
//     }
// };








////======================Bottom Up Approach===========================
// class Solution {
// public:

// int count(int i, int n, vector<int> &dp)
// {
//     if(i==n)
//     return 1;

//     if(i>n)
//     return 0;

//     for(int i=n-1;i>=0;i--)
//     {
//         dp[i]=dp[i+1]+dp[i+2];
//     }
//     return dp[0];
// }


//     int climbStairs(int n) {

//         vector<int>dp(n+2,-1);

// ///Base Case
//         dp[n]=1;
//         dp[n+1]=0;

//        return count(0,n,dp); 
//     }
// };




///////////==================Space Optimisation==================
// class Solution {
// public:




//     int climbStairs(int n) {

//         vector<int>dp(n+2,-1);

//         // dp[n]=1;
//         // dp[n+1]=0;

//         int curr, next=1, next2=0;

//         for(int i=n-1;i>=0;i--)
//         {
//              curr=next+next2;
//              next2=next;
//              next=curr;
//         }

//        return curr; 
//     }
// };





/////////////========Method-2 approch using for it nth position starting from it============
class Solution {
public:

     int count(int n, vector<int> &dp)
     {
        if(n<=1)
        return 1;


        if(dp[n]!=-1)
        return dp[n];


        return dp[n]=count(n-1,dp)+count(n-2,dp);
     }


    int climbStairs(int n) {

        vector<int>dp(n+1,-1);

        return count(n,dp);
    }
};



  

