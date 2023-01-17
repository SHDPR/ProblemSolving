#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N (1000)

int N;
int frog[MAX_N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  /* input */
  cin >> N;
  for(int ndx = 0; ndx < N; ndx++)
    cin >> frog[ndx];

  sort(frog, frog + N);
  int cnt = 0;

  for(int idx = 0; idx < N - 2; idx++){
    for(int jdx = idx + 1; jdx < N - 1; jdx++){
      int dist = frog[jdx] - frog[idx];
      int lower = frog[jdx] + dist;
      int upper = frog[jdx] + 2 * dist;
      auto lower_iter = lower_bound(frog + jdx + 1, frog + N, lower);
      auto upper_iter = upper_bound(frog + jdx + 1, frog + N, upper);

      if(lower_iter < upper_iter)
        cnt += (upper_iter - lower_iter);
    }
  }

  cout << cnt;
}
