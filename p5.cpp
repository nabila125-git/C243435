
#include <iostream>
using namespace std;

void quickSort(int a[], int left, int right)
{
    int i = left;
    int j = right;
    int pivot = a[left];

    while(i <= j)
    {
        while(a[i] < pivot)
            i++;

        while(a[j] > pivot)
            j--;

        if(i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            i++;
            j--;
        }
    }

    if(left < j)
        quickSort(a, left, j);

    if(i < right)
        quickSort(a, i, right);
}

int main()
{
    int n;
    cin >> n;

    int a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    quickSort(a, 0, n-1);

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}
