#include <iostream>
#include <queue>

using namespace std;



class RecentCounter {
    public:
        RecentCounter() {}

        int ping(int t) {
            q.push(t);
            while (q.front() < t - 3000) q.pop();
            return q.size();
        }
    private:
        queue<int> q;
};

int main () {

    RecentCounter R;

    cout << "val: " << R.ping(1) << endl;
    cout << "val: " << R.ping(100) << endl;
    cout << "val: " << R.ping(3001) << endl;
    cout << "val: " << R.ping(3002) << endl;

    return 0;
}
