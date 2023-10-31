#include <iostream>
#include <cstdlib> // Додайте цю бібліотеку для використання функції rand()

using namespace std;

void AddArray(int* a, const int n, int A, int B)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = A + rand() % (B - A + 1);
    }
}

void Print(int* a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "     ";
        if (i == n - 1)
        {
            cout << "   " << endl;
        }
    }
}

int Count(const int* a, const int n, int A, int B)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (i >= A && i <= B)
        {
            count++;
        }
    }

    return count;
}

int Find_Max(int* a, const int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

int Sum(int* a, const int n)
{
    int maxIndex = Find_Max(a, n);
    int sum = 0;

    for (int i = maxIndex; i < n; i++)
    {
        sum += a[i];
    }

    return sum;
}

void Arrangement(int* a, const int n)
{
    // Сортування парних елементів за спаданням модулів
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] % 2 == 0 && abs(a[j]) > abs(a[i]))
                {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
}

int main()
{
    int A;
    int B;
    int n;

    cout << "A = ";
    cin >> A;
    cout << "B = ";
    cin >> B;
    cout << "n = ";
    cin >> n;

    int* a = new int[n];

    AddArray(a, n, A, B);

    cout << "Array = ";
    cout << "    ";
    Print(a, n);

    int countInRange = Count(a, n, A, B);

    cout << "[" << A << ", " << B << "] = " << countInRange << "    " << "elements" << endl;

    Arrangement(a, n);

    cout << "Array after arrangement: ";
    cout << "    ";
    Print(a, n);

    int Max = Find_Max(a, n);
    cout << "Max element: " << Max << endl;

    cout << "Sum = " << Sum(a, n) << endl;

    delete[] a; // Звільнення виділеної пам'яті

    return 0;
}
