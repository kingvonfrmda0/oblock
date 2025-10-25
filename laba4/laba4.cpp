#include <iostream>

int main() {

	setlocale(LC_ALL, "Russian");
	// 1
	int x[7]; // массив из 7 элементов
	int k = 0; // счетчик четных чисел
	std::cout << "Введите 7 чисел массива: " << std::endl;
	for (int i = 0;i < 7;++i) {
		std::cin >> x[i];
		if (x[i] % 5 == 0) {
			k += 1;
		}
	}


	if (k == 7) { // если соблюдается условие(все числа четные)
		for (int i = 0;i < 6;++i) {
			for (int j = i + 1;j < 7;++j) {
				if (x[i] > x[j]) {
					std::swap(x[i], x[j]);
				}

			}
		}
	}
	std::cout << "Массив: " << std::endl;
	for (int i = 0;i < 7;++i) {
		std::cout << x[i] << std::endl;
	}
	
	// 2
	int matr[3][4];
	std::cout << "Введите значения элементов матрицы 3x4: " << std::endl;
	for (int i = 0;i < 3;++i) {
		for (int j = 0;j < 4;++j) {
			std::cin >> matr[i][j];
		}
	}
	// ищу столбец с наибольшим количеством отрицательных чисел
	int maxO = 0; // количество отр чисел
	int maxS = 0; // столбец


	for (int j = 0; j < 4; ++j) {
		int countNeg = 0;
		for (int i = 0; i < 3; ++i) {
			if (matr[i][j] < 0) {
				countNeg++;
			}
		}
		if (countNeg > maxO) {
			maxO = countNeg;
			maxS = j;  // первый столбец с максимумом
		}
	}

	// заменяю все значения в найденном столбце на -1
	if (maxO > 0) {
		for (int i = 0; i < 3; ++i) {
			matr[i][maxS] = -1;
		}
	}

	std::cout << "Результат матрицы: " << std::endl;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			std::cout << matr[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	return 0;
}
