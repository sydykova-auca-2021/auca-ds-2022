#include <bits/stdc++.h> 
 
template <typename C> 
int sz(const C &c) { return static_cast<int>(c.size()); } 
 
using namespace std; 
 
int main() 
{ 
    iostream::sync_with_stdio(false); 
    int n; 
    cin >> n; 
    for (int testCase = 1; testCase <= n; testCase++) 
    { 
        vector<string> webSite(10); 
        vector<int> relevance(10); 
        int maxRev = 0; 
        cout << "Case #" << testCase << ":\n"; 
        
        for (int i = 0; i < 10; i++) 
        { 
            cin >> webSite[i] >> relevance[i]; 
            maxRev = max(maxRev, relevance[i]); 
        } 

        for (int i = 0; i < 10; i++) 
        { 
            if (maxRev == relevance[i]) 
            { 
                cout << webSite[i] << "\n"; 
            } 
        } 
    } 
}