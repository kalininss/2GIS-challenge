#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int N;			//������
	int M;			//�������
	int amount = 0;	//������� �����

//���� ������ ������������

	cout << "��������� ����������� ���������� ����� �� �����" << endl << endl;
	cout << "������� ���������� ����� N: ";
	cin >> N;
	cout << "������� ���������� �������� � ������ M: ";
	cin >> M;

//���������� ���������� �������

	int **array = new int*[N];
	for (int count = 0; count < N; count++)
		array[count] = new int[M];

//���������� ������� �������
	
	string line;

	for (int n = 0; n < N; n++)
	{
		cout << "������� ������ � " << n + 1 << ": ";
		cin >> line;
		for (int i = 0; i < M; i++)
		{			
			if (line[i] == '*') array[n][i] = -1;	//-1 = ���
			else array[n][i] = 0;				// 0 = ��� ����
		}
	}

//�������� 

	for (int n = 0; n < N; n++)//������ �� �������
	{
		for (int i = 0; i < M; i++)//������ �� �������� � ������
		{
			if (array[n][i] == -1)//���� � ������ ��� 
			{
				if ((i == 0) && (n == 0))//���� ������ ������� ���
				{
					array[n][i] = ++amount;
				}
				else
				{
					if (n == 0)//���� ������ ������
					{
						if (array[n][i - 1] == 0) array[n][i] = ++amount;		//���� ����� ��� ����, �� ������� +1
						else array[n][i] = array[n][i - 1];						//����� �������������� ������						
					}
					else
					{
						if (i == 0)//���� ������ �������
						{
							if (array[n - 1][i] == 0) array[n][i] = ++amount;	//���� ������ ��� ����, �� ������� +1
							else array[n][i] = array[n - 1][i];					//����� �������������� ������
						}
						else
						{

							if (array[n - 1][i] != 0)					//���� ������ ���
							{
								array[n][i] = array[n - 1][i];			
								if ((array[n][i - 1] != 0) && (array[n][i - 1] != array[n - 1][i])) amount--;	//���� ������ � ����� ��� � ������� ��������
							}
							else
							{
								if (array[n][i - 1] != 0) array[n][i] = array[n][i - 1];//���� ������ ���
								else amount++;//����� ������� �������������
							}							 
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