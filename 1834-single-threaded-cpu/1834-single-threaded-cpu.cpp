class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        vector<int>ans;

        int n=tasks.size();
        for(int i=0;i<n;i++)
        tasks[i].push_back(i);

        //sort the task on the basis of enque time
        sort(tasks.begin(),tasks.end());

        long long timer=tasks[0][0];
        int i=0;

        //processing time, index
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>>p;

        
        while(!p.empty() || i<n)
        {
           //put all the task into the min heap whose enque time is less than or equal to timer
        while(i< n && timer>=tasks[i][0])
        {
            p.push({tasks[i][1], tasks[i][2]});
            i++;
        }

        //if min-heap is empty 
        if(p.empty())
        {
            timer=tasks[i][0];
        }
        // non-empty
        else 
        {
            // ans.push_back(p.top().second);
            // p.pop();
            // timer+=p.top().first;



            auto curr = p.top();
            ans.push_back(curr.second);
              p.pop();
             timer += curr.first;




            //    // Execute task with minimum processing time
            //   auto curr = p.top();
            //     p.pop();

            //     ans.push_back(curr.second);

            //     timer += curr.first;
        }

        }
        
      return ans;

    }
};