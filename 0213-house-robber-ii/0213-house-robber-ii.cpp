// class Solution {
// public:

//     int Robbery(vector<int> &nums)
//     {
//         int n=nums.size();
//           if(n==1)
//           return nums[0];

//           if(n==2)
//           return max(nums[0], nums[1]);

//           int curr, prev=max(nums[0], nums[1]), prev2=nums[0];

//           for(int i=2;i<n;i++)
//           {
//             curr=max(nums[i]+prev2, prev);
//             prev2=prev;
//             prev=curr;
//           }

//           return curr;
//     }


//     int rob(vector<int>& nums) {
//         int n=nums.size();

//         vector<int>arr1(n-1);
//         vector<int>arr2(n);

//         if(n==1)
//         return nums[0];

//         if(n==2)
//         return max(nums[0], nums[1]);

//         for(int i=0;i<n-1;i++)
//         {
//             arr1[i]=nums[i];
//         }
//         for(int i=1;i<n;i++)
//         {
//             arr2[i]=nums[i];
//         }

//         int curr1=Robbery(arr1);
//         int curr2=Robbery(arr2);

//         return max(curr1, curr2);
//     }
// };


// ///////////T.C-O(n) and S.C.->O(n)




/////////////Optimisation Method way using =================
class Solution {
public:

    

    int rob(vector<int>& nums) {
        int n=nums.size();

       

        if(n==1)
        return nums[0];

        if(n==2)
        return max(nums[0], nums[1]);

         int curr1, prev=max(nums[0], nums[1]), prev2=nums[0];
         curr1=prev;

          for(int i=2;i<n-1;i++)
          {
            curr1=max(nums[i]+prev2, prev);
            prev2=prev;
            prev=curr1;
          }
         int curr2;
          prev=max(nums[1], nums[2]), prev2=nums[1];
          curr2=prev;

          for(int i=3;i<n;i++)
          {
            curr2=max(nums[i]+prev2, prev);
            prev2=prev;
            prev=curr2;
          }

       
        return max(curr1, curr2);
    }
};