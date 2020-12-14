#pragma once
#ifndef TVector_H
#define TVector_H
#include <iostream>
using namespace std;
const int MAX_VECTOR_SIZE = 100000000;
template <class Type>
class TVector
{
protected:
	Type* pVec;
	int Size;
	int StartIndex;
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector& v);
	int GetSize() { return Size; };
	int GetStartIndex() { return StartIndex; };
	Type& GetValue(int pos);
	Type& operator[](int pos);
	bool operator==(const TVector& v);
	bool operator!=(const TVector& v);
	TVector& operator=(const TVector& v);
	TVector operator+(const Type& val);
	TVector operator-(const Type& val);
	TVector operator*(const Type& val);
	TVector operator+(const TVector& v);
	TVector operator-(const TVector& v);
	Type operator*(const TVector& v);
	friend istream& operator>>(istream& in, TVector& v)
	{
		for (int i = 0; i < v.Size; i++)
			in >> v.pVec[i];
		return in;
	}

	friend ostream& operator<<(ostream& out, const TVector<Type>& v)
	{
		for (int i = 0; i < v.StartIndex; i++)
		{
			out << ' ' << '\t';
		}
		for (int i = 0; i < v.Size; i++)
		{
			out << v.pVec[i] <<'\t';
		}
		out << endl;
		return out;
	}

};

#endif
