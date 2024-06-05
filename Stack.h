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
	};;
public:
	Stack() = default;
	~Stack();
	void Push(int val);
	int Pop();
	int Size() const;
	bool Empty()const;
private:
	int currentSize = 0;
	Element* head = nullptr;
};