class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ct=0,i=0;
        while(i<nums.size())
        {
            if(nums[i]==val)
            {
                nums.erase(nums.begin()+i);
            }
            else
                i+=1;
        }
        return (nums.size());
    }
};