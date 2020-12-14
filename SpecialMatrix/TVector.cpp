#include "TVector.h"

template <class Type>
TVector<Type>::TVector(int s, int si)
{
	//if (s > MAX_VECTOR_SIZE || s<0 || si>s || si < 0) 
	//{ throw out_of_range("Given size(s) must be less than 100000000 and greater than 0"); }
	Size = s;
	StartIndex = si;
	pVec = new Type[Size];
	for (int i = 0; i < Size; i++)
		pVec[i] = 0;

}

template <class Type>
TVector<Type>::TVector(const TVector& v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;
	pVec = new Type[Size];
	for (int i = 0; i < Size; i++)
		pVec[i] = v.pVec[i];
}

template<class Type>
Type& TVector<Type>::GetValue(int pos)
{
	//if (pos > Size || pos < StartIndex) throw out_of_range("You cannot reach this element. No such element. Out of range.");
	return pVec[pos - StartIndex];
}

template<class Type>
Type& TVector<Type>::operator[](int pos)
{
	return pVec[pos - StartIndex];
}

template<class Type>
bool TVector<Type>::operator==(TVector const& v)
{
	if (Size != v.Size || StartIndex != v.StartIndex)
		return false;
	for (int i = 0; i < v.Size; i++)
	{
		if (v.pVec[i] != pVec[i])
			return false;
	}
	return true;
}

template<class Type>
bool TVector<Type>::operator!=(TVector const& v)
{
	if (Size != v.Size || StartIndex != v.StartIndex)
		return true;
	for (int i = 0; i < v.Size; i++)
	{
		if (v.pVec[i] != pVec[i])
			return true;
	}
	return false;
}

template<class Type>
TVector<Type>& TVector<Type>::operator=(const TVector& v)
{
	if (this != &v)
	{
		if (Size != v.Size)
		{
			delete[] pVec;
			pVec = new Type[v.Size];
		}
		Size = v.Size;
		StartIndex = v.StartIndex;
		for (int i = 0; i < Size; i++)
		{
			pVec[i] = v.pVec[i];
		}
	}
	return *this;
}

template<class Type>
TVector<Type> TVector<Type>::operator+(Type const& val)
{
	TVector<Type> tmp(*this);
	for (int i = 0; i < this->Size; i++)
		tmp.pVec[i] += val;
	return tmp;
}


template<class Type>
TVector<Type> TVector<Type>::operator-(Type const& val)
{
	TVector<Type> tmp(*this);
	for (int i = 0; i < this->Size; i++)
		tmp.pVec[i] -= val;
	return tmp;
}
template<class Type>
TVector<Type> TVector<Type>::operator*(const Type& val)
{
	TVector<Type> tmp(*this);
	for (int i = 0; i < this->Size; i++)
		tmp.pVec[i] *= val;
	return tmp;
}

template<class Type>
TVector<Type> TVector<Type>:: operator+(const TVector& v)
{
	TVector<Type> tmp(*this);
	//if (v.Size != tmp.Size || v.StartIndex != tmp.StartIndex) throw length_error("Vectors' sizes must be equal");
	for (int i = 0; i < tmp.Size; i++)
		tmp.pVec[i] = tmp.pVec[i] + v.pVec[i];
	return tmp;
}
template<class Type>
TVector<Type> TVector<Type>:: operator-(const TVector& v)
{
	TVector<Type> tmp(*this);
	//if (v.Size != tmp.Size || v.StartIndex != tmp.StartIndex) throw length_error("Vectors' sizes must be equal");
	for (int i = 0; i < tmp.Size; i++)
		tmp.pVec[i] = tmp.pVec[i] - v.pVec[i];
	return tmp;
}

template<class Type>
Type TVector<Type>::operator*(const TVector& v)
{
	Type tmp = 0;
	//if (v.Size != Size || v.StartIndex != StartIndex) throw length_error("Vectors' sizes must be equal");
	for (int i = 0; i < Size; i++)
		tmp = tmp + (this->pVec[i] * v.pVec[i]);
	return tmp;
}