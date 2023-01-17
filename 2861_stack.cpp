#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
#define N_MAX (100000)

struct el{
  int x, y;
};

int N;
int height[N_MAX];
stack<el> stk;

int input_handler(){
  cin >> N;
  if(N == 0)
    return 0;
  for(int ndx = 0; ndx < N; ndx++)
    cin >> height[ndx];
  return 1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while(input_handler()){
    ll max_area = 0;
    for(int ndx = 0; ndx < N; ndx++){
      struct el curr = {ndx, height[ndx]};
      while(!stk.empty() && stk.top().y > curr.y){
        struct el prev = stk.top();
        ll temp = (ll)(prev.y) * (ll)(ndx - prev.x);
        max_area = (max_area > temp)? max_area : temp;
        curr.x = prev.x;
        stk.pop();
      }
      stk.push(curr);
    }
    while(!stk.empty()){
      struct el prev = stk.top();
      ll temp = (ll)(prev.y) * (ll)(N - prev.x);
      max_area = (max_area > temp)? max_area : temp;
      stk.pop();
    }
    cout << max_area << endl;
  }
}
