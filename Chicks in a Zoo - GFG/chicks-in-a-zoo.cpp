//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
long long int f(int n)

{

    if(n<1) return 0;

    if(n==1) return 1;

    if(n<6)

    {

        return 3*f(n-1);

    }

    else{

        return 3*f(n-1)-2*f(n-6);

    }

}

 long long int NoOfChicks(int n){

     // Code here

     //return f(n)-f(n-6);

     vector<long long>dp(n+1);

     dp[0]=0,dp[1]=1;

     for(int i=2;i<=n;i++)

     {

         if(i<6)

         {

             dp[i]=(3*dp[i-1]);

         }

         else if(i>=6){

             dp[i]=3*dp[i-1]-2*dp[i-6];

         }

     }

     if(n<6) return dp[n];

     else{

         return dp[n]-dp[n-6];

     }

 

 }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends