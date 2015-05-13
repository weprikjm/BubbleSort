#include <iostream>
#include "BubbleSort.h"
#include "p2DynArray.h"

int main()
{
	p2DynArray<int> bubble;
	
	
	
	for (int i = 0; i < 10000; i++)
	{
		bubble.PushBack(rand());
	}
	

	int i = bubble.CombSort();

	
	bubble.PrintArray();
	printf("\n%d", i);
	
	getchar();


}