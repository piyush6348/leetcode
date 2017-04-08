class Solution {
public:
    vector<vector<char>> phonepad;
    vector<string> ans;
    void getStrings(int n,string&temp)
{
    if(n<=0)
    {   ans.push_back(temp);
        cout<<temp<<"\n";
        if(temp.length()>=1)
        temp.erase(temp.length()-1);
        return;
    }
    else
    {
        int x=1;
        int t=n,ct=0;
        while(t>0)
        {
            ct+=1;
            t=t/10;
            x=x*10;
        }
        x=x/10;

        int left_digit=n/x;
        for(int i=0;i<phonepad[left_digit-2].size();i++)
        {
            temp.insert(temp.length(),1,phonepad[left_digit-2][i]);
         getStrings(n%x,temp);
        }
        if(temp.length()>=1)
        temp.erase(temp.length()-1);
    }
}

    vector<string> letterCombinations(string digits) {
        int temp=97;
    for(int i=0;i<8;i++)
    {
        vector<char> v;
        if(i!=7 && i!=5)
        {
            for(int j=0;j<3;j++)
            {
                v.push_back((char)temp);
                temp+=1;
            }
        }
        else
        {
            for(int j=0;j<=3;j++)
            {
                v.push_back((char)temp);
                temp+=1;
            }
        }
        phonepad.push_back(v);
    }
    
    bool found=false;
    
    for(int i=0;i<digits.length();i++)
    {
        if(digits[i]=='1')
        {
            found=true;
            break;
        }
    }
    
    string k="";
    if(!found && digits.length()>0)
    getStrings(stoi(digits),k);
    
    return ans;
    }
};