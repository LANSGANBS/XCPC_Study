#include <iostream>
using namespace std;

void straightInsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    int arr[] = {17, 3, 25, 14, 20, 9};
    int n = 6;

    straightInsertionSort(arr, n);

    cout << "straightInsertionSort:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}