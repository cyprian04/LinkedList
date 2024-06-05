#pragma once
class Stack
{
private:
	class Element
	{
	public:
		Element(int val);
		void PointToNext(Element* current, Element* next);
		void DisconnectLast(Element* current);
	public:
		int value;
		Element* element = nullptr;
	};
private:
	template <typename Type, typename value_type>
	class Iterator
	{
	public:
		Iterator(Type* pointer) : pointer(pointer) {};
		const Iterator& operator++() { pointer = pointer->element; return *this; }
		value_type& operator*() { return pointer->value; }
		bool operator==(const Iterator& rhs) { return pointer == rhs.pointer; }
		bool operator!=(const Iterator& rhs) { return!(pointer == rhs.pointer); }
	private:
		Type* pointer = nullptr;
	};
	typedef Iterator<Element, int> raw_iterator;
	typedef Iterator<const Element, const int> const_iterator;
private:
public:
	Stack() = default;
	Stack(const Stack& source);
	Stack& operator=(const Stack& source);
	~Stack();
	void Push(int val);
	int Pop();
	int Size() const;
	bool Empty()const;
	raw_iterator begin()
	{
		return raw_iterator(head);
	}
	raw_iterator end()
	{
		return raw_iterator(nullptr);
	}
	const_iterator begin() const
	{
		return const_iterator(head);
	}
	const_iterator end() const
	{
		return const_iterator(nullptr);
	}
private:
	int currentSize = 0;
	Element* head = nullptr;
};