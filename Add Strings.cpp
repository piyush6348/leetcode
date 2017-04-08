class Solution {
public:
    int makeEqualLength(string &num1, string &num2){
        int len1 = num1.size();
        int len2 = num2.size();
        if(len1 > len2){
            for(int i = 0; i< len1-len2;i++){
                num2 = '0' + num2;
            }
            return len1;
        }
        else if(len1 < len2){
            for(int i = 0; i< len2-len1;i++){
                num1 = '0' + num1;
            }
        }
        return len2;
        
    }
    string addStrings(string num1, string num2) {
        string result = "";
        int length = makeEqualLength(num1, num2);
        int carry = 0;
        
        cout<<num1<<" "<<num2<<endl;
        for(int i = length - 1;i >=0; i--){
            int first = num1[i] - '0';//int value of num1.at(i)
            int second = num2[i] - '0';//int value of num2.at(i)
            int sum = first + second + carry;
           // cout<<"sum: "<<sum<<endl;
            
            char ch=((sum%10)+'0');
            result = ch+ result;
            carry = sum/10;
        
        }
        if(carry){
            char ch=(carry+'0');
            result = ch + result;
        }
        return result;
        
}
    
};