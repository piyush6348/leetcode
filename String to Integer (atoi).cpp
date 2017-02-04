class Solution {
public:
    int myAtoi(string str) {
        long ans=0;
        long len=str.length()-1,mul=1;
        bool con=false;
        for(long i=0;i<=len;i++){

            long val=(str[i]-'0');
            if((val>=0 && val<=9) || str[i]=='-' || str[i]=='+')
            {
                if(val>=0 && val<=9){
                 ans=ans*10+val;
                 con=true;
                }
                if(str[i]=='-')
                    mul=-1;
                    for(long j=i+1;j<=len;j++){
                        long temp=(str[j]-'0');
                        if(temp>=0 && temp<=9){
                            ans=ans*10+temp;
                            con=true;

                            if(ans>=2147483647)
                            {
                                //mul=1;
                                break;
                            }
                        }else{
                            break;
                        }
                    }
                    break;
            }else if(str[i]==' '){

            }else{
                break;
            }
        }

        if(ans>=2147483647 && mul==1)
        return (mul*2147483647);

        else if(ans>=2147483648 && mul==-1)
        return (mul*2147483648);

        if(con)
        return (ans*mul);
        else
        return (0);
    }
};
