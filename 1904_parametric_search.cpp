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

  int start = budget[0];
  int end = budget[N-1];
  int ans, sum;

  while(start <= end){
    int mid = (start + end) / 2;
    sum = 0;
    for(int ndx = 0; ndx < N; ndx++)
      sum += min(budget[ndx], mid);

    if(sum <= budget_total){
      ans = mid;
      start = mid + 1;
    }
    else
      end = mid - 1;
  }
  cout << ans;
}
