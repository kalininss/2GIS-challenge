#include <iostream>

using namespace std;

int N;
int M;

int amount = 0;

int main()
{
	setlocale(LC_ALL, "rus");

//���� ������ ������������

	cout << "��������� ����������� ���������� ����� �� �����" << endl << endl;
	cout << "������� ���������� ����� N: ";
		cin >> N;
	cout << "������� ���������� �������� � ������ M: ";
		cin >> M;

//���������� ���������� �������

		bool **array = new bool*[M];
	for (int count = 0; count < M; count++)
		array[count] = new bool[N];
	
//���������� ������� �������

	for (int n = 0; n < N; n++)
	{
		cout << "������� ������ � " << n + 1 << ": " << endl;
		for (int i = 0; i < M; i++)
			{
				char check;
				cin >> check;
				if (check == '*') array[n][i] = 1;
				else array[n][i] = 0;
			}	

	}

//�������� ������� �����

	int **group = new int*[M];
	for (int count = 0; count < M; count++)
		group[count] = new int[N];

//��������� ������� �����

	for (int n = 0; n < N; n++)//������ �� �������
	{
		for (int i = 0; i < M; i++)//������ �� �������� � ������
		{
			if (array[n][i] == 0) group[n][i] = -1;//���� ������ ��� ���� ������ == -1
			else group[n][i] = 0;//��� == 0
		}
	}

//�������� 

	for (int n = 0; n < N; n++)//������ �� �������
	{
		for (int i = 0; i < M; i++)//������ �� �������� � ������
		{
			if (array[n][i] == 1)//���� � ������ ��� 
			{
				if ((i == 0) && (n == 0))//���� ������ ������� ���
				{					
					group[n][i] = ++amount;					
				}
				else
				{
					if (n == 0)//���� ������ ������
					{
						if (group[n][i - 1] == -1) group[n][i] = ++amount;//���� ����� ��� ����, �� ������� +1
						else group[n][i] = group[n][i - 1];//����� �������������� ������						
					}
					else 
					{
						if (i == 0)
						{
							if (group[n-1][i] == -1) group[n][i] = ++amount;//���� ������ ��� ����, �� ������� +1
							else group[n][i] = group[n-1][i];//����� �������������� ������
						}
						else
						{
							if ((group[n - 1][i] != -1) || (group[n][i - 1] != -1))//���� ����� ��� ������ ���� ���
							{
								if (group[n - 1][i] != -1) group[n][i] = group[n - 1][i];//���� ����� ���
								if (group[n][i - 1] != -1) group[n][i] = group[n][i - 1];//���� ������ ���
							}
							else ++amount;//����� ������� �������������
						}
					}
					
				}
				
			}
		}
	}

//����� �����������

	cout << "���������� ����� �� �����  = " << amount << endl;

//�������� �������
	for (int i = 0; i < N; i++)
	{
		delete[] array[i];
	}
	delete[] array;
	system("PAUSE");
	return 0;
} 