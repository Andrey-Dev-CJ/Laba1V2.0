#pragma once
#include"List.h"
#include<iostream>
#include<string>
using namespace std;
template<class T>
inline List<T>::List()
{
	head = q = nullptr;
	size = 0;
	
}

template<class T>
inline List<T>::List(T val)
{
	size = 0;
	head = nullptr;
	Element<T>* elptr = new (Element<T>);
	elptr->setVal(val);
	elptr->setAdr(elptr);
	head = q = elptr;
	size++;
}

template<class T>
inline List<T>::List(T* arr, int size)
{
	this->size = 0;
	head = nullptr;
	q = nullptr;
	for (int i = 0; i < size; i++) {
		Element<T>* elptr = new (Element<T>), * qptr = head;
		if (this->size == 0) {
			elptr->setVal(arr[i]);
			elptr->setAdr(elptr);
			head = q = elptr;
		}
		else {
			elptr->setVal(arr[i]);
			while (qptr->getAdr() != head) //проходимся до последнего 
				qptr = qptr->getAdr();
			qptr->setAdr(elptr);
			elptr->setAdr(head);
		}
		this->size++;
	}
	
}

template<class T>
inline List<T>::List(const List<T>& obj)
{
	this->head = nullptr;
	this->q = this->head;
	this->size = obj.size;

	Element<T>* elptrObj = obj.head;
	for (int i = 0; i < this->size; i++) {
		Element<T>* elptr = new (Element<T>);
		if (i == 0) {
			elptr->setVal(elptrObj->getVal());
			elptr->setAdr(elptr);
			this->head = this->q = elptr;
		}
		else {
			Element<T>* hptr = head;
			elptr->setVal(elptrObj->getVal());
			while (hptr->getAdr() != this->head) //проходимся до последнего 
				hptr = hptr->getAdr();
			hptr->setAdr(elptr);
			elptr->setAdr(this->head);
		}
		elptrObj = elptrObj->getAdr();
	}
}


template<class T>
inline List<T>::~List()
{
	try {
		if (head == nullptr)
			throw "error";
		Element<T>* ptr = q;
		for (int i = 0; i < size; i++) {
			ptr = ptr->getAdr();
			delete head;
			head = ptr;

		}
		size = 0;
	}
	catch (...) {
		std::cout << " ";
	}
}

template<class T>
inline int List<T>::getSize()
{
	return this->size;
}

template<class T>
inline List<T>& List<T>::operator=(const List<T>& obj)
{
	// TODO: вставьте здесь оператор return
	this->head = nullptr;
	this->q = this->head;
	this->size = obj.size;

	Element<T>* elptrObj = obj.head;//ссылка на первый элемент входного объекта


	for (int i = 0; i < this->size; i++) {

		Element<T>* elptr = new (Element<T>);
		if (i == 0) {
			elptr->setVal(elptrObj->getVal());
			elptr->setAdr(elptr);
			this->head = this->q = elptr;
		}
		else {
			Element<T>* hptr = head;
			elptr->setVal(elptrObj->getVal());
			while (hptr->getAdr() != this->head) //проходимся до последнего 
				hptr = hptr->getAdr();
			hptr->setAdr(elptr);
			elptr->setAdr(this->head);
		}
		elptrObj = elptrObj->getAdr();

		return *this;
	}


}

template<class T>
inline T List<T>::operator[](const int index)
{
	Element<T>*qptr = this->head;
	for (int i = 0; i < index; i++) {
		qptr = qptr->getAdr();
	}
	//T myObj = qptr->getVal();
	return T(qptr->getVal());//why i can't get object????
}

template<class T>
inline void List<T>::append(T val)
{

	Element<T>* elptr = new (Element<T>), * qptr = head;
	if (this->size == 0) {
		
		elptr->setVal(val);
		elptr->setAdr(elptr);
		head = q = elptr;
	}
	else {
		elptr->setVal(val);
		while (qptr->getAdr() != head) //проходимся до последнего 
			qptr = qptr->getAdr();
		qptr->setAdr(elptr);
		elptr->setAdr(head);
	}
	this->size++;
}

template<class T>
inline T& List<T>::pop()
{
	try
	{
		Element<T>* qptr = head;
		T val;
		if (this->size == 0) {
			throw "Empty list";
		}
		else {
			while (qptr->getAdr()->getAdr()!= head) //проходимся до предпоследнего 
				qptr = qptr->getAdr();
			val = q->getVal();
			delete q;
			q = qptr->getAdr();
			qptr->setAdr(head);
		}
		this->size--;
		return val;
	}
	catch (const std::exception&)
	{

	}
	
	
}
//
//template<class T>
//inline void List<T>::save()
//{
//	for (int i = 0; i < other.size; i++) {
//		Element<T>* qptr = other.head;
//		T val;
//		while (qptr->getAdr() != other.head) { //проходимся до последнего 
//			val = qptr->getVal();
//			val.save();
//			qptr = qptr->getAdr();//переходим к следующему
//
//		}
//		val = qptr->getVal();
//		val.save();
//
//	}
//	
//}

template<class T>
inline void List<T>::irase(int index)
{
	Element<T>* qptr = this->head, *delptr = this->head;
	string s = "empty list\n";
	try
	{
		if (size == 0)
			throw s;
		if (index == 0) {
			qptr = qptr->getAdr();
			q = qptr;
			delete head;
			q->setAdr(qptr);
			head = qptr;
			size--;
		}
		else if (index == size - 1) {
			pop();
		}
		else if (index >= size)
			throw 1;
		else {
			Element<T>* qptrLast;
			for (int i = 0; i < index-1; i++) {
				qptr = qptr->getAdr();//перед удаляемым
			}//до удаляемого	
			qptrLast = qptr;//сохранили адрес i-1
			qptr = qptr->getAdr();	//перешли к i
			qptrLast->setAdr(qptr->getAdr());//в приявзяли i-1 к i+1
			delete qptr;
			size--;

		}
	}
	
	catch (const std::exception&)
	{

	}

	
	

	//delptr = qptr;//присвоили адрес удаляемого элемента
	

}


template<class T>
inline std::ostream& operator<<(std::ostream& out, const List<T>& other)
{
	for (int i = 0; i < other.size; i++) {
		Element<T> *qptr = other.head;
	
		
		while (qptr->getAdr() != other.head) { //проходимся до последнего 
			out << qptr->getVal()<<" ";
			qptr = qptr->getAdr();

		}
		out<<qptr->getVal()<<"\n";
		
		return out;
	}
	
}
