// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыделяться память
template<typename T>
class Stack
{
protected:
	T* pMem;
	int top_index;
	int size;
	Stack(sz)
	{
		size = sz;
		T* pMem = new T[size];
		top_index = -1;
	}
public:
	void push( T value)
	{
		if (top_index + 1 < size)
		{
			top_index += 1;
			pMem[top_index] = value;
		}
		else
		{
			T* tmp = new T[size*2];
			for (int i = 0; i < top_index; i++)
			{
				tmp[i] = pMem[i];
			}
			delete pMem;
			pMem = tmp;
			top_index += 1;
			pMem[top_index] = value;
			size *= 2;
		}
	}
	T top()
	{
		return pMem[top_index];
	}
	T pop()
	{
		T tmp = pMem[top_index];
		top_index -= 1;
		return tmp;
	}
	bool emptiness_сheck()
	{
		return (top_index == -1);
	}
	int stack_real_size()
	{
		return(top_index + 1);
	}
	void delete_stack()
	{
		top_index = -1;
	}
	~stack()
	{
		delete[] pMem;
	}
};