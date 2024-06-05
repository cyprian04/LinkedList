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
	class Iterator
	{
	public:
		Iterator(Element* pointer) : pointer(pointer) {};
		Iterator& operator++() { pointer = pointer->element; return *this; }
		int& operator*() { return pointer->value; }
		bool operator==(const Iterator& rhs) { return pointer == rhs.pointer; }
		bool operator!=(const Iterator& rhs) { return!(pointer == rhs.pointer); }
	private:
		Element* pointer = nullptr;
	};
private:
	class ConstIterator
	{
	public:
		ConstIterator(const Element* pointer) : pointer(pointer) {};
		const ConstIterator& operator++() { pointer = pointer->element; return *this; }
		const int& operator*() { return pointer->value; }
		bool operator==(const ConstIterator& rhs) { return pointer == rhs.pointer; }
		bool operator!=(const ConstIterator& rhs) { return!(pointer == rhs.pointer); }
	private:
		const Element* pointer = nullptr;
	};
public:
	Stack() = default;
	Stack(const Stack& source);
	Stack& operator=(const Stack& source);
	~Stack();
	void Push(int val);
	int Pop();
	int Size() const;
	bool Empty()const;
	Iterator begin()
	{
		return Iterator(head);
	}
	Iterator end()
	{
		return Iterator(nullptr);
	}
	ConstIterator begin() const
	{
		return ConstIterator(head);
	}
	ConstIterator end() const
	{
		return ConstIterator(nullptr);
	}
private:
	int currentSize = 0;
	Element* head = nullptr;
};