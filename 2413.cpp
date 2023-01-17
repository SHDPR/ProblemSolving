#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 100000

int N;
int acorn[MAX_N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  for(int adx = 0; adx < N; adx++)
    cin >> acorn[adx];

  int sum_smart = 0;
  int sum_fool = -10000;
  int sum_temp = 0;
  for(int adx = 0; adx < N; adx++){
    if(acorn[adx] > 0)
      sum_smart += acorn[adx];
    sum_temp += acorn[adx];
    if(sum_temp > sum_fool)
      sum_fool = sum_temp;
    if(sum_temp < 0)
      sum_temp = 0;
  }

  if(sum_smart == 0)
    sum_smart  = sum_fool;

  cout << sum_fool << " " << sum_smart << '\n';
  return 0;
}
