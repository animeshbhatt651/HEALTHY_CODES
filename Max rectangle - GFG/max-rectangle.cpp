//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    long long getMaxArea(long long h[], int n)
    {
        vector<long long>left(n);
        vector<long long>right(n);
        stack<long long>st;
        stack<long long>stk;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                left[i]=-1;
                st.push(i);
                continue;
            }
            while(!st.empty() && h[st.top()]>=h[i])
            {
                st.pop();
                
            }
            if(st.empty())
            {
                left[i]=-1;
            }
            else
            left[i]=st.top();
            st.push(i);
        }
        for(long long i=n-1;i>=0;i--)
        {
            if(stk.empty())
            {
                right[i]=n;
                stk.push(i);
                continue;
            }
            while(!stk.empty() && h[stk.top()]>=h[i])
            {
                stk.pop();
                
            }
            if(stk.empty())
            {
                right[i]=n;
            }
            else
            right[i]=stk.top();
            stk.push(i);
        }
        long long  ans=0;
        for(long long i=0;i<n;i++)
        {
            ans=max(ans,(right[i]-left[i]-1)*h[i]);        
            
        }
        return ans;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        long long h[m];
        for(int i=0;i<m;i++)
        h[i]=0;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]==1)
                h[j]++;
                else
                h[j]=0;
            }
            //long long area=getMaxArea(h,m);
            ans=max(ans,getMaxArea(h,m));
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends