#ifndef TARRAY_HPP
#define TARRAY_HPP

template<typename T>
struct FnIteratorBasic
{
	typedef void (*FnIterator)(T*);
};

template<typename T>
void iter(T* arr, int length, typename FnIteratorBasic<T>::FnIterator func)
{
	for (int i = 0; i < length; i++)
	{
		func(&arr[i]);
	}
}

#endif
