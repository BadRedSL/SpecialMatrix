#pragma once
#ifndef TMatrix_H
#define TMatrix_H
#include "TVector.h"
#include <iostream>
const int MAX_MATRIX_SIZE = 10000;

template<class Type>

class TMatrix : public TVector<TVector<Type> >
{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix& mt);
	TMatrix(const TVector<TVector<Type> >& mt);
	bool operator==(const TMatrix& mt);
	TMatrix& operator=(const TMatrix& mt);
	TMatrix operator+(const TMatrix& mt);
	TMatrix operator-(const TMatrix& mt);
	TMatrix operator*(const TMatrix& mt);

	friend istream& operator>>(istream& in, TMatrix<Type>& mt)
	{
		for (int i = 0; i < mt.Size; i++)
			in >> mt.pVec[i];
		return in;
	}
	friend ostream& operator<<(ostream& out, TMatrix<Type>& mt)
	{
		for (int i = 0; i < mt.Size; i++)
			out << mt.pVec[i] << endl;
		return out;
	}

	
	
};


#endif
