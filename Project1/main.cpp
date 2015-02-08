#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int N;			//строки
	int M;			//столбцы
	int amount = 0;	//счетчик домов

//ввод данных пользоватлем

	cout << "Программа определения количества домов на карте" << endl << endl;
	cout << "Введите количество строк N: ";
	cin >> N;
	cout << "Введите количество символов в строке M: ";
	cin >> M;

//объявление двумерного массива

	int **array = new int*[N];
	for (int count = 0; count < N; count++)
		array[count] = new int[M];

//заполнение массива данными
	
	string line;

	for (int n = 0; n < N; n++)
	{
		cout << "Введите строку № " << n + 1 << ": ";
		cin >> line;
		for (int i = 0; i < M; i++)
		{			
			if (line[i] == '*') array[n][i] = -1;	//-1 = дом
			else array[n][i] = 0;				// 0 = нет дома
		}
	}

//алгоритм 

	for (int n = 0; n < N; n++)//проход по строкам
	{
		for (int i = 0; i < M; i++)//проход по символам в строке
		{
			if (array[n][i] == -1)//если в клетке дом 
			{
				if ((i == 0) && (n == 0))//если первый элемент дом
				{
					array[n][i] = ++amount;
				}
				else
				{
					if (n == 0)//если первая строка
					{
						if (array[n][i - 1] == 0) array[n][i] = ++amount;		//если слева нет дома, то счетчик +1
						else array[n][i] = array[n][i - 1];						//иначе приравнивается группа						
					}
					else
					{
						if (i == 0)//если первый столбец
						{
							if (array[n - 1][i] == 0) array[n][i] = ++amount;	//если СВЕРХУ нет дома, то счетчик +1
							else array[n][i] = array[n - 1][i];					//иначе приравнивается группа
						}
						else
						{

							if (array[n - 1][i] != 0)					//если сверху дом
							{
								array[n][i] = array[n - 1][i];			
								if ((array[n][i - 1] != 0) && (array[n][i - 1] != array[n - 1][i])) amount--;	//если сверху и снизу дом с разными группами
							}
							else
							{
								if (array[n][i - 1] != 0) array[n][i] = array[n][i - 1];//если сверху дом
								else amount++;//иначе счетчик увеличивается
							}							 
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