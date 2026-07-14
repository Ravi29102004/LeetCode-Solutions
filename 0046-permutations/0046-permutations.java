class Solution {

    public void permut(List<Integer> nums, List<List<Integer>> ans, int index)
    {
        if(index==nums.size())
        {
            ans.add(new ArrayList<>(nums));
            return ;
        }
        for (int i=index;i<nums.size();i++)
        {
            //  swap(nums.get(i),nums[index]);
            //  permut(nums,ans,index+1);
            //  swap(nums[i],nums[index]);
              // Swap
              Collections.swap(nums,i,index);
              //recursive call
              permut(nums,ans,index+1);
              Collections.swap(nums,i,index);
           
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        //List<List<Integer>>ans=new ArrayList<>();
       
        List<Integer> list = new ArrayList<>();

        for (int num : nums) {
            list.add(num);
        }

        List<List<Integer>> ans = new ArrayList<>();

        permut(list, ans, 0);

        return ans;
    }
}