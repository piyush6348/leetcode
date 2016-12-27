class Solution {
public:
    int romanToInt(string s) {
        
        map<char,int> mapp;
        mapp['M']=1000;
        mapp['D']=500;
        mapp['C']=100;
        mapp['L']=50;
        mapp['X']=10;
        mapp['V']=5;
        mapp['I']=1;
        
        int num=0,i;
        for( i=0;i<s.length()-1;i++)
        {
            if(mapp[s[i]]>=mapp[s[i+1]])
            {
                num+=mapp[s[i]];
            }
            else
            {
                num+=mapp[s[i+1]]-mapp[s[i]];
                i+=1;
            }
        }
        return num+mapp[s[i]];
    }
};