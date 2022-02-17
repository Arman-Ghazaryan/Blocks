#include <iostream>
#include <vector>
#include <array>
#define h 2

using namespace std;

int solution(vector<int> blocks, int height)
{
	int width = INT32_MAX;
	const int size = blocks.size();
	int temp, j;
	array<int,h> arr {0};

	for (int k = 1; k < size; k++)
	{
		j = 0;
		temp = k;
		arr.fill(0);
		for (int i = 0; i < height; i++)
		{
			for (; j < temp; j++)
			{
				arr[i] += blocks[j];
			}
			j = k;
			temp = size;
		}
		for (int i = 0; i < height - 1; i++)
		{
			if (arr[i] > arr[i + 1] && arr[i] < width)
			{
				width = arr[i];
			}
			else if(arr[i + 1] < width && arr[i + 1] > arr[i])
			{
				width = arr[i + 1];
			}
		}
	}
	return width;
}

int main()
{
	vector<int> vec = { 2,3,1,1,1 };
	cout << solution(vec, h);
}