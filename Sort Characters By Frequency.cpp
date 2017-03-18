class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> um;
        typedef pair<int,char> elem;
        priority_queue<elem> pq;
        for(int i=0;i<s.length();i++)
        {
            auto itr=um.find(s[i]);
            if(itr!=um.end())
            {
                itr->second+=1;
            }
            else
                um[s[i]]=1;
        }
        for(auto itr=um.begin();itr!=um.end();itr++)
            pq.push(make_pair(itr->second,itr->first));
        string ans="";
        while(!pq.empty())
        {
            int ct=pq.top().first;
            char ch=pq.top().second;
            for(int i=1;i<=ct;i++)
                ans+=ch;
            pq.pop();
        }
        return ans;
    }
};