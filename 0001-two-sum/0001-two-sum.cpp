class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>arr;
        for(int i=0;i<nums.size();i++)
        {
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        //vector<int>ans;
        int start=0, end=nums.size()-1;
        while(start<end)
        {
            //before unsorted
           // arr[i]	arr[i].first	arr[i].second
//            arr[0]	3	            0
//            arr[1]	2	            1
//            arr[2]	4	            2
           //after sortd
           //arr[i]	arr[i].first	arr[i].second
            //arr[0]	2	         1
            //arr[1]	3	         0
//             arr[2]	4	          2
            int sum=arr[start].first+arr[end].first;  //sum=3+2 ussiko kahte hai arr[i].first=3,
            if(sum==target)
            {
               return {arr[start].second,arr[end].second};   //arr[i].second=1
            }
            else if(sum<target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
       return {};
    }
};