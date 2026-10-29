// class Solution {
// public:
//     //Brute Force Approach

//     //T.c:-O(n!).  and S.c:-O(n*n);
//     bool check(int n, vector<string> &Board, int i, int j)
//     {
//         //upper Left diagonal,  koi bhi queen diag ke upper side me exist naa ho
//         int row=i, col=j;
//         while(row>-1 && col>-1)
//         {
//             if(Board[row][col]=='Q')
//             return 0;
//             row--, col--;
//         }

//         //Lower Right diagonal,  koi bhi queen diag ke upper side me exist naa ho
//         row=i, col=j;
//         while(row>-1 && col<n)
//         {
//             if(Board[row][col]=='Q')
//             return 0;
//             row--,col++;
//         }

//         return 1;

//     }
    
//     void find(int row, int n, vector<vector<string>> &ans,vector<string> &Board, vector<bool> &column)
//     {
//         //Base Condition
//         if(row==n)
//         {
//             ans.push_back(Board);
//             return ;
//         }


//         //Put queen at any position
//         for(int j=0;j<n;j++)
//         {
//             if(column[j]==0 && check(n,Board,row,j))
//             {
//                 column[j]=1;
//                 Board[row][j]='Q';
//                 find(row+1,n,ans,Board,column);
//                 column[j]=0;
//                 Board[row][j]='.';

//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>>ans;
//         vector<string>Board(n);
//         for(int i=0;i<n;i++)
//         for(int j=0;j<n;j++)
//         Board[i].push_back('.');

//         vector<bool>column(n,0);

//         find(0,n,ans,Board,column);

//         return ans;
//     }
// };

//Optimised Approach
class Solution {
public:
   
    
   
    
    void find(int row, int n, vector<vector<string>> &ans,vector<string> &Board, vector<bool> &column, vector<bool> &leftDiag, vector<bool> &rightDiag)
    {
        //Base Condition
        if(row==n)
        {
            ans.push_back(Board);
            return ;
        }

        //leftDiag:-n-1+col-row;
        //rightDaig:-row+col;


        //Put queen at any position
        for(int j=0;j<n;j++)
        {
            if(column[j]==0 && leftDiag[n-1+j-row]==0 && rightDiag[row+j]==0)
            {
                //recursive concept
                column[j]=1;
                Board[row][j]='Q';
                leftDiag[n-1+j-row]=1;
                rightDiag[row+j]=1;

                find(row+1,n,ans,Board,column,leftDiag,rightDiag);
                //Backtracking concept using
                column[j]=0;
                Board[row][j]='.';
                 leftDiag[n-1+j-row]=0;
                rightDiag[row+j]=0;

            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>Board(n);
       
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        Board[i].push_back('.');

        vector<bool>leftDiag(2*n-1,0);
        vector<bool>rightDiag(2*n-1,0);

        vector<bool>column(n,0);
         

        find(0,n,ans,Board,column,leftDiag,rightDiag);

        return ans;
    }
};