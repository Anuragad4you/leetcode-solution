//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     int longestPerfectPiece(int arr[], int N) {
        map<int,int>mp;
        int st = 0;
        int len = 0;
        for(int i=0;i<N;++i){
           ++mp[arr[i]];
           auto it1 = mp.begin();
           int str = it1->first;
           auto it2 = mp.rbegin();
           int end = it2->first;
           if(end-str<=1){
               int a = i-st+1;
               if(a>=len){
                   len = a;
               }
           }
           else{
               while(st<=i){
                   auto it3 = mp.begin();
                   int str = it3->first;
                   auto it4 = mp.rbegin();
                   int end = it4->first;
                    if(end-str<=1){
                        int a = i-st+1;
                         if(a>len){
                           len = a;
                     }
                     break;
                    }
                  if(mp[arr[st]]==1){
                       mp.erase(arr[st]);
                       ++st;
                   }
                   else{
                       --mp[arr[st]];
                       ++st;
                   }
               }
           }
            
        }
       return len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends