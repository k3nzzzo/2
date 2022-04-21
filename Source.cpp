#include <iostream>

using namespace std;

void invert(int* arr, int n)
{
    int* inverted_array = new int[n];

    for (int i = n - 1; i >= 0;)
    {
        for (int j = 0; j < n;)
        {
            inverted_array[i] = arr[j];
            i--;
            j++;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\n" << inverted_array[i] << " ";
    }

    delete[]inverted_array;
}

void non_decrease(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n;)
        {
            if (arr[i] <= arr[j])
            {
                int c = 0;

                c = arr[i];
                arr[i] = arr[j];
                arr[j] = c;

                c = 0;

                j++;
            }

            else
            {
                j++;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        cout << "\n" << arr[i] << " ";
    }

    cout << "\n" << arr[0] << " ";
}

void non_increase(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n;)
        {
            if (arr[i] >= arr[j])
            {
                int c = 0;

                c = arr[i];
                arr[i] = arr[j];
                arr[j] = c;

                c = 0;

                j++;
            }

            else
            {
                j++;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        cout << "\n" << arr[i] << " ";
    }

    cout << "\n" << arr[0] << " ";
}

void function(int* arr, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if (sum < arr[0])
    {
        invert(arr, n);
    }
    else if (sum == arr[0])
    {
        non_decrease(arr, n);
    }
    else if (sum > arr[0])
    {
        non_increase(arr, n);
    }
}

int main()
{
    int n = rand() % 15 + 10;

    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 20;
    }

    void (*jj)(int*, int);

    jj = function;

    (*jj)(arr, n);

    delete[] arr;

    return 0;
}