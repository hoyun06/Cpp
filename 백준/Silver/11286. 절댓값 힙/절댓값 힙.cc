#include <iostream>
using namespace std;

class PriQueue
{
	int arr[100001];
	int numOfData;
public:
	PriQueue() { numOfData = 0; }
	bool isEmpty();
	void enqueue(int data);
	int dequeue();
	int getHChildPri(int pInd);
};
bool PriQueue::isEmpty()
{
	if (numOfData == 0)
		return true;
	else
		return false;
}
void PriQueue::enqueue(int data)
{
	int ind = numOfData + 1;
	int absData = data;
	if (data < 0)
		absData *= -1;
	
	int parData;

	while (ind != 1)
	{
		parData = arr[ind / 2];
		if (parData < 0)
			parData *= -1;

		if (parData - absData > 0)
		{
			arr[ind] = arr[ind / 2];
			ind /= 2;
		}
		else if (parData - absData == 0)
		{
			if (arr[ind / 2] > data)
			{
				arr[ind] = arr[ind / 2];
				ind /= 2;
			}
			else
				break;
		}
		else
		{
			break;
		}
	}
	arr[ind] = data;
	numOfData++;
}
int PriQueue::dequeue()
{
	if (numOfData == 0)
		return 0;

	int data = arr[1];
	int lastElem = arr[numOfData];

	int absLastElem = lastElem;
	if (lastElem < 0)
		absLastElem *= -1;

	int pInd = 1, cInd;

	int absCData;

	while (cInd = getHChildPri(pInd))
	{
		absCData = arr[cInd];
		if (absCData < 0)
			absCData *= -1;

		if (absCData - absLastElem < 0)
		{
			arr[pInd] = arr[cInd];
			pInd = cInd;
		}
		else if (absCData - absLastElem == 0)
		{
			if (arr[cInd] < lastElem)
			{
				arr[pInd] = arr[cInd];
				pInd = cInd;
			}
			else
				break;
		}
		else
			break;
	}

	arr[pInd] = lastElem;
	numOfData--;
	return data;
}
int PriQueue::getHChildPri(int pInd)
{
	if (numOfData < pInd * 2)
		return 0;

	else if (numOfData == pInd * 2)
		return pInd * 2;

	else
	{
		int absRight = arr[pInd * 2 + 1];
		int absLeft = arr[pInd * 2];

		if (absRight < 0)
			absRight *= -1;

		if(absLeft < 0)
			absLeft *= -1;

		int comp = absRight - absLeft;

		if (comp > 0)
			return pInd * 2;
		else if (comp == 0)
		{
			if(arr[pInd * 2 + 1] >= arr[pInd * 2])
				return pInd * 2;
			else
				return pInd * 2 + 1;
		}
		else
			return pInd * 2 + 1;
	}
}

PriQueue q;
int tmparr[100000];

int main()
{
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, num;

	cin >> n;
	int j = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num == 0)
			tmparr[j++] = q.dequeue();
		else
			q.enqueue(num);
	}
	for (int i = 0; i < j; i++)
	{
		cout << tmparr[i] << "\n";
	}
	return 0;
}