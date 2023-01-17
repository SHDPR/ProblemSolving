#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_M (100000)
#define MAX_N (100000)

struct xy{
  int x, y;
};

int N, M, L;
int shoot[MAX_M];
struct xy animl[MAX_N];

int main(){
  cin >> M >> N >> L;
  for(int mdx = 0; mdx < M; mdx++)
    cin >> shoot[mdx];

  for(int ndx = 0; ndx < N; ndx++)
    cin >> animl[ndx].x >> animl[ndx].y;

  sort(shoot, shoot + M);
  int count = 0;

  for(int ndx = 0; ndx < N; ndx++){
    int lower_x = animl[ndx].x - (L - animl[ndx].y);
    int upper_x = animl[ndx].x + (L - animl[ndx].y);

    if(lower_x > upper_x)
      continue;

    auto lower = lower_bound(shoot, shoot + M, lower_x);
    auto upper = upper_bound(shoot, shoot + M, upper_x);

    if(lower == shoot + M)
      continue;

    if(lower == upper)
      continue;

    count++;

  }
  cout << count << endl;
}
