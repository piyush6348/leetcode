#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > vec;
    int n=0;
    void getSums(int index,vector<int> elem,int currentSum,vector<int>& nums,int currentIterator)
    {
        if((index>=n-1) || (currentSum==0 && elem.size()==3))
        {
            if(currentSum==0 && elem.size()==3)
            {
            sort(elem.begin(),elem.end());
             vec.push_back(elem);
             //return;
            }
            /*else if(((index==n-1) && currentSum!=0) || (elem.size()==3 && currentSum!=0))*/
                return;
        }
        else
        {   getSums(index+1,elem,currentSum,nums,currentIterator);
            elem.push_back(nums[index]);
            getSums(index+1,elem,currentSum+elem[currentIterator],nums,currentIterator+1);
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        n=nums.size();
        vector<int> elem;
        if(nums.size()!=0)
        getSums(0,elem,0,nums,0);


        for(int i=0;i<vec.size();i++)
        {
            for(int j=0;j<vec[i].size();j++)
                cout<<vec[i][j]<<" ";
            cout<<"\n";
        }
        sort(vec.begin(), vec.end());
        vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
        return vec;
    }
};

int main()
{
    Solution obj;
    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    obj.threeSum(v);
}
