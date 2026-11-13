// class Solution {
// public:

//     int fib(int n) {

//         //  if(n<=1)
//         // return n;
         
//         // return fib(n-1)+fib(n-2);






        


//     }
// };




// class Solution
// {
//     public: 

//     int fibon(int n, vector<int> &dp)
//     {
         
//         //logic using dynamic programming.  using top-down approach 
       
//         if(n<=1)
//         return n;

//         //jo already value calculate kiye hue hai
//         if(dp[n] != -1)
//         return dp[n];


//         return fibon(n-1,dp)+fibon(n-2,dp);
//     }


//     int fib(int n)
//     {
//         vector<int>dp(n+1, -1);
//         return fibon(n,dp);
//     }
// };












//Logic using dp in bottom approach 
class Solution
{
    public: 

    int fibon(int n, vector<int> &dp)
    {
         
        //logic using dynamic programming.  using top-down approach 
       
        if(n<=1)
        return n;

        //jo already value calculate kiye hue hai
        if(dp[n] != -1)
        return dp[n];


        return fibon(n-1,dp)+fibon(n-2,dp);
    }


    int fib(int n)
    {
        if(n<=1)
        return n;
        vector<int>dp(n+1, -1);
        dp[0]=0;
        dp[1]=1;

        for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];

        return dp[n];
    }
};