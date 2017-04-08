#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int ans=0,n=0;

void func(int currentElem,vector<int>& height,int ct,int element)
{
    cout<<"current index : "<<currentElem<<" element : "<<element<<" ans : "<<ans<<"\n";
    if(currentElem>=n-1)
    {   if(ans<ct*element)
        {
            ans=ct*element;
        }
        cout<<"current index : "<<currentElem<<" element : "<<element<<" ans : "<<ans<<"\n";
        return;
    }
    else if(height[currentElem]>=element)
    {
        func(currentElem+1,height,ct+1,element);
        func(currentElem+1,height,0,height[currentElem]);
    }
    else
    {
        if(ans<ct*element)
        {
            ans=ct*element;
        }
        cout<<"current index : "<<currentElem<<" element : "<<element<<" ans : "<<ans<<"\n";
        return;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int x=0;
    cin>>n;
    vector<int> height;
    for(int i=0;i<n;i++)
        {
        cin>>x;
        height.push_back(x);
    }
    func(0,height,0,height[0]);
    cout<<ans<<"\n";
    return 0;
}

