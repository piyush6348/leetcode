class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();i++)
        m[nums[i]]=i;
        
      /*  for(unordered_map<int,int> :: iterator itr=m.begin();itr!=m.end();itr++)
        cout<<itr->first<<" "<<itr->second<<"\n";*/
        
        vector<int> v;
        
        for(int i=0;i<nums.size();i++)
        {
            int com=target-nums[i];
            unordered_map<int,int> :: iterator itr=m.find(com);
            if(itr!=m.end())
            {
                if(itr->second!=i)
                {
                    if(i>itr->second)
                    {
                        v.push_back(itr->second);
                         v.push_back(i);
                    }
                    else
                    {
                        v.push_back(i);
                        v.push_back(itr->second);
                    }
                 break;
                }
            }
        }
        return v;
    }
};