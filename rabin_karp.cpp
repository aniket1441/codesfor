#include <bits/stdc++.h>
using namespace std;
 
// d is the number of characters in the input alphabet
#define d 256
 
// mod is a prime number used for modulo arithmetic 
#define mod INT_MAX

void RabinKarpSearchPattern(string txt, string pat)
{
    int n = txt.size();
    int m = pat.size();

    int hashp = 0; // hash value for pattern
    int hasht = 0; // hash value for txt
    
    int h = 1;

    // h = d^(m-1)
    for(int i = 0; i < m - 1; i++)
        h = (h * d) % mod;
 
    for(int i = 0; i < m; i++){
        hashp = (d * hashp + pat[i]) % mod;
        hasht = (d * hasht + txt[i]) % mod;
    }
 
    // Slide the pattern over text one by one
    for(int i = 0; i <= n-m; i++){
 
        if(hashp == hasht){

            int j;

            for(j = 0; j < m; j++){
                if(txt[i + j] != pat[j]){
                    break;
                }
            }
 
            if(j == m)
                cout << "Pattern found at index " << i << endl;
        }
 
        // Calculate hash value for next window of text:
        if(i < n - m){
            hasht = (d*(hasht - txt[i]*h) + txt[i+m]) % mod;
 
            if(hasht < 0)
                hasht = (hasht + mod);
        }
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

    RabinKarpSearchPattern(str,pat);
}