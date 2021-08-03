#include <iostream>
#include <vector>
#include <limits.h>
#include <stdio.h>
using namespace std;

//recursive rod cutting O(2^n)
int CutRod(int n, vector<int> p)
{
	if (n == 0)
		return 0;
	int q = INT_MIN;
	for (int i=1; i <= n; i++)
	{
		int temp = p[i] + CutRod(n - i, p);
		if (q < temp)
		{
			q = temp;
		}
	}
	return q;
}

//Dynamic programming
int CutRodD(int n, vector<int> p)
{
	vector<int> r(n, 0);
	for (int j = 1; j <= n; j++)
	{
		int q = INT_MIN;
		for (int i = 1; i <= j; i++)
		{
			if (q < (p[i] + r[j - i]))
			{
				q = p[i] + r[j - i];
			}
			r[j] = q;
		}
	}
	return r[n];
}

int CutRodD2(int n, vector<int> p)
{
	vector<int> r(n+1, 0);
	vector<int> s(n+1, 0);
	for (int j = 1; j <= n; j++)
	{
		int q = INT_MIN;
		for (int i = 1; i <= j; i++)
		{
			if (q < (p[i] + r[j-i]))
			{
				q = p[i] + r[j - i];
				s[j] = i;
			}
			r[j] = q;
		}
	}
	return r[n];
}

int main()
{
	vector<int> p = { 0,1,5,8,9,10 };
	int a1 = CutRod(5, p);
	int a2 = CutRodD(5, p);
	int a3 = CutRodD2(5, p);
	cout << a1 << " " << a2 << " " << a3 << endl;
	return 0;
}
