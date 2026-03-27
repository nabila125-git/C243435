#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int start[n], finish[n];

    for(int i = 0; i < n; i++) {
        cin >> start[i] >> finish[i];
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(finish[i] > finish[j]) {
                swap(finish[i], finish[j]);
                swap(start[i], start[j]);
            }
        }
    }

    int i = 0;
    cout << start[i] << " " << finish[i] << endl;

    for(int j = 1; j < n; j++) {
        if(start[j] >= finish[i]) {
            cout << start[j] << " " << finish[j] << endl;
            i = j;
        }
    }

    return 0;
}
