//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++
#define ll long long
#define all(x) x.begin(),x.end()
class Solution 
{
    public:
    bool predicate_function(vector<ll> v, ll limit, ll m)
    {
    ll segments = 1;
    ll sum = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        sum += v[i];
        if (sum > limit)
        {
            segments++;
            sum = v[i];
        }
    }
    if (sum > limit)
        return false;
    return segments <= m;
    }
    int findPages(int A[], int N, int M) 
    {
        vector<ll> v(A,A+N);
       ll n=N,m=M;
       if(m>n)return -1;
          ll start = *max_element(v.begin(), v.end());
    ll end = accumulate(v.begin(), v.end(), 0LL);
    ll answer = end;
    while (start <= end)
    {
        ll mid = (start + end) / 2;
        // cout << mid;
        if (predicate_function(v, mid, m))
        {
            answer = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
            return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends