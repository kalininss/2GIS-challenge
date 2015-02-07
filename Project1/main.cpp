#include <iostream>

using namespace std;

int N;
int M;

int amount = 0;

int main()
{
	setlocale(LC_ALL, "rus");

//ввод данных пользоватлем

	cout << "Программа определения количества домов на карте" << endl << endl;
	cout << "Введите количество строк N: ";
		cin >> N;
	cout << "Введите количество символов в строке M: ";
		cin >> M;

//объявление двумерного массива

		bool **array = new bool*[M];
	for (int count = 0; count < M; count++)
		array[count] = new bool[N];
	
//заполнение массива данными

	for (int n = 0; n < N; n++)
	{
		cout << "Введите строку № " << n + 1 << ": " << endl;
		for (int i = 0; i < M; i++)
			{
				char check;
				cin >> check;
				if (check == '*') array[n][i] = 1;
				else array[n][i] = 0;
			}	

	}

//создание массива групп

	int **group = new int*[M];
	for (int count = 0; count < M; count++)
		group[count] = new int[N];

//обнуление массива групп

	for (int n = 0; n < N; n++)//проход по строкам
	{
		for (int i = 0; i < M; i++)//проход по символам в строке
		{
			if (array[n][i] == 0) group[n][i] = -1;//если клетка без дома группа == -1
			else group[n][i] = 0;//дом == 0
		}
	}

//алгоритм 

	for (int n = 0; n < N; n++)//проход по строкам
	{
		for (int i = 0; i < M; i++)//проход по символам в строке
		{
			if (array[n][i] == 1)//если в клетке дом 
			{
				if ((i == 0) && (n == 0))//если первый элемент дом
				{					
					group[n][i] = ++amount;					
				}
				else
				{
					if (n == 0)//если первая строка
					{
						if (group[n][i - 1] == -1) group[n][i] = ++amount;//если слева нет дома, то счетчик +1
						else group[n][i] = group[n][i - 1];//иначе приравнивается группа						
					}
					else 
					{
						if (i == 0)
						{
							if (group[n-1][i] == -1) group[n][i] = ++amount;//если СВЕРХУ нет дома, то счетчик +1
							else group[n][i] = group[n-1][i];//иначе приравнивается группа
						}
						else
						{
							if ((group[n - 1][i] != -1) || (group[n][i - 1] != -1))//если слева или сверху ЕСТЬ дом
							{
								if (group[n - 1][i] != -1) group[n][i] = group[n - 1][i];//если слева дом
								if (group[n][i - 1] != -1) group[n][i] = group[n][i - 1];//если справа дом
							}
							else ++amount;//иначе счетчик увеличивается
						}
					}
					
				}
				
			}
		}
	}

//вывод результатов

	cout << "Количество домов на карте  = " << amount << endl;

//удаление массива
	for (int i = 0; i < N; i++)
	{
		delete[] array[i];
	}
	delete[] array;
	system("PAUSE");
	return 0;
} 