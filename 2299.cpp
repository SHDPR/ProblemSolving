#include <iostream>
using namespace std;

#define MAX_N 100000
int N;
int conc[MAX_N];

int abs(int value){
  return (value > 0)? value : -value;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  for(int ndx = 0; ndx < N; ndx++)
    cin >> conc[ndx];

  int start = 0, end = N-1;
  int conc_sum = 2000000000;
  pair<int, int> answer;

  while(start != end){
    int temp_sum = conc[start] + conc[end];

    if(abs(temp_sum) < conc_sum){
      conc_sum = abs(temp_sum);
      answer = {start, end};
    }
    if(temp_sum < 0)
      start++;
    else
      end--;



  }
  cout << conc[answer.first] << " " << conc[answer.second];
  return 0;
}
