#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    vector <char> st;
    int len = s.size();

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') st.push_back('(');
        else {
            if (st.empty() || st.back() == ')') return false;
            else st.pop_back();
        }
    }

    return st.empty();
}