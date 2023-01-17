#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int N, budget_total;
  int budget[100000];

  cin >> N;
  for(int ndx = 0; ndx < N; ndx++)
    cin >> budget[ndx];
  cin >> budget_total;

  sort(budget, budget + N);
  bool flag = false;

  for(int ndx = 0; ndx < N; ndx++){
    int curr = budget[ndx];
    if(curr * (N - ndx) > budget_total){
      cout << (budget_total) / (N - ndx) << endl;
      flag = true;
      break;
    }
    budget_total -= curr;
  }
  if(!flag)
    cout << budget[N-1] << endl;
}
