class Solution {
public:
    string intToRoman(int num) {
        
        int temp=num;
        vector<string> vec(4000);
        vec[1]="I";
        vec[2]="II";
        vec[3]="III";
        vec[4]="IV";
        vec[5]="V";
        vec[6]="VI";
        vec[7]="VII";
        vec[8]="VIII";
        vec[9]="IX";
        vec[10]="X";
        vec[40]="XL";
        vec[50]="L";
        vec[100]="C";
        vec[90]="XC";
        vec[400]="CD";
        vec[500]="D";
        vec[900]="CM";
        vec[1000]="M";
        //cout<<vec[45];
        string s="";
        while(temp>0)
        {
            if((vec[temp].length()!=0))
            {
                //cout<<vec[temp];
                s+=vec[temp];
                temp=0; 
            }
            else if(temp<40)
            {
                //cout<<vec[10];
                s+=vec[10];
                temp-=10;
            }
            else if(temp>40 && temp<50)
            {
                s+=vec[40];
                temp-=40;
            }
            else if(temp>=50 && temp<=89)
            {
                //cout<<vec[50];
                s+=vec[50];
                temp-=50;
            }
            else if(temp>=91 && temp<=99)
            {
                //cout<<vec[90];
                s+=vec[90];
                temp-=90;
            }
            else if(temp>100 && temp<=399)
            {
                //cout<<vec[100];
                s+=vec[100];
                temp-=100;
            }
            else if(temp>400 && temp<500)
            {
                s+=vec[400];
                temp-=400;
            }
            else if(temp>500 && temp<900)
            {
                s+=vec[500];
                temp-=500;
            }
            else if(temp>900 && temp<1000)
            {
                s+=vec[900];
                temp-=900;
            }
            else if(temp>1000)
            {
                s+=vec[1000];
                temp-=1000;
            }
        }
        cout<<s;
        return s;
    }
};