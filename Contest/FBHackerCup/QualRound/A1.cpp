#include <bits/stdc++.h>

using namespace std;

const unordered_set<char> vowels {'A', 'E', 'I', 'O', 'U'};

bool vowel (char c) {
    return vowels.count(c);
}

int solve(const string& s, char c) {
    int cost = 0;
    bool isVowel = vowel(c);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            continue;
        } else if(vowel(s[i]) == isVowel) {
            cost += 2;
        } else {
            cost++;
        }
    }
    return cost;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ifstream in;
    in.open("inA1.txt", ios::in);
    ofstream out;
    out.open("outA1.txt", ios::trunc);
    int T;
    in >> T;
    vector<string> strs(T);
    for (int i = 0; i < T; i++) {
        in >> strs[i];
    }

    for (int i = 1; i <= T; i++) {
        string curr = strs[i-1];
        unordered_map<char, int> vowelLens;
        unordered_map<char, int> consonantLens;
        for (const char& c : curr) {
            if (vowel(c)) {
                vowelLens[c]++;
            } else {
                consonantLens[c]++;
            }
        }
        char consonant = 'B';
        int maxConsonantLen = 0;
        char vowel = 'A';
        int maxVowelLen = 0;
        for (const auto& p : vowelLens) {
            if (p.second > maxVowelLen) {
                maxVowelLen = p.second;
                vowel = p.first;
            }
        }
        for (const auto& p : consonantLens) {
            if (p.second > maxConsonantLen) {
                maxConsonantLen = p.second;
                consonant = p.first;
            }
        }
        int res1 = solve(curr, consonant);
        int res2 = solve(curr, vowel);
        int res = min(res1, res2);
        out << "Case #" << i << ": " << res << endl;
    }


    return 0;
}