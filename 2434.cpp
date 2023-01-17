#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

struct town{
  int pos;
  int fish;
};

int N, min_fish, max_fish;
town town_list[100000];


int main(){
  cin >> N;
  min_fish = 1000000000;
  max_fish = 0;
  int ans = 0;
  for(int ndx = 0; ndx < N; ndx++){
    cin >> town_list[ndx].pos >> town_list[ndx].fish;
    min_fish = (min_fish < town_list[ndx].fish)? min_fish : town_list[ndx].fish;
    max_fish = (max_fish > town_list[ndx].fish)? max_fish : town_list[ndx].fish;
  }

  while(min_fish <= max_fish){
    int mid_fish = (min_fish + max_fish) / 2;
    ll c = 0;
    for(int ndx = 0; ndx < N - 1; ndx++){
      long long remain = town_list[ndx].fish + c - mid_fish;
      c = remain - (town_list[ndx + 1].pos - town_list[ndx].pos);
      if(remain >= 0 && c < 0) c = 0;
    }

    if(town_list[N - 1].fish + c >= mid_fish){
      ans = mid_fish;
      min_fish = mid_fish + 1;
    }
    else
      max_fish = mid_fish - 1;
  }

  cout << ans;
}
