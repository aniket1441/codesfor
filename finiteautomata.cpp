#include <bits/stdc++.h>
using namespace std;

int NUM_OF_CHARS = 256;

vector<vector<int>> computeTF(string ptr) {
    int m = ptr.size();
    vector<vector<int>> TFtable(m + 1, vector<int>(NUM_OF_CHARS));

    for (int i = 0; i < NUM_OF_CHARS; i++) TFtable[0][i] = 0;
    TFtable[0][ptr[0]] = 1;

    int lps = 0;
    for (int i = 1; i <= m; i++) {
        for (int x = 0; x < NUM_OF_CHARS; x++) TFtable[i][x] = TFtable[lps][x];

        TFtable[i][ptr[i]] = i + 1;
        if (lps < m) lps = TFtable[lps][ptr[i]];
    }
    return TFtable;
}

void finiteAutomataStringMatcher(string txt, string ptr) {
    int n = txt.size();
    int m = ptr.size();
    vector<vector<int>> TF = computeTF(ptr);
    int j = 0;
    for (int i = 0; i < n; i++) {
        j = TF[j][txt[i]];
        if (j == m) {
            cout << "Pattern found with shift " << i - m + 1 << "\n";
        }
    }
}

int main() {
    string txt, ptr;
    cin >> txt >> ptr;

    finiteAutomataStringMatcher(txt, ptr);

    return 0;
}
