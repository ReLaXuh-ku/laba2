#include <iostream>
#include <ctime>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

int algoritm(int Arr[], int Value, int End, int Start)
{
    if (End >= Start)
    {
        int Mid = Start + (End - Start) / 2;
        if (Arr[Mid] == Value)
        {
            return Mid;
        }
        if (Arr[Mid] < Value)
        {
            return algoritm(Arr, Value, End, Mid + 1);
        }
        return algoritm(Arr, Value, Mid - 1, Start);
    }
    return -1;
}
void quicksort(int arr[], int  end, int begin)
{
    int mid;
    int f = begin;
    int l = end;
    mid = arr[(f + l) / 2];
    while (f < l)
    {
        while (arr[f] < mid) f++;
        while (arr[l] > mid) l--;
        if (f <= l)
        {
            swap(arr[f], arr[l]);
            f++;
            l--;
        }
    }
    if (begin < l)
    {
        quicksort(arr, l, begin);
    }
    if (f < end)
    {
        quicksort(arr, end, f);
    }
}
int main()
{
    setlocale(0, "");
    const int Length = 200;
    // Пункт первый
    cout << "Реализация пункта 1:" << endl;
    srand(time(0));
    int Arr1[Length];
    for (int i = 0; i < Length; ++i)
    {
        Arr1[i] = rand() % 199 - 99;
        //cin >> Arr1[i];
        cout << Arr1[i] << ' ';
    }
    int Arr2[Length], ArrForShake[Length], ArrForGnomik[Length], ArrForQuick[Length];
    for (int i = 0; i < Length; ++i)
    {
        Arr2[i] = Arr1[i];
    }
    for (int i = 0; i < Length; ++i)
    {
        ArrForShake[i] = Arr1[i];
    }
    for (int i = 0; i < Length; ++i)
    {
        ArrForGnomik[i] = Arr1[i];
    }
    for (int i = 0; i < Length; ++i)
    {
        ArrForQuick[i] = Arr1[i];
    }
    cout << endl;
    system("pause");
    // Пункт второй
    cout << "Реализация пункта 2:" << endl;
    cout << "Реализуем пузырьковую сортировку" << endl;
    bool State2 = true;
    auto start = steady_clock::now();
    while (State2)
    {
        State2 = false;
        for (int i = 0; i < Length-1; ++i)
        {
            if (Arr1[i] > Arr1[i + 1])
            {
                swap(Arr1[i], Arr1[i + 1]);
                State2 = true;
            }
        }
    }
    auto end = steady_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Пузырьковая сортировка заняла " << duration.count() << " микросекунд." << endl;
    for (int i = 0; i < Length; ++i)
    {
        cout << Arr1[i] << ' ';
    }
    cout << endl;
    cout << "Реализуем сортировку коктейлем" << endl;
    bool StateS = true;
    start = steady_clock::now();
    while (StateS)
    {
        StateS = false;
        for (int I = 0; I < Length - 1; ++I)
        {
            if (ArrForShake[I] > ArrForShake[I + 1])
            {
                swap(ArrForShake[I], ArrForShake[I + 1]);
                StateS = true;
            }
        }
        for (int I = Length-1; I > 1; --I)
        {
            if (ArrForShake[I] < ArrForShake[I - 1])
            {
                swap(ArrForShake[I], ArrForShake[I - 1]);
                StateS = true;
            }
        }
    }
    end = steady_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Сортировка коктейлем заняла " << duration.count() << " микросекунд." << endl;
    for (int I = 0; I < Length; I++)
    {
        cout << ArrForShake[I] << ' ';
    }
    cout << endl;
    cout << "Теперь реализуем сортировку гномиком" << endl;
    int I = 0;
    start = steady_clock::now();
    while (I < Length-1)
    {
        if (ArrForGnomik[I] > ArrForGnomik[I + 1])
        {
            swap(ArrForGnomik[I], ArrForGnomik[I + 1]);
            if (I != 0)
            {
                I = I - 1;
            }
        }
        else
        {
            ++I;
        }
    }
    end = steady_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Сортировка гномиком заняла " << duration.count() << " микросекунд." << endl;
    for (int I = 0; I < Length; I++)
    {
        cout << ArrForGnomik[I] << ' ';
    }
    cout << endl;
    cout << "Теперь реализуем быструю сортировку" << endl;
    start = steady_clock::now();
    quicksort(ArrForQuick, Length - 1, 0);
    end = steady_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Быстрая сортировка заняла " << duration.count() << " микросекунд." << endl;
    for (int I = 0; I < Length; ++I)
    {
        cout << ArrForQuick[I] << ' ';
    }
    cout << endl;
    system("pause");
    // Пункт 3
    cout << "Реализация пункта 3:" << endl;
    cout << "Находим минимальный и максимальный элементы в отсортрованном массиве: " << endl;
    start = steady_clock::now();
    cout << Arr1[0] << ' ' << Arr1[Length-1] << endl;
    end = steady_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Поиск занял " << duration.count() << " микросекунд." << endl;
    cout << "Теперь найдем минимальный и максимальный элементы для неотсортированного массива: " << endl;
    start = steady_clock::now();
    float min = 999, max = -999;
    float min1 = Arr1[0], max1 = Arr1[Length-1];
    for (int i = 0; i < Length; ++i)
    {
        if (Arr2[i] < min)
        {
            min = Arr2[i];
        }
    }
    for (int i = 0; i < Length; ++i)
    {
        if (Arr2[i] > max)
        {
            max = Arr2[i];
        }
    }
    cout << min << ' ' << max << endl;
    end = steady_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Поиск занял " << duration.count() <<  " микросекунд" << endl;
    system("pause");
    // Пункт 4
    cout << "Реализация пункта 4: " << endl;
    float MiddleOne;
    float MiddleTwo;
    cout << "Найдем среднее арифметическое для максимального и минимального элементов отсортированного массива: " << endl;
    MiddleOne = (min1 + max1) / 2;
    MiddleTwo = (min + max) / 2;
    if (int((MiddleOne - int(MiddleOne))*10) == 5 or int((MiddleOne - int(MiddleOne)) * 10) == -5)
    {
        if (int((MiddleOne - int(MiddleOne)) * 10) == 5)
        {
            MiddleOne = MiddleOne + 0.5;
            MiddleTwo = MiddleTwo + 0.5;
        }
        if (int((MiddleOne - int(MiddleOne)) * 10) == -5)
        {
            MiddleOne = MiddleOne - 0.5;
            MiddleTwo = MiddleTwo - 0.5;
        }

    }
    cout << MiddleOne << ' ' << MiddleTwo << endl;;
    cout << "Теперь найдем индексы всех элементов равных этому значению для обоих массивов и количество таких элементов(сначала отсортированный):" << endl;
    start = steady_clock::now();
    int Index1 = 0, Index2 = 0;
    for (int I = 0; I < Length; ++I)
    {
        if (MiddleOne == Arr1[I])
        {
            cout << I << ' ';
            Index1++;
        }
    }
    end = steady_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << endl;
    cout << "Количество в отсортированном массиве:" << endl;
    cout << Index1 << endl;
    cout << "На всю операцию ушло " << duration.count() << " микросекунд" << endl;
    cout << "Теперь проделаем то же самое для неотсортированного массива:" << endl;
    start = steady_clock::now();
    for (int I = 0; I < Length; ++I)
    {
        if (MiddleTwo == Arr2[I])
        {
            cout << I << ' ';
            Index2++;
        }
    }
    end = steady_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << endl;
    cout << "На всю операцию ушло " << duration.count() << " микросекунд" << endl;
    cout << endl;
    cout << "Количество в неотсортированном массиве:" << endl;
    cout << Index2 << endl;
    system("pause");
    // Пункт 5
    cout << "Реализация пункта 5:" << endl;
    cout << "Введите число, которое будет сравниваться с элементами массива:" << endl;
    int NumberForOperation;
    cin >> NumberForOperation;
    int Amount = 0;
    for (int I = 0; I < Length; ++I)
    {
        if (NumberForOperation > Arr1[I])
        {
            Amount++;
        }
        else
        {
            break;
        }
    }
    cout << "Количество элементов в массиве меньших введеного Вами числа равно: " << Amount << endl;
    system("pause");
    // Пункт 6
    cout << "Реализация пункта 6:" << endl;
    cout << "Введите число, которое будет сравниваться с элементами массива:" << endl;
    int NumberForOperation2;
    cin >> NumberForOperation2;
    int Amount2 = 0;
    for (int I = Length-1; I > 0; --I)
    {
        if (NumberForOperation2 < Arr1[I])
        {
            Amount2++;
        }
        else
        {
            break;
        }
    }
    cout << "Количество элементов больших введенного Вами числа равно: " << Amount2 << endl;
    system("pause");
    // Пункт 7
    cout << "Реализация пункта 7:" << endl;
    cout << "Введите число, которое Вы хотите попробовать найти в массиве:" << endl;
    int NumberForSearch;
    cin >> NumberForSearch;
    cout << "Теперь поищем это число с помощью обычного перебора:" << endl;
    start = steady_clock::now();
    bool Flag = false;
    for (int I = 0; I < Length; ++I)
    {
        if (NumberForSearch == Arr1[I])
        {
            cout << "Такое число есть и оно находится на " << I << " позиции в массиве" << endl;
            Flag = true;
            break;
        }
    }
    if (Flag == false)
    {
        cout << "Такого числа нет в массиве" << endl;
    }
    end = steady_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "На поиск обычным перебором ушло " << duration.count() << " микросекунд" << endl;
    cout << "Теперь же реализуем алгоритм бинарного поиска:" << endl;
    start = steady_clock::now();
    int Start = 0;
    int End = sizeof(Arr1) / sizeof(Arr1[0]);
    int Result = algoritm(Arr1, NumberForSearch, End, Start);
    if (Result != -1)
    {
        cout << "Такое число есть и оно находится на " << Result << " позиции в массиве" << endl;
    }
    else
    {
        cout << "Такого числа нет в массиве" << endl;;
    }
    end = steady_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "На поиск с помощью бинарного поиска ушло " << duration.count() << " микросекунд" << endl;
    system("pause");
    // Пункт 8
    cout << "Реализация пункта 8:" << endl;
    cout << "Введите индексы элементов, которые хотите поменять местами(от 0 до " << Length - 1 << ")" << endl;
    int Ind1, Ind2;
    cin >> Ind1;
    cin >> Ind2;
    cout << endl;
    cout << "На примере будем использовать неотсортированный массив" << endl;
    for (int I = 0; I < Length; ++I)
    {
        cout << Arr2[I] << ' ';
    }
    cout << endl;
    cout << "Теперь же поменяем местами выбранные Вами элементы:" << endl;
    start = steady_clock::now();
    swap(Arr2[Ind1], Arr2[Ind2]);
    end = steady_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "На замену ушло " << duration.count() << " микросекунд" << endl;
    for (int I = 0; I < Length; ++I)
    {
        cout << Arr2[I] << ' ';
    }
    cout << endl;
    return 0;
}
