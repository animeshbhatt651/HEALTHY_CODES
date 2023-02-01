//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    int maxLength(string s){
        // code here
        stack<char>st ;
        stack<int>st_ind ;
        int ans = 0 ;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]) ;
                st_ind.push(i) ;
            }
            else if(s[i]==')'){
                if(st.empty()==false and st.top()=='('){
                    st.pop() ;
                    st_ind.pop() ;
                   if(st_ind.empty()==false) ans = max(ans , i-st_ind.top()) ;
                   else ans = max(ans , i+1) ;
                }
                else st_ind.push(i) ;
            }
        }
        return ans ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends