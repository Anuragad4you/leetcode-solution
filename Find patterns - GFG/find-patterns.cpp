//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
   int numberOfSubsequences(string s, string w){
        int n=s.size(), m=w.size(), ans=0, flg=1;
        while(flg)
        {
            int i=0, j=0, cnt=0;
            for(; i<m; i++)
            for(; j<n; j++)
                if(s[j] == w[i])
                {s[j++]='#'; cnt++; break;}
                    
            cnt == m ? ans++ : flg=0;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends