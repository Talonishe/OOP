#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <limits>
#define NOMINMAX // Вимикає макроси min та max з Windows.h
#include <Windows.h>

using namespace std;

void task1() {
	FILE* f;
	fopen_s(&f, "t1.txt", "w");
	if (!f) {
		cout << "Помилка відкриття файлу\n";
		return;
	}

	cout << "Вводьте символи до '#':\n";
	char ch = getchar();
	while (ch != '#') {
		fputc(ch, f);
		ch = getchar();
	}
	fclose(f);

	fopen_s(&f, "t1.txt", "r");
	if (!f) {
		cout << "Помилка відкриття файлу\n";
		return;
	}

	cout << "Вміст файлу:\n";
	ch = fgetc(f);
	while (!feof(f)) {
		putchar(ch);
		ch = fgetc(f);
	}
	fclose(f);
	cout << endl;
}

void task2() {
	FILE* f;
	int n;
	cout << "Введіть кількість рядків -> ";
	cin >> n;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	fopen_s(&f, "t1.txt", "w");
	if (!f) {
		cout << "Помилка відкриття файлу\n";
		return;
	}

	char s[100];
	cout << "Вводьте рядки:\n";
	for (int i = 0; i < n; i++) {
		cin.getline(s, 100);
		fputs(s, f);
		fputs("\n", f);
	}
	fclose(f);

	fopen_s(&f, "t1.txt", "r");
	if (!f) {
		cout << "Помилка відкриття файлу\n";
		return;
	}

	cout << "Читання з файлу:\n";
	for (int i = 0; i < n; i++) {
		fgets(s, 100, f);
		cout << s;
	}
	fclose(f);
}

void task3() {
	FILE* f1;
	FILE* f2;
	int x;
	int k = 0, sum = 0;

	fopen_s(&f1, "t1.txt", "w");
	if (!f1) {
		cout << "Error\n";
		return;
	}

	for (int i = 0; i < 20; i++) {
		x = rand() % 10;
		fprintf(f1, "%2d ", x);
		k++;
	}
	fclose(f1);

	fopen_s(&f1, "t1.txt", "r");
	fopen_s(&f2, "t2.txt", "w");
	for (int i = 0; i < k; i++) {
		fscanf_s(f1, "%d", &x);
		fprintf(f2, "%2d ", x);
		sum += x;
	}
	fclose(f1);
	fclose(f2);

	fopen_s(&f2, "t2.txt", "r");
	cout << "Числа з другого файлу: ";
	for (int i = 0; i < k; i++) {
		fscanf_s(f2, "%d", &x);
		cout << x << " ";
	}
	fclose(f2);

	cout << "\nСума всіх чисел: " << sum;
	cout << "\nКількість всіх чисел: " << k;
	cout << "\nСереднє арифметичне: " << (double)sum / k << endl;
}

void task4() {
	FILE* f;
	char name[20];
	cout << "Введіть ім'я файлу -> ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.getline(name, 20);

	fopen_s(&f, name, "wb");
	if (!f) {
		cout << "Помилка відкриття файлу\n";
		return;
	}

	int x;
	for (int i = 0; i < 10; i++) {
		x = rand() % 20;
		fwrite(&x, sizeof(int), 1, f);
	}
	fclose(f);

	fopen_s(&f, name, "rb");
	if (!f) {
		cout << "Помилка відкриття файлу\n";
		return;
	}

	int max = -1;
	cout << "Читання чисел з файлу: ";
	for (int i = 0; i < 10; i++) {
		fread(&x, sizeof(int), 1, f);
		cout << x << " ";
		if (x > max) max = x;
	}
	fclose(f);

	cout << "\nМаксимальне число: " << max << endl;
}

void task5() {
	FILE* f;
	fopen_s(&f, "t1.dat", "wb");
	if (!f) {
		cout << "Помилка відкриття файлу\n";
		return;
	}

	int mas[5] = { 0, 1, 2, 3, 4 };
	fwrite(mas, sizeof(int), 5, f);
	fclose(f);

	fopen_s(&f, "t1.dat", "rb");
	if (!f) {
		cout << "Помилка відкриття файлу\n";
		return;
	}

	int mas2[5];
	cout << "Масив після читання: ";
	for (int i = 0; i < 5; i++) {
		fread(&mas2[i], sizeof(int), 1, f);
		cout << mas2[i] << " ";
	}
	fclose(f);
	cout << endl;
}

void task6() {
	FILE* f;
	fopen_s(&f, "t1.dat", "wb");
	if (!f) {
		cout << "Помилка відкриття файлу\n";
		return;
	}

	int mas[11] = { 0,11,22,33,44,55,66,77,88,99,100 };
	fwrite(mas, sizeof(int), 11, f);
	fclose(f);

	fopen_s(&f, "t1.dat", "rb");
	if (!f) {
		cout << "Помилка відкриття файлу\n";
		return;
	}

	int x;
	fseek(f, 5 * sizeof(int), SEEK_SET);
	fread(&x, sizeof(int), 1, f);
	cout << "П'ятий елемент з файлу: " << x << endl;
	fclose(f);
}

