#include<bits/stdc++.h>
using namespace std;
void bestFit(int blockSize[], int m, int processSize[], int n)
{

	int alloc[n];
	memset(alloc, -1, sizeof(alloc));


	for (int i=0; i<n; i++)
	{
		int bestIdx = -1;
		for (int j=0; j<m; j++)
		{
			if (blockSize[j] >= processSize[i])
			{
				if (bestIdx == -1)
					bestIdx = j;
				else if (blockSize[bestIdx] > blockSize[j])
					bestIdx = j;
			}
		}

		if (bestIdx != -1)
		{
			alloc[i] = bestIdx;
			blockSize[bestIdx] -= processSize[i];
		}
	}

	cout << "\nProcess No.     Process Size       Block no.\n";
	for (int i = 0; i < n; i++)
	{
		cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
		if (alloc[i] != -1)
			cout << alloc[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}
int main()
{
	int blockSize[] = {100, 400, 200, 300, 900};
	int processSize[] = {210, 417, 312, 450};
	int m = sizeof(blockSize)/sizeof(blockSize[0]);
	int n = sizeof(processSize)/sizeof(processSize[0]);

	bestFit(blockSize, m, processSize, n);

	return 0 ;
}
