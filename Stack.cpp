#include "Stack.h"

Stack::~Stack()
{
	while (currentSize != 0)
	{
		if (currentSize == 1) {
			delete head;
			head = nullptr;
		}
		else if (currentSize > 1){
			Element* temp = head;
			Element* current = temp;

			while (temp->element != nullptr) {
				current = temp;
				temp = temp->element;
			}
			current->DisconnectLast(current);
			temp = nullptr;
			current = nullptr;
		}
		currentSize--;
	}
}

void Stack::Push(int val)
{
	if (head == nullptr)
		head = new Element(val);
	else {
		Element* temp = head->element;
		Element* current = head;
		while (temp != nullptr) {
			current = temp;
			temp = temp->element;
		}
		current->PointToNext(current, new Element(val));
		current = nullptr;
	}
	currentSize++;
}

int Stack::Pop()
{
	int val = 0;
	if (currentSize == 1) {
		val = head->value;
		delete head;
		head = nullptr;

		currentSize--;
		return val;
	}
	else if(currentSize > 1) {
		Element* temp = head;
		Element* current = temp;

		while (temp->element != nullptr) {
			current = temp;
			temp = temp->element;
		}

		val = temp->value;
		current->DisconnectLast(current);
		temp = nullptr;
		current = nullptr;

		currentSize--;
		return val;
	}
	return 0;
}

int Stack::Size() const
{
	return currentSize;
}

bool Stack::Empty() const
{
	return currentSize == 0;
}

Stack::Element::Element(int val)
	:
	value(val)
{}

void Stack::Element::PointToNext(Element* current, Element* next)
{
	current->element = next;
}

void Stack::Element::DisconnectLast(Element* current)
{
	delete current->element;
	current->element = nullptr;
}
