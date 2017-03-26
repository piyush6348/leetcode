class Solution {
public:
    int hammingDistance(int x, int y) {
        vector<int> num1=getBinary(x);
        vector<int> num2=getBinary(y);

        long l1=num1.size();
        long l2=num2.size();
        if(l1<l2)
        {
            for(long i=1;i<=l2-l1;i++)
            num1.push_back(0);
        }
        else
        {
            for(long i=1;i<=l1-l2;i++)
            num2.push_back(0);
        }

        long ct=0;

        for(long i=0;i<num1.size();i++)
        {
            if(num1[i]!=num2[i])
                ct+=1;
        }
        return ct;
    }
    vector<int> getBinary(long temp)
    {
        vector<int> binary_vec;
        if(temp==0)
            binary_vec.push_back(0);
        while(temp>0)
        {
            int x=temp%2;
            temp=temp/2;
            binary_vec.push_back(x);
        }
        return binary_vec;
    }
};
