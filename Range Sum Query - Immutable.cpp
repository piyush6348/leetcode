class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int> nums) {
        //(nums.size()+1,0);
        dp.resize(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++){
         dp[i]=nums[i-1]+dp[i-1];
         cout<<dp[i]<<" ";
        }
    }

    int sumRange(int i, int j) {
        return (dp[j+1]-dp[i]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
