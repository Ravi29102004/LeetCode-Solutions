class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        //create data adj list
        vector<int>adj[n];
        // for(auto & relation:realtions)
        // {
        //     int u=relation[0];
        //     int v=realtion[1];
        //     adj[u].push_back(v);
        // }
        for(int i=0;i<relations.size();i++)
        {
            //converting them into 0 based indexing
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
        }

        //Indexing ke through fillup kar do 
        vector<int>InDeg(n,0);
        for(int i=0;i<n;i++)
        for(int j=0;j<adj[i].size();j++)
          InDeg[adj[i][j]]++;
        
        queue<int>q;
        for(int i=0;i<n;i++)
        if(!InDeg[i])
        q.push(i);

        //Maximum time complete previous course time
        vector<int>CourseTime(n,0);

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            for(int j=0;j<adj[node].size();j++)
            {
                InDeg[adj[node][j]]--;
                if(!InDeg[adj[node][j]])
                q.push(adj[node][j]);

                //Maximum time to complete previous time+current time
                 CourseTime[adj[node][j]]=max(CourseTime[adj[node][j]],CourseTime[node]+time[node]);

            }
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,CourseTime[i]+time[i]);
        }

        return ans;



    }
};