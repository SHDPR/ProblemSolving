#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define MAX_N (80000)
int N;
int height[MAX_N];
stack<int> stk;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long count = 0;

    cin >> N;
    for(int ndx = 0; ndx < N; ndx++)
      cin >> height[ndx];

    for(int ndx = 0; ndx < N; ndx++){
      while(!stk.empty() && stk.top() <= height[ndx])
        stk.pop();

      count += stk.size();
      stk.push(height[ndx]);
    }

    cout << count;

    return 0;
}
