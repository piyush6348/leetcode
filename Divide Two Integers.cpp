class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign=0;
        if(divisor==0 ||(dividend==INT_MIN && divisor==-1))
            return INT_MAX;
        
        if(dividend<0 || divisor<0)
            sign=-1;
        else
            sign=1;
        
        if(dividend<0 && divisor<0)
            sign=1;
            
        long long dvd=labs(dividend);
        long long dvs=labs(divisor);
        int ans=0;
        while(dvd>=dvs){
            long long i=1,temp=dvs;
            while(dvd >= (temp<<1))
            {
                temp=temp<<1;
                i=i<<1;
            }
            dvd-=temp;
            ans+=i;
        }
        if(sign==1)
            return ans;
        else 
            return (-ans);
    }
};