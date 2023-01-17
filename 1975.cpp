#include <iostream>
#include <cstring>
using namespace std;
#define N_MAX 3000000
#define D_MAX 3000

int plate_cnt, sushi_cnt, K, coupon;
int sushi[N_MAX + D_MAX];
int schk[D_MAX + 1];

void input_handler(void){
  cin >> plate_cnt >> sushi_cnt >> K >> coupon;
  for(int sdx = 0; sdx < plate_cnt; sdx++)
    cin >> sushi[sdx];
  for(int sdx = 0; sdx < K; sdx++)
    sushi[plate_cnt + sdx] = sushi[sdx];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
  input_handler();

  int temp_cnt = 1, max_cnt = 0;
  memset(schk, 0, sizeof(schk));
  schk[coupon] = 1;


  for(int kdx = 0; kdx < K; kdx++){
    int curr_sushi = sushi[kdx];
    if(schk[curr_sushi] == 0)
      temp_cnt += 1;
    schk[curr_sushi] += 1;
  }

  max_cnt = temp_cnt;

  for(int sdx = 1; sdx < plate_cnt; sdx++){
    int prev = sdx - 1;
    int next = K - 1 + sdx;

    if(schk[sushi[prev]] == 1)
      temp_cnt -= 1;
    if(schk[sushi[next]] == 0)
      temp_cnt += 1;

    schk[sushi[prev]] -= 1;
    schk[sushi[next]] += 1;

    max_cnt = (max_cnt < temp_cnt)? temp_cnt : max_cnt;
  }

  cout << max_cnt << endl;
	return 0;
}
