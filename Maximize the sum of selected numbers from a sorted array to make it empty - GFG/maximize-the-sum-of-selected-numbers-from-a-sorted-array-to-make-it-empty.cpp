//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
   int maximizeSum(int a[], int n) 

    {

        // Complete the function

        int res=0;

        sort(a,a+n);

        unordered_map<int,int>umap;

        for(int i=0;i<n;i++) umap[a[i]]++;

        for(int i=n-1;i>=0;i--){

            if(umap[a[i]]>0){

                res+=a[i];

                umap[a[i]]--;

                if(umap.find(a[i]-1)!=umap.end())

                umap[a[i]-1]--;

            }

        }

        return res;

    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends