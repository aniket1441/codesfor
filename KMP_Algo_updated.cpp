#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string ptr) {
    int m = ptr.size();
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        int j = pi[i - 1];
        while (j > 0 && ptr[i] != ptr[j]) {
            j = pi[j - 1];
        }
        if (ptr[i] == ptr[j]) j++;

        ptr[i] = j;
    }
    // time complexity  O(m)
    return pi;
}

void KMPStringSearch(string txt, string ptr) {
    int M = ptr.size();
    int N = txt.size();

    vector<int> pi = prefix_function(ptr);

    int i = 0;
    int j = 0;
    while (i < N) {
        if (txt[i] == ptr[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = pi[j - 1];
            } else {
                i++;
            }
        }
        if (j == M) {
            cout << "Pattern found with shift " << i - M << "\n";
            j = pi[j - 1];
        }
    }
}

int main() {
    string text;
    cin >> text;
    string pattern;
    cin >> pattern;
    KMPStringSearch(text, pattern);

    return 0;
}
