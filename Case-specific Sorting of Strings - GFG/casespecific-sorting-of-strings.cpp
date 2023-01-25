//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
   string caseSort(string str, int n)
    {
        vector<char>v(n);
        for (int i = 0; i<n; i++) {
            if(str[i]>=65 && str[i]<=90) v[i] = 0;
            else v[i] = 1;
        }
        sort(str.begin(),str.end());
        int x = 0;
        for (int i = 0; i<n; i++) {
            if (v[i]==0) {
                v[i] = str[x];
                x++;
            }
        }
        for (int i = 0; i<n; i++) {
            if (v[i]==1) {
                v[i] = str[x];
                x++;
            }
        }
        string news = "";
        for (auto x:v) {
            news.push_back(x);
        }
        return news;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends