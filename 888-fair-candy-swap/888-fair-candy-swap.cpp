class Solution {
public:
    vector<int> fairCandySwap(vector<int>& alice, vector<int>& bob) {
        int an = alice.size();
        int bn = bob.size();
        
        int sumA = 0,sumB = 0;
        for(int i = 0; i < an; i++) sumA += alice[i];
        for(int i = 0; i < bn; i++) sumB += bob[i];
        
        sort(bob.begin(), bob.end());
        for(int i = 0; i < an; i++)
        {
            
            int A = alice[i];
            int l = 0, h = bn-1;
            
            while(l <= h)
            {
                int mid = l + (h-l)/2;
                int B = bob[mid];
                int afterA = sumA - A + B;
                int afterB = sumB - B + A;
                
                if(afterA == afterB)
                {
                    return {A,B};
                }
                else if(afterA > afterB)
                {
                    h = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
        return {};
    }
};