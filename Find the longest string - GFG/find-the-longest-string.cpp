//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
   bool check(string s,vector<string> &v)

    {

       

        string temp="";

        for(int i=0;i<s.length();i++)

        {

            temp+=s[i];

            if(!binary_search(v.begin(),v.end(),temp))

            {

                return false;

            }

        }

        return true;

    }

 

    string longestString(vector<string> &v)

    {

        string res="";

        

        sort(v.begin(),v.end());

        

        int n=v.size();

       

        

        for(int i=v.size()-1;i>=0;i--)

        {

            

            string t=v[i];

            

            if(check(t,v) and res.length()<=t.length() )

            {

                res=t;

                

            }

        }

        

        return res;

        

    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends