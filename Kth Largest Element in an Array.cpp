class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++)
            pq.push(nums[i]);
        int ct=1;
        while(ct<k)
        {
            pq.pop();
            ct+=1;
        }
        return pq.top();
    }
};