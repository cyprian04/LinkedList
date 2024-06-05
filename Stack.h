#pragma once
class Stack
{
private:
	class Element
	{
	public:
		Element(int val);
		~Element();
		void PointToNext(Element* current, Element* next);
	public:
		int value;
		Element* element = nullptr;
	};;
public:
	Stack() = default;
	void Push(int val);
	int Pop();
	int Size() const;
	bool Empty()const;
private:
	int currentSize = 0;
	Element* head = nullptr;
};