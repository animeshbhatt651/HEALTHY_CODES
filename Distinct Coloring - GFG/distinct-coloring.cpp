//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int N, int r[], int g[], int b[]){
         long long int R = r[0], B = b[0], G = g[0];
 
 
 
    for (int i = 1; i < N; i++)
 
    {
 
       long long int rr = R, bb = B, gg = G;
 
 
 
        R = min(bb, gg) + r[i];
 
        B = min(rr, gg) + b[i];
 
        G = min(rr, bb) + g[i];
 
    }
 
 
 
    return min(R, min(B, G));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends