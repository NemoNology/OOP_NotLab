#include <iostream>
#include <exception>


using namespace std;

namespace Arrays {

	// Не смог вновь использовать M_PI, т.к. не нашёл его
	const double PI = 3.141592653589793;


	// Расчёт а
	float Calc_a(float x, float y) {
		float a;
		return a = (2 * cos(x - (PI / 6))) / (0.5 + pow(sin(y), 2));
	}

	// Расчёт b  
	float Calc_b(float z) {
		float b;
		return b = 1 + (pow(z, 2)) / (3 + (pow(z, 2) / 5));
	}


	// Создание случайного одномерного массива (int)
	void Cr_rand_1darr(int* arr, unsigned& n) {
		for (unsigned i = 0; i < n; i++) {
			arr[i] = rand() % 200 - 100;
		}
	}
	
	// Суммирование массива
	unsigned Sum_1darr(int* arr, unsigned& n) {
		unsigned sum = 0;
		for (unsigned i = 0; i < n; i++) {
			sum += pow(arr[i], 2);
		}
		return sum;
	}

	// Вывод массива
	void Cout_1darr(int* arr, unsigned& n) {
		for (unsigned i = 0; i < n; i++) {
			cout << arr[i] << "; ";
		}
		cout << endl;
	}
}


using namespace Arrays;

int main()
{
	setlocale(LC_ALL, "Russian");
	float x, y, z;

	unsigned n = 10, restart; unsigned* np = &n;


	// Массив - 2-ое задание 
	// ################################################

	int* arr = new int[n];
	float vi;
	Cr_rand_1darr(arr, n);
	Cout_1darr(arr, n);
	cout << Sum_1darr(arr, n) << endl;

	// ################################################

	// Вычисление по 1-ому заданию
	do {
		cout << endl; // (НОД)
		cout << endl;
		cout << "Введите x, y, z поочерёдно, через Enter:\n";
		bool exp;
		do {
			cin >> x >> y >> z;
			if (!cin) {
				exp = true;
			}
			else {
				cout << "Введите корректные значения\n";
				exp = false;
			}
		} while (exp == true);
		cout << "a = " << Calc_a(x, y);
		cout << "\nb = " << Calc_b(z);
		cout << "\nХотите изменить значения? (1 - да; 0 - нет)\n" << endl;
		cin >> restart;
	} while (restart != 1); // Множественное воспроизведение счёта

	
	cout << "\n\n### Если Вы ввели некорректные значения для x, y или z, программа моментально завершится ###" << endl;
	cout << "### Попытайтесь вновь, если Вам нужны результаты этой программы ###\n\n" << endl;
	system("pause");
	return 0;
}