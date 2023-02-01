//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int total=0;
	    for(int i=0;i<n;i++){
	        total+=arr[i];
	    }
	    vector<vector<int>> memo(n+1,vector<int>(total+1,-1));
	    return solve(arr,n,0,total,memo);
	} 
	int solve(int arr[],int n,int sum1,int total,vector<vector<int>>& memo){
	    if(n==0){
	        return abs(sum1-(total-sum1));
	    }
	    if(memo[n][sum1]!=-1) return memo[n][sum1];
	    return memo[n][sum1]=min(
	    solve(arr,n-1,sum1,total,memo),
	    solve(arr,n-1,sum1+arr[n-1],total,memo));
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

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends