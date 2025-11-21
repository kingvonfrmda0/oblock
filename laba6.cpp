#include <iostream>
#include <cstdlib>
#include <locale.h>


// Функция ищет строки, содержащие хотя бы один 0
int* findZeroRows(int** arr, int rows, int cols, int& countZero)
{
    countZero = 0;

    // Считаю сколько строк содержат хотя бы один 0
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == 0)
            {
                countZero++;
                break;
            }
        }
    }

    // Если нулевых строк нет — создаю безопасный массив
    if (countZero == 0)
    {
        int* zeroRows = (int*)malloc(sizeof(int));
        zeroRows[0] = -1;   // метка «нет строк»
        return zeroRows;
    }

    // Иначе создаю массив индексов строк
    int* zeroRows = (int*)malloc(countZero * sizeof(int));

    int pos = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == 0)
            {
                zeroRows[pos++] = i;
                break;
            }
        }
    }

    return zeroRows;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int A, B, C, D;


    do {
        std::cout << "Введите A (строки сверху): ";
        std::cin >> A;
        if (A < 0) std::cout << "Ошибка! A не может быть отрицательным.\n";
    } while (A < 0);

 
    do {
        std::cout << "Введите B (столбцы слева): ";
        std::cin >> B;
        if (B < 0) std::cout << "Ошибка! B не может быть отрицательным.\n";
    } while (B < 0);

 
    std::cout << "Введите C (коэффициент C): ";
    std::cin >> C;
    std::cout << "Введите D (коэффициент D): ";
    std::cin >> D;

    int rows = 2 + A;
    int cols = 2 + B;

  

    int** arr = (int**)malloc(rows * sizeof(int*));

   
    for (int i = 0; i < rows; i++)
        arr[i] = NULL;

    for (int i = 0; i < rows; i++)
        arr[i] = (int*)malloc(cols * sizeof(int));

    // Заполняю по формуле
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[i][j] = i * C + j * D;

    // Вывод матрицы
    std::cout << "\nИсходная матрица:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            std::cout << arr[i][j] << "\t";
        std::cout << std::endl;
    }

    // Ищу строки с нулем

    int countZero = 0;
    int* zeroRows = findZeroRows(arr, rows, cols, countZero);

    if (zeroRows[0] == -1)
    {
        std::cout << "\nСтрок с нулевыми элементами не найдено.\n";
    }
    else
    {
        // Удаляю строки
        for (int i = 0; i < countZero; i++)
        {
            int r = zeroRows[i];
            free(arr[r]);
            arr[r] = NULL;
        }

        // Вывожу матрицу после удаления
        std::cout << "\nМатрица после удаления строк:\n";
        for (int i = 0; i < rows; i++)
        {
            if (arr[i] == NULL) continue;

            for (int j = 0; j < cols; j++)
                std::cout << arr[i][j] << "\t";
            std::cout << std::endl;
        }
    }

    // Очищаю память

    for (int i = 0; i < rows; i++)
        if (arr[i] != NULL)
            free(arr[i]);

    free(arr);
    free(zeroRows);

    // Пункт 2

    std::cout << "\n=== Пункт 2 ===\n";

    int a, b;
    std::cout << "Введите два целых числа a и b: ";
    std::cin >> a >> b;

    int* pa = &a;     // указатель на a
    int* pb = &b;     // указатель на b

    *pa = *pa * 2;    

    int* temp = new int;   
    *temp = *pa;           

    *pa = *pb;             
    *pb = *temp;

    delete temp;           

    std::cout << "После обработки:\n";
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    return 0;
}
