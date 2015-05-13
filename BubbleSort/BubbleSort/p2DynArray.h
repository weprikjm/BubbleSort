// ----------------------------------------------------
// Array that resizes dynamically   -------------------
// ----------------------------------------------------

#ifndef __P2DYNARRAY_H__
#define __P2DYNARRAY_H__

#include <assert.h>

#define DYN_ARRAY_BLOCK_SIZE 16

template<class VALUE>
class p2DynArray
{
private:

	VALUE*			data;
	unsigned int	mem_capacity;
	unsigned int	num_elements;

public:

	// Constructors
	p2DynArray() : mem_capacity(0), num_elements(0), data(NULL)
	{
		Alloc(DYN_ARRAY_BLOCK_SIZE);
	}

	p2DynArray(unsigned int capacity) : mem_capacity(0), num_elements(0), data(NULL)
	{
		Alloc(capacity);
	}

	p2DynArray(const p2DynArray& array) : mem_capacity(0), num_elements(0), data(NULL)
	{
		Alloc(array.num_elements);

		for(unsigned int i = 0; i < array.num_elements; ++i)
			PushBack(array.data[i]);
	}

	// Destructor
	~p2DynArray()
	{
		delete[] data;
	}

	// Operators
	VALUE& operator[](unsigned int index)
	{
		assert(index < num_elements);
		return data[index];
	}

	const VALUE& operator[](unsigned int index) const
	{
		assert(index < num_elements);
		return data[index];
	}

	// Data Management
	void PushBack(const VALUE& element)
	{
		if(num_elements >= mem_capacity)
		{
			Alloc(mem_capacity + DYN_ARRAY_BLOCK_SIZE);
		}

		data[num_elements++] = element;
	}

	bool Pop(VALUE& value)
	{
		if(num_elements > 0)
		{
			value = data[--num_elements];
			return true;
		}
		return false;
	}

	void Clear()
	{
		num_elements = 0;
	}

	bool Insert(const VALUE& element, unsigned int position)
	{
		if(position > num_elements)
			return false;

		if(position == num_elements)
		{
			PushBack(element);
			return true;
		}

		if(num_elements + 1 > mem_capacity)
			Alloc(mem_capacity + DYN_ARRAY_BLOCK_SIZE);

		for(unsigned int i = num_elements; i > position; --i)
		{
			data[i] = data[i - 1];
		}

		data[position] = element;
		++num_elements;

		return true;
	}

	VALUE* At(unsigned int index)
	{
		VALUE* result = NULL;
		
		if(index < num_elements)
			return result = &data[index];
		
		return result;
	}

	const VALUE* At(unsigned int index) const
	{
		VALUE* result = NULL;

		if(index < num_elements)
			return result = &data[index];

		return result;
	}

	// Utils
	unsigned int GetCapacity() const
	{
		return mem_capacity;
	}

	unsigned int Count() const
	{
		return num_elements;
	}


	double CombSort()
	{


		int gap = num_elements;
		int i, j;

		bool swapped = true;
		int counter = 0;
		int num = num_elements;
		int swapWhere = num_elements;


		while (swapped)
		{
			swapped = false;

			gap = gap * 10 / 13;
			for (i = 0, j = gap; j < num_elements; i++, j++)
			{
				counter++;
				if (data[i] > data[j])
				{

					Swap(data[i], data[(j)]);

					swapped = true;

				}

			}
			--num;

		}
		return counter;
	
	
	
	
	}


	double BubbleSortSuperOptimized()
	{

		bool swapped = true;
		int counter = 0;
		int num = num_elements;
		int swapWhere = num_elements;
		int tmpEnd;
		int tmpStart = 0;
		int alreadySorted = 0;

		while (swapped)
		{
			swapped = false;
			

			for (int i = 0; i < num - 1; i++)
			{
				counter++;
				if (data[i] > data[(i + 1)])
				{

					Swap(data[i], data[(i + 1)]);

					swapped = true;

				}

			}
			

			tmpEnd = num;


			for (int i = tmpEnd; i > 0 + alreadySorted; --i)
			{
				counter++;
				if (data[i] > data[(i + 1)])
				{
				
					Swap(data[i], data[(i + 1)]);

					swapped = true;

				}

			}

			++alreadySorted;


			--num;
			
		}
		return counter;

	}

	//Print Array
	void PrintArray()
	{
		if (num_elements == 0)
			printf("The array is empty");

		for (int i = 0; i < num_elements; i++)
		{
			printf("%d ", data[i]);//We manually change % because i don't know how to make the program detect its type (it doesn't really matter cause its for debugging)
		}
	}


	//ComSort

	double BubbleSortOptimized()
	{


		bool swapped = true;
		int counter = 0;
		int num = num_elements;
		int swapWhere = num_elements;


		while (swapped)
		{
			swapped = false;


			for (int i = 0; i < num - 1; i++)
			{
				counter++;
				if (data[i] > data[(i + 1)])
				{
					int m = i;

					Swap(data[i], data[(i + 1)]);

					swapped = true;

				}

			}
			--num;

		}
		return counter;

	}


	
	double BubbleSort()
	{

		bool swapped = true;
		int counter = 0;

		while (swapped)
		{
			swapped = false;
			
			for (int i = 0; i < num_elements-1; i++)
			{
				counter++;
				if (data[i] > data[(i+1)])
				{
					Swap(data[i], data[(i+1)]);
					swapped = true;
				}
			}
			
		}
		return counter;

	}

	
private:
	
	// Private Utils
	void Alloc(unsigned int mem)
	{
		VALUE* tmp = data;

		mem_capacity = mem;
		data = new VALUE[mem_capacity];

		if(num_elements > mem_capacity)
			num_elements = mem_capacity;

		if(tmp != NULL)
		{
			for(unsigned int i = 0; i < num_elements; ++i)
				data[i] = tmp[i];

			delete[] tmp;
		}
	}








	void Swap(VALUE &a, VALUE &b)
	{
		VALUE tmp = a;
		a = b;
		b = tmp;
	}












};

#endif // __P2DYNARRAY_H__