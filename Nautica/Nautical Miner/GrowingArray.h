#ifndef GROWINGARRAY_H
#define GROWINGARRAY_H


constexpr unsigned DEFAULT_CAPACITY = 16;
constexpr float DEFAULT_LOAD_FACTOR = .75f;

template<typename T> class GrowingArray
{
public:

	GrowingArray();
	~GrowingArray();

	void Add(T element);
	void RemoveAt(const unsigned index);
	const T& At(const unsigned index);
	void Clear();

	const unsigned& size();

private:

	void Resize();

	T myArray [DEFAULT_CAPACITY];

	unsigned myCapacity;
	unsigned mySize;

};

#endif

