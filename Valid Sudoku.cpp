class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        bool correct=false;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                int rowl=0,rowh=0,coll=0,colh=0;
                
                if(i>=0 && i<=2)
                {
                    rowl=0;
                    rowh=2;
                }
                else if(i>=3 && i<=5)
                {
                    rowl=3;
                    rowh=5;
                }
                else if(i>=6 && i<=8)
                {
                    rowl=6;
                    rowh=8;
                }
                
                if(j>=0 && j<=2)
                {
                    coll=0;
                    colh=2;
                }
                
                else if(j>=3 && j<=5)
                {
                    coll=3;
                    colh=5;
                }
                
                else if(j>=6 && j<=8)
                {
                    coll=6;
                    colh=8;
                }
                
                if(board[i][j]!='.')
                {
                    bool cond1=false,cond2=false,cond3=false;
                    int ct=0;
                    
                    for(int col=0;col<board.size();col++)
                    {
                        if(board[i][col]==board[i][j])
                            ct+=1;
                    }
                    if(ct==1)
                    {   cond1=true;
                        ct=0;
                        for(int row=0;row<board.size();row++)
                        {
                            if(board[row][j]==board[i][j])
                                ct+=1;
                        }
                        if(ct==1)
                        {
                            cond2=true;   
                            ct=0;
                            for(int l=rowl;l<=rowh;l++)
                            {
                                for(int h=coll;h<=colh;h++)
                                {
                                    if(board[l][h]==board[i][j])
                                        ct+=1;
                                }
                            }
                    
                            if(ct==1)
                                cond3=true;
                        }
                    }
                    
                    if(cond1 && cond2 && cond3 )
                        correct=true;
                    else{
                        correct=false;
                        return correct;
                    }
                    cout<<rowl<<" "<< rowh<<" "<<coll<<" "<<colh<<" "<< cond1<<" "<<cond2<<" "<<cond3<<correct<<"\n";
                }
            }
        }
        
        return correct;
    }
};