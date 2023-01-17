#include <iostream>
#include <algorithm>
#define MAX_M (100000)
using namespace std;
typedef long long ll;

struct interval{
  ll start, end;
};

bool compare(struct interval a, struct interval b){
  return a.start < b.start;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, M;
  struct interval grass[MAX_M];

  cin >> N >> M;
  for(int mdx = 0; mdx < M; mdx++)
    cin >> grass[mdx].start >> grass[mdx].end;

  sort(grass, grass + M, compare);

  ll low = 0;
  ll high = grass[M - 1].end / (ll)(N - 1);
  ll ans = 0;

  while(low <= high){
    ll mid = (low + high) / 2;

    int count = 1;
    int idx = 0;
    ll cow_pos = grass[idx].start;
    while(idx < M && count < N){
      if(cow_pos + mid <= grass[idx].end){
        count++;
        if(cow_pos + mid >= grass[idx].start)
          cow_pos += mid;
        else
          cow_pos = grass[idx].start;
      }
      else
        idx++;
    }

    if(count == N){
      ans = mid;
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
  cout << ans;
}
