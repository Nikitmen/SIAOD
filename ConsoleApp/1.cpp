#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������� ������ �������: ";
	int n; // ������ �������
	cin >> n;
	clock_t start, end;
	start = clock();
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100; // ��������� ������ ���������� �������
		cout << a[i] << "  "; // ����� ������� �� �����
	}
	cout << "\n";
	int buff = 0;	// ��� �������� ������������� ��������
	int i, j;		// ��� ������		

	/************* ������ ���������� *******************/
	for (i = 1; i < n; i++)
	{
		buff = a[i];
		for (j = i - 1; j >= 0 && a[j] > buff; j--)
			a[j + 1] = a[j];

		a[j + 1] = buff;
	}
	/************* ����� ���������� *******************/

	for (int i = 0; i < n; i++) // ����� ���������������� �������
		cout << a[i] << "  ";
	cout << endl;
	end = clock();
	printf("����� ���������� ��������� %.4f(s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));

}