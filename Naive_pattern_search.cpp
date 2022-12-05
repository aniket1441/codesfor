#include <bits/stdc++.h>
using namespace std;
 
void NaiveSearchPattern(string txt, string pat)
{
    int n = txt.size();
    int m = pat.size();
 
    for(int i = 0; i <= n-m; i++){
        
        int j;

        for(j = 0; j < m; j++)
            if(txt[i + j] != pat[j])
                break;
 
        if(j == m) 
            cout << "Pattern found at index " << i << endl;
    }
}
 
int main()
{
    
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    string str,pat;
    cin >> str >> pat;

    NaiveSearchPattern(str,pat);
}