#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX_N 50000
using namespace std;
typedef long long ll;

ll M;
int N, K;
bool flag[MAX_N];


struct el{
  ll price;
  ll coupon;
  int idx;
};
struct el sort_price[MAX_N];
struct el sort_coupon[MAX_N];
int p_ptr = 0;
int c_ptr = 0;

bool compare_price(struct el a, struct el b){
  if(a.price != b.price)
    return a.price < b.price;
  return a.coupon < b.coupon;
}

bool compare_coupon(struct el a, struct el b){
  if(a.coupon != b.coupon)
    return a.coupon < b.coupon;
  return a.price < b.price;
}

struct comp{
  bool operator()(struct el a, struct el b){
    return (a.price - a.coupon) > (b.price - b.coupon);
  }
};


int find_next_price(){
  struct el curr = sort_price[p_ptr];
  if(p_ptr >= N)
    return -1;

  if(flag[sort_price[p_ptr].idx] == true){
    p_ptr++;
    find_next_price();
  }
  return p_ptr;
}
int find_next_coupon(){
  struct el curr = sort_coupon[c_ptr];
  if(c_ptr >= N)
    return -1;

  if(flag[sort_coupon[c_ptr].idx] == true){
    c_ptr++;
    find_next_coupon();
  }
  return c_ptr;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> N >> K >> M;
  memset(flag, 0, sizeof(flag));

  for(int ndx = 0; ndx < N; ndx++){
    cin >> sort_price[ndx].price >> sort_price[ndx].coupon;
    sort_price[ndx].idx = ndx;
    sort_coupon[ndx] = sort_price[ndx];
  }
  sort(sort_price, sort_price + N, compare_price);
  sort(sort_coupon, sort_coupon + N, compare_coupon);

  ll ans = 0;

  priority_queue<el, vector<el>, comp> pq;

  int kdx;
  for(kdx = 1; kdx <= K; kdx++){
    pq.push(sort_coupon[c_ptr]);
    flag[sort_coupon[c_ptr].idx] = true;
    ans += sort_coupon[c_ptr++].coupon;
    if(ans > M){
      cout << kdx - 1 << endl;
      return 1;
    }
  }
  kdx = K;

  while(ans <= M){
    if(find_next_price() == -1 || find_next_coupon() == - 1){
      cout << N << endl;
      return 1;
    }
    ll next_price = sort_price[p_ptr].price;
    ll next_coupon = sort_coupon[c_ptr].coupon;

    ll price_sum = next_price + ans;
    ll coupon_sum = ans + (pq.top().price - pq.top().coupon) + next_coupon;

    if(price_sum <= coupon_sum){
      flag[sort_price[p_ptr].idx] = true;
      p_ptr++;
      ans = price_sum;
    }
    else{
      flag[sort_coupon[c_ptr].idx] = true;
      c_ptr++;
      ans = coupon_sum;
      pq.pop();
    }
    kdx++;
  }
  cout << kdx - 1;

}
