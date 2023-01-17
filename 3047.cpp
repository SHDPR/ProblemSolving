#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> stk;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  int pos, speed;

  for(int ndx = 0; ndx < N; ndx++){
    cin >> pos >> speed;

    while(!stk.empty() && stk.top()> speed){
      stk.pop();
    }
    stk.push(speed);
  }

  cout << stk.size();
}
