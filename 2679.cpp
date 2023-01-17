#include <iostream>
#include <deque>

using namespace std;

struct JOB{
    int prio;
    int no;
};

int N, M;
deque<JOB> printer_queue;
int cnt_prio[10];

void Init(void) {
    printer_queue.clear();
    for (int i = 1; i <= 9; i++) cnt_prio[i] = 0;
}

void Input_Data(void ) {
    cin >> N >> M;
    for (int i = 0; i < N;i++) {
        JOB  temp;
        temp.no = i;
        cin >> temp.prio;
        printer_queue.push_back(temp);
        cnt_prio[temp.prio]++;
    }
}

int Simulation(void) {
    int cnt_print = 0;
    JOB j;
    for (int prio = 9; prio >= 1;prio--) {
        for (int i = 0; i < cnt_prio[prio];i++) {
            for (;;) {
                j = printer_queue.front(); printer_queue.pop_front();
                if (j.prio == prio) break;
                printer_queue.push_back(j);
            }
            cnt_print++;
            if (j.no == M) return cnt_print;
        }
    }

    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T;t++) {
        Init();
        Input_Data();

        cout << Simulation() << '\n';
    }
    return 0;
}
