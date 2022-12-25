//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
   long long int MissingNo(vector<vector<int> >& matrix) {
        
        int n = matrix.size();
        vector<long long int> row(n, 0);
        long long int ldia = 0, rdia = 0;
        long long int x=-1, y=-1;
        bool isldia = false, isrdia = false;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                if(matrix[i][j] == 0){
                    x = i;
                    y = j;
                    
                    // Checking if 0 lies in diagonal
                    if(i == j) isldia = true;
                    if(j == n-1-i) isrdia = true;
                }
                
                row[i] += matrix[i][j];

                if(i == j){
                    ldia += matrix[i][j];
                }
                // Important: Dont use else because there is always intersection in two diagonals
                if(j == n-1-i){
                    rdia += matrix[i][j];
                }
            }
        }
        
        // Finding value requried for equal row sum and col sum
        long long int rowVal = (x == n-1) ? row[x-1] - row[x] : row[x+1] - row[x];

        // updating rowsum and colsum to make value equal
        row[x] += rowVal;
    
        // checking if row sum and col sum are equal or not after updating new value
        for(int i=0; i<n-1; i++){
            
            if(row[i] != row[i+1])
                return -1;
        }
        
        // If 0 does not lie on any diagonal or lie on both diagonal, we found unique value we return rowVal
        // And sum of left diagonal and right diagonal are same
        // Note: if 0 lies in both diagonal no need to calculate sum of diagonal again as the new value will
        // be added to both the diagoanls
        if(isldia == false && isrdia == false || isldia == true && isrdia == true){

            if(ldia == rdia)
                return (rowVal > 0) ? rowVal : -1;
            return -1;
        }
        
        // If 0 lies on diagonal we again have to calculate sum
        long long int newLeftDia = 0, newRightDia = 0;
        
        if(isldia == true){
			newLeftDia = ldia + rowVal;
			newRightDia = rdia;
		}
		else{
			newLeftDia = ldia;
			newRightDia = rdia + rowVal;
		}
        
        if(newRightDia != newLeftDia)
            return -1;
            
        return (rowVal > 0) ? rowVal : -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends