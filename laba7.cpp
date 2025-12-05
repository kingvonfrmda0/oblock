#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    vector<int> arr;

    int choice;

    while (true) {
        cout << "\nМеню:\n";
        cout << "0. Выход\n";
        cout << "1. Просмотр массива\n";
        cout << "2. Добавить элемент в начало\n";
        cout << "3. Добавить элемент в конец\n";
        cout << "4. Очистить массив\n";
        cout << "5. Поиск элемента\n";
        cout << "6. Задание варианта\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {

        case 0:
            cout << "Выход...\n";
            return 0;

        case 1: {
            cout << "Массив: [";
            for (size_t i = 0; i < arr.size(); i++) {
                cout << arr[i];
                if (i + 1 < arr.size()) cout << " ";
            }
            cout << "]\n";
            break;
        }

        case 2: {
            int v;
            cout << "Введите число: ";
            cin >> v;
            arr.insert(arr.begin(), v);
            cout << "Добавлено.\n";
            break;
        }

        case 3: {
            int v;
            cout << "Введите число: ";
            cin >> v;
            arr.push_back(v);
            cout << "Добавлено.\n";
            break;
        }

        case 4: {
            arr.clear();
            cout << "Массив очищен.\n";
            break;
        }

        case 5: {
            int v;
            cout << "Введите число для поиска: ";
            cin >> v;

            cout << "Индексы: [";
            bool found = false;

            for (size_t i = 0; i < arr.size(); i++) {
                if (arr[i] == v) {
                    if (found) cout << ", ";
                    cout << i;
                    found = true;
                }
            }

            if (!found) cout << "нет";
            cout << "]\n";
            break;
        }

        case 6: {
            if (arr.empty()) {
                cout << "Массив пуст.\n";
                break;
            }

            int minValue = 0;
            bool hasNonZero = false;

            for (int x : arr) {
                if (x != 0) {
                    if (!hasNonZero || abs(x) < abs(minValue)) {
                        minValue = x;
                        hasNonZero = true;
                    }
                }
            }

            if (!hasNonZero) {
                cout << "Нет ненулевых элементов.\n";
                break;
            }

            cout << "Минимальное по модулю число: " << minValue << "\n";
            cout << "Добавляем " << abs(minValue) << " нулей...\n";

            for (int i = 0; i < abs(minValue); i++)
                arr.push_back(0);

            cout << "Готово.\n";
            break;
        }

        default:
            cout << "Неверный пункт меню!\n";
            break;
        }
    }

    return 0;
}
