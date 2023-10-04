#include <iostream>
using namespace std;

void reverse(int arr[], int size)
{
    int start = 0, end = size - 1;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements you want in the array:" << endl;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << " element:" << endl;
        cin >> arr[i];
    }
    reverse(arr, n);
    printArray(arr, n);
    return 0;
}