void task7() {
	FILE* f;
	fopen_s(&f, "t1.dat", "wb");
	if (!f) {
		cout << "Помилка відкриття файлу\n";
		return;
	}

	cout << "Масив для запису в файл:\t";
	int mas[10];
	for (int i = 0; i < 10; i++) {
		mas[i] = rand() % 30;
		cout << setw(3) << mas[i];
	}
	fwrite(mas, sizeof(int), 10, f);
	fclose(f);

	fopen_s(&f, "t1.dat", "r+b");
	if (!f) {
		cout << "Помилка відкриття файлу\n";
		return;
	}

	int mas2[10];
	int max = mas[0], imax = 0;
	for (int i = 0; i < 10; i++) {
		fread(&mas2[i], sizeof(int), 1, f);
		if (mas2[i] > max) {
			max = mas2[i];
			imax = i;
		}
	}

	int nn = 0;
	fseek(f, imax * sizeof(int), SEEK_SET);
	fwrite(&nn, sizeof(int), 1, f);
	fclose(f);

	fopen_s(&f, "t1.dat", "rb");
	if (!f) {
		cout << "Помилка відкриття файлу\n";
		return;
	}

	int mas3[10];
	cout << "\nМасив після читання з файлу:\t";
	for (int i = 0; i < 10; i++) {
		fread(&mas3[i], sizeof(int), 1, f);
		cout << setw(3) << mas3[i];
	}
	fclose(f);
	cout << endl;
}

struct Krol {
	int id;
	int voz;
	int massa;
};

void task8() {
	FILE* f;
	Krol dat, mx;
	int n;

	fopen_s(&f, "krolik.dat", "wb");
	if (!f) {
		cout << "Помилка відкриття файлу\n";
		return;
	}

	cout << "Введіть кількість кроликів -> ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Введіть id вік масу кролика -> ";
		cin >> dat.id >> dat.voz >> dat.massa;
		fwrite(&dat, sizeof(Krol), 1, f);
	}
	fclose(f);

	fopen_s(&f, "krolik.dat", "rb");
	if (!f) {
		cout << "Помилка відкриття файлу\n";
		return;
	}

	fread(&mx, sizeof(Krol), 1, f);
	while (fread(&dat, sizeof(Krol), 1, f) == 1) {
		if (dat.voz > mx.voz || (dat.voz == mx.voz && dat.massa > mx.massa)) {
			mx = dat;
		}
	}
	fclose(f);

	cout << "Кролик з найбільшим віком і масою: ";
	cout << mx.id << " " << mx.voz << " " << mx.massa << endl;
}

struct A {
	int x;
	int y;
};

void task9() {
	FILE* f;
	A spis[4], dat;

	fopen_s(&f, "t1.dat", "wb");
	if (!f) {
		cout << "Помилка відкриття файлу\n";
		return;
	}

	for (int i = 0; i < 3; i++) {
		cout << "Введіть x y -> ";
		cin >> spis[i].x >> spis[i].y;
		fwrite(&spis[i], sizeof(A), 1, f);
	}
	fclose(f);

	fopen_s(&f, "t1.dat", "ab");
	if (!f) {
		cout << "Помилка відкриття файлу\n";
		return;
	}

	dat.x = 9;
	dat.y = 99;
	fwrite(&dat, sizeof(A), 1, f);
	fclose(f);

	fopen_s(&f, "t1.dat", "rb");
	if (!f) {
		cout << "Помилка відкриття файлу\n";
		return;
	}

	cout << "\nДані у файлі після додавання в кінець:\n";
	for (int i = 0; i < 4; i++) {
		fread(&spis[i], sizeof(A), 1, f);
		cout << spis[i].x << " " << spis[i].y << endl;
	}
	fclose(f);
}

#define n 5

void f1(char* name, int* mas) {
	FILE* f;
	fopen_s(&f, name, "wb");
	fwrite(mas, sizeof(int), n, f);
	fclose(f);
}

void f2(char* name, int* S, int* P) {
	FILE* f;
	fopen_s(&f, name, "rb");
	int x;
	for (int i = 0; i < n; i++) {
		fread(&x, sizeof(int), 1, f);
		if (x > 0) *P *= x;
		else *S += x;
	}
	fclose(f);
}

void task10() {
	int mas[n];
	int P = 1, S = 0;

	cout << "Масив:\n";
	for (int i = 0; i < n; i++) {
		mas[i] = rand() % 10 - 5;
		cout << mas[i] << " ";
	}

	char name[20];
	cout << "\nВведіть ім'я файлу -> ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.getline(name, 20);

	f1(name, mas);
	f2(name, &S, &P);

	cout << "\nСума негативних: " << S << endl;
	cout << "Добуток позитивних: " << P << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	task1();
	task2();
	task3();
	task4();
	task5();
	task6();
	task7();
	task8();
	task9();
	task10();

	return 0;
}
