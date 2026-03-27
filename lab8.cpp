
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int weight[n], profit[n];

    for(int i = 0; i < n; i++) {
        cin >> weight[i] >> profit[i];
    }

    int capacity;
    cin >> capacity;

    double ratio[n];

    for(int i = 0; i < n; i++) {
        ratio[i] = (double)profit[i] / weight[i];
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(weight[i], weight[j]);
                swap(profit[i], profit[j]);
            }
        }
    }

    double total = 0;

    for(int i = 0; i < n; i++) {
        if(capacity >= weight[i]) {
            total += profit[i];
            capacity -= weight[i];
        }
        else {
            total += profit[i] * ((double)capacity / weight[i]);
            break;
        }
    }

    cout << total;

    return 0;
}
