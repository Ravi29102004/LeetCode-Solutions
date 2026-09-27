class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
          vector<pair<int, pair<int,int>>>temp;
        for(int i=0;i<matrix.size();i++)
        {
            temp.push_back(make_pair(matrix[i][0], make_pair(i,0)));
        }
        
        //create Minheap
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>p(temp.begin(),temp.end());
        
        //data(value),row,column
        int ans;
        pair<int, pair<int,int>>Element;
        int i,j;
        
        while(k--)
        {
            Element=p.top();
            p.pop();
            ans=Element.first;      //value
            i=Element.second.first;   //row number 
            j=Element.second.second;   //column number 
            //ab agar 16 ko out karte hai to uske baad 28 ko enter bhi to karwana hai
            if(j+1<matrix.size())
            p.push(make_pair(matrix[i][j+1], make_pair(i,j+1)));
        }
        
        return ans;
    }
};