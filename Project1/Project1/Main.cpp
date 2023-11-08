#include <iostream>

#define NB_PYLONES 3
#define NB_DISQUES 50

int hanoi[NB_PYLONES][NB_DISQUES] = 
{
	{},
	{},
	{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25
	,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50}
};

int CheckPyloneOpti(int pylone)
{
	int* subHanoi = hanoi[pylone];
	if (subHanoi[0] == 0)
		return 2;
	if (subHanoi[NB_DISQUES - 1] > 0)
		return 1;
	return 0;
}

int CheckHanoi()
{
	if (hanoi[0][0] > 0)
		return 0;

	for (int i = 1; i < NB_PYLONES; i++)
	{
		int resolve = CheckPyloneOpti(i);
		if (resolve < 2)
			return resolve;
	}
	return 0;
}

int CheckHanoiRecursif(int n)
{
	if (hanoi[0][0] > 0)
		return 0;

	if (n > 0)
	{
		int resolve = CheckPyloneOpti(NB_PYLONES - n + 1);
		if (resolve < 2)
			return resolve;

		return CheckHanoiRecursif(n - 1);
	}

}

int main()
{
	printf("%d\n", CheckHanoiRecursif(NB_PYLONES));
	return 0;
}