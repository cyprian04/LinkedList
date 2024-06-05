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
private:
	int currentSize = 0;
	Element* head = nullptr;
};