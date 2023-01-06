//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    int shortestPath(int num1,int num2)
    {   
        // Complete this function using prime vector
        bool prime[10001];
        memset(prime,true,sizeof(prime));
        for(int i=2;i*i<=10000;i++)
        {
            if(prime[i])
            {
                for(int j=i*i;j<=10000;j+=i)
                {
                    prime[j] = false;
                }
            }
        }
        
        queue<int> q;
        q.push(num1);
        int lvl = 0;
        map<int,int> mp;
        mp[num1]++;
        
        while(!q.empty())
        {
            int size = q.size();
            for(int x=0;x<size;x++){
            int num = q.front();
            q.pop();
            if(num==num2)
            {
                return lvl;
            }
            string str = to_string(num);
            
            for(int i=0;i<4;i++)
            {
                string tmp = str;
                if(i==0)
                {
                    for(int j=1;j<=9;j++)
                    {
                        tmp[i] = j+'0';
                        int val = stoi(tmp);
                        if(mp.find(val)==mp.end() && prime[val])
                        {
                            mp[val]++;
                            q.push(val);
                        }
                    }
                }
                else
                {
                    for(int j=0;j<=9;j++)
                    {
                        tmp[i] = j+'0';
                        int val = stoi(tmp);
                        if(mp.find(val)==mp.end() && prime[val])
                        {
                            mp[val]++;
                            q.push(val);
                        }
                    }
                }
            }
            }
            
            lvl++;
            
            
        }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends