
#include<iostream>

using namespace std;

int main()
{
	int str[]{1,2,3,4};
	int count = 0;

	for (auto v : str)
	{
		cout << v;
	}
	cout << endl;
	return 0;
}