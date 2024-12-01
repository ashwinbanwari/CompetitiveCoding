#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    long long sum = 0;
    while (cin >> s)
    {
        int first = -1;
        int last = -1;

        for (char c : s)
        {
            if (isdigit(c))
            {
                if (first == -1)
                {
                    first = c - '0';
                }
                last = c - '0';
            }
        }
        sum += first * 10 + last;
    }

    cout << sum << endl;

    return 0;
}