class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;

        //Algorithm ke logic using kiye hue dutch national flag for using it one traversing and t.c.->o(n) and s.c.->o(1);
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;

            }
            else if(nums[mid]==1)
            {
                    mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
               
            
        }
    }
};