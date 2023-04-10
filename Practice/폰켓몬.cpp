#include <vector>
#include <set>
using namespace std;
set <int> st;

int solution(vector<int> nums)
{
    int pos = nums.size() / 2;

    for (int i = 0; i < nums.size(); i++) {
        st.insert(nums[i]);
        if (st.size() >= pos) break;
    }

    return st.size();
}
