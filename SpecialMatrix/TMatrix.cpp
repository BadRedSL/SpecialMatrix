#include "TMatrix.h"

template<class Type>
TMatrix<Type>::TMatrix(int s) : TVector<TVector<Type> >(s)
{
	for (int i = 0; i < s; i++)
		this->pVec[i] = TVector<Type>(s - i, i);
}

template<class Type>
TMatrix<Type>::TMatrix(const TMatrix<Type>& mt) :TVector<TVector<Type> >(mt) {}

template<class Type>
TMatrix<Type>::TMatrix(const TVector<TVector<Type> >& mt) : TVector<TVector<Type> >(mt)
{
	for (int i = 0; i < this->GetSize(); i++)
	{
		if (this->pVec[i].GetSize() != this->GetSize() - i)
			throw std::out_of_range("This is not a triangle matrix");
	}
}


template<class Type>
TMatrix<Type>& TMatrix<Type>:: operator=(const TMatrix& mt)
{
	if (this != &mt)
	{
		if (this->Size != mt.Size)
		{
			delete[] this->pVec;
			this->pVec = new TVector<Type>[mt.Size];
		}
		this->Size = mt.Size;
		this->StartIndex = mt.StartIndex;
		for (int i = 0; i < this->Size; i++)
		{
			this->pVec[i] = mt.pVec[i];
		}
	}
	return *this;
}

template<class Type>
bool TMatrix<Type>::operator==(TMatrix const& mt)
{
	if (this->Size != mt.Size || this->StartIndex != mt.StartIndex)
		return false;
	for (int i = 0; i < mt.Size; i++)
	{
		if (mt.pVec[i] != this->pVec[i])
			return false;
	}
	return true;
}

template<class Type>
TMatrix<Type> TMatrix<Type>::operator+(const TMatrix& mt)
{
	TMatrix tmp(*this);
	//if (mt.Size != tmp.Size || mt.StartIndex != tmp.StartIndex) throw length_error("Matrixes' sizes must be equal");
	for (int i = 0; i < tmp.Size; i++)
		tmp.pVec[i] = tmp.pVec[i] + mt.pVec[i];
	return tmp;
}

template<class Type>
TMatrix<Type> TMatrix<Type>::operator-(const TMatrix& mt)
{
	TMatrix tmp(*this);
	//if (mt.Size != tmp.Size || mt.StartIndex != tmp.StartIndex) throw length_error("Matrixes' sizes must be equal");
	for (int i = 0; i < tmp.Size; i++)
		tmp.pVec[i] = tmp.pVec[i] - mt.pVec[i];
	return tmp;
}

template<class Type>
TMatrix<Type> TMatrix<Type>::operator*(const TMatrix& mt)
{

	//if (mt.Size != this->Size || mt.StartIndex != this->StartIndex) throw length_error("Matrixes' sizes must be equal");
	TMatrix<Type> tmp(this->Size);
	for (int i = 0; i < this->Size; i++)
		for (int j = 0; j < this->Size; j++) 
		{
			Type tp = Type();
			for (int k = i; k <= j; ++k)
			{
				tp = tp + (this->pVec[i][k] * mt.pVec[k][j]);
			}
			
			tmp.pVec[i][j] = tp;
			
		} 
	return tmp;
}

