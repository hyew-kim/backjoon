#include<iostream>

using namespace std;

int arr[10];
bool isused[10];
int n, m;

void func(int idx)
{
	if (idx == m) // ���� ����
	{
		for (int i = 0;i < m;i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1;i <= n;i++)
	{
		if (!isused[i])
		{
			arr[idx] = i;
			isused[i] = true;
			func(idx + 1);// ���� ĭ ä�췯 ����
			//cout << "idx: " << idx << " i: " << i <<"\n";
			isused[i] = false; //�̱��� �Դٴ°� ����ϰ� return �� �� ä������ ���ʴ�� off
		}
	}
	return;
}
int main(void)
{
	cin >> n >> m;
	func(0);
	return 0;
}