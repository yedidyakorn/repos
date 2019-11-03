/*
File: iterators.h
Description: runs the program
Course: 150018 C++ Workshop
Exercise 8, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/
#pragma once
#ifndef __ITERATORS_H
#define __ITERATORS_H
template <typename T, typename R>
class ForwardIterator {
protected:
	T* p;
public:
	using ValueType = R;
	using Pointer = T * ;
	using Reference = R & ;
	ForwardIterator(Pointer p) : p(p) {}
	virtual void advance() = 0;
	Reference operator*() const { return *p; }
	bool operator==(const ForwardIterator& rhs) const { return p == rhs.p; }
	bool operator!=(const ForwardIterator& rhs) const { return p != rhs.p; }
	ForwardIterator& operator++() { advance(); return *this; }
	ForwardIterator operator++(int) { auto copy(*this); ++(*this); return copy; }

};

template <typename T, typename R>
class BidirectionalIterator: class ForwardIterator
{
	using Typename ForwardIterator<T, U>::InternalType
	using ForwardIterator<T, U>::operator++;

public:
	BidirectionalIterator(Pointer p) : p(p) {}
	virtual void rend() = 0;
	BidirectionalIterator operator--() { BidirectionalIterator temp = *this;	--(*this); return temp; }
	BidirectionalIterator operator--(int) {	BidirectionalIterator temp = *this;	--(*this);return temp;}

private:
{

}
};

#endif // __ITERATORS_H

