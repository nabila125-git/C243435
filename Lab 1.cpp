#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    bool found = false;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            cout << "Found at index: " << i << endl;
            found = true;
            break;
        }
    }

    if(found == false)
    {
        cout << "Not Found" << endl;
    }

    return 0;
}
