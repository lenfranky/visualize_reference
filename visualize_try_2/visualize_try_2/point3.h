#ifndef _POINT3_H_PHANTOM_
#define _POINT3_H_PHANTOM_
#pragma warning(disable: 4996)
#include <vector>
#include <cmath>
#include <cstring>
#include <cassert>
#include <limits>
#include <algorithm>
#include <numeric>
#include <functional>

/////////////////////////////////////////////////////
//	class CPoint3
//	This class is one implemention for storage of 3D coordinate.
//	This class could also be used as a 3D vector(œÚ¡ø)
//	In order to use opengl vertex array, this class only contain xyz value,
//	and all other parts are isolated by micro __HAVE__MORE__.

template<class T>
class CPoint3_tpl
{
public:
	typedef size_t size_type;
	typedef size_t difference_type;
	typedef T & reference;
	typedef const T & const_reference;
	typedef T value_type;
	typedef const T const_value_type;
	typedef T * iterator;
	typedef const T * const_iterator;

public:
	CPoint3_tpl()
	{
		memset(m_data, 0, sizeof(m_data));
	}

	CPoint3_tpl(value_type x, value_type y, value_type z = value_type(0))
	{
		m_data[0] = x;
		m_data[1] = y;
		m_data[2] = z;
	}

	explicit CPoint3_tpl(const_value_type * pnt)
	{
		assert(pnt != NULL);
		memcpy(m_data, pnt, sizeof(m_data));
	}

	CPoint3_tpl(const CPoint3_tpl<value_type> & rhs)
	{
		std::copy(rhs.begin(), rhs.end(), begin());
	}

	~CPoint3_tpl(){}

	CPoint3_tpl<value_type> & operator=(const CPoint3_tpl<value_type> & rhs)
	{
		std::copy(rhs.begin(), rhs.end(), begin());
		return *this;
	}

	template<typename F>
	CPoint3_tpl<T> & From(const CPoint3_tpl<F> & rhs)
	{
		copy(rhs.begin(), rhs.end(), begin());
		return *this;
	}

	template<typename F>
	const CPoint3_tpl<T> From(const CPoint3_tpl<F> & rhs)
	{
		return CPoint3_tpl<T>().From(rhs);
	}

public:
	size_t size() const {return Data_Size;}
	iterator begin(){return m_data;}
	const_iterator begin() const {return m_data;}
	iterator end(){return m_data + Data_Size;}
	const_iterator end() const {return m_data + Data_Size;}

	value_type * Data()//Return an array containing the coordinate(x, y, z, w).
	{
		return m_data;
	}

	const_value_type * Data() const
	{
		return m_data;
	}

	reference operator[](int k)//return m_data[k % 4]
	{
		return m_data[k % Data_Size];
	}

	const_reference operator[](int k) const
	{
		return m_data[k % Data_Size];
	}

	reference x(){return m_data[0];}
	const_reference x() const{return m_data[0];}
	reference y(){return m_data[1];}
	const_reference y() const{return m_data[1];}
	reference z(){return m_data[2];}
	const_reference z() const{return m_data[2];}

public:
	double Length() const//Consider (x, y, z) as a vector, and return the length of the vector
	{
		return (double)sqrt(DotMult(*this, *this));
	}

	bool operator==(const CPoint3_tpl<value_type> & rhs) const
	{
		return (m_data[0] == rhs.m_data[0]) && (m_data[1] == rhs.m_data[1]) && (m_data[2] == rhs.m_data[2]);
	}

	CPoint3_tpl<T> & operator+=(const CPoint3_tpl<T> & rhs)
	{
		std::transform(rhs.begin(), rhs.end(), begin(), begin(), std::plus<T>());
		return *this;
	}

	CPoint3_tpl<T> & operator-=(const CPoint3_tpl<T> & rhs)
	{
		transform(begin(), end(), rhs.begin(), begin(), std::minus<T>());
		return *this;
	}

	CPoint3_tpl<T> & operator*=(T rhs)
	{
		std::transform(begin(), end(), begin(), std::bind2nd(std::multiplies<T>(), rhs));
		return *this;
	}

	CPoint3_tpl<T> & operator/=(T rhs)
	{
		assert(rhs != T(0));
		std::transform(begin(), end(), begin(), std::bind2nd(std::divides<T>(), rhs));
		return *this;
	}

protected:
	enum _etagInit{Data_Size = 3};
	value_type		m_data[Data_Size];//Stored in the format of (x, y, z, w).
};

//member function implementation of type float and double
bool CPoint3_tpl<float>::operator==(const CPoint3_tpl<float> & p) const
{
	return (fabs(m_data[0] - p.m_data[0]) <= std::numeric_limits<float>::epsilon())
		&& (fabs(m_data[1] - p.m_data[1]) <= std::numeric_limits<float>::epsilon())
		&& (fabs(m_data[2] - p.m_data[2]) <= std::numeric_limits<float>::epsilon());
}

bool CPoint3_tpl<double>::operator==(const CPoint3_tpl<double> & p) const
{
	return (fabs(m_data[0] - p.m_data[0]) <= std::numeric_limits<double>::epsilon())
		&& (fabs(m_data[1] - p.m_data[1]) <= std::numeric_limits<double>::epsilon())
		&& (fabs(m_data[2] - p.m_data[2]) <= std::numeric_limits<double>::epsilon());
}

CPoint3_tpl<float> & CPoint3_tpl<float>::operator/=(float rhs)
{
	assert(fabs(rhs) > std::numeric_limits<float>::epsilon());
	std::transform(begin(), end(), begin(), std::bind2nd(std::divides<T>(), rhs));
	return *this;
}

CPoint3_tpl<double> & CPoint3_tpl<double>::operator/=(double rhs)
{
	assert(fabs(rhs) > std::numeric_limits<double>::epsilon());
	std::transform(begin(), end(), begin(), std::bind2nd(std::divides<T>(), rhs));
	return *this;
}

#ifdef __POINT3__USE__FLOAT__
typedef CPoint3_tpl<float>		CPoint3;
#else
typedef CPoint3_tpl<double>		CPoint3;
#endif//__POINT3__USE__FLOAT__
typedef CPoint3_tpl<long>		CPointInt;
typedef std::vector<CPoint3>			CPointVector;//a series of CPoint3, could indicate a line or circle.

//Math functions of CPoint3_tpl
template<typename T>
const CPoint3_tpl<T> operator+(const CPoint3_tpl<T> & lhs)
{
	return lhs;
}

template<typename T>
const CPoint3_tpl<T> operator-(const CPoint3_tpl<T> & lhs)
{
	CPoint3_tpl<T> r;
	std::transform(lhs.begin(), lhs.end(), r.begin(), std::negate<T>());
	return r;
}

template<typename T>
const CPoint3_tpl<T> operator+(const CPoint3_tpl<T> & lhs, const CPoint3_tpl<T> & rhs)
{
	return CPoint3_tpl<T>(lhs) += rhs;
}

template<typename T>
const CPoint3_tpl<T> operator-(const CPoint3_tpl<T> & lhs, const CPoint3_tpl<T> & rhs)
{
	return CPoint3_tpl<T>(lhs) -= rhs;
}

template<typename T>
const CPoint3_tpl<T> operator*(const CPoint3_tpl<T> & lhs, T rhs)
{
	return CPoint3_tpl<T>(lhs) *= rhs;
}

template<typename T>
const CPoint3_tpl<T> operator*(T lhs, const CPoint3_tpl<T> & rhs)
{
	return CPoint3_tpl<T>(rhs) *= lhs;
}

template<typename T>
const CPoint3_tpl<T> operator/(const CPoint3_tpl<T> & lhs, T rhs)
{
	return CPoint3_tpl<T>(lhs) /= rhs;
}

template<class T>
const T Distance(const CPoint3_tpl<T> & lhs, const CPoint3_tpl<T> & rhs)
{
	return (CPoint3_tpl<T>(lhs) -= rhs).Length();
}

template<class T>
const T DotMult(const CPoint3_tpl<T> & lhs, const CPoint3_tpl<T> & rhs)
{
	return std::inner_product(lhs.begin(), lhs.end(), rhs.begin(), T(0));
}

//template<class T>
//const T chainDotMult(const vector<CPoint3_tpl<t>>& hs)
//{
//	CPoint3_tpl<T> tp = hs[0];
//	for (int i = 1; i < hs.size(); i++)
//	{
//		tp = DotMult(tp, hs[i]);
//	}
//	return
//}


template<class T>
const CPoint3_tpl<T> CrossMult(CPoint3_tpl<T> & lhs, CPoint3_tpl<T> & rhs)
{
	CPoint3_tpl<T> p;
	p.x() = lhs.y() * rhs.z() - rhs.y() * lhs.z();
	p.y() = rhs.x() * lhs.z() - lhs.x() * rhs.z();
	p.z() = lhs.x() * rhs.y() - lhs.y() * rhs.x();
	return p;
}

template<class T>
const CPoint3_tpl<T> triangleNormal(CPoint3_tpl<T> & point1, CPoint3_tpl<T> & point2, CPoint3_tpl<T> & point3)
{
	CPoint3_tpl<T> tempv1,tempv2;
	tempv1 = point2 - point1;
	tempv2 = point3 - point2;
	return CrossMult(tempv1, tempv2);
}

template<class T>
double triangleArea(CPoint3_tpl<T> & point1, CPoint3_tpl<T> & point2, CPoint3_tpl<T> & point3)
{
	double p = double(((point1 - point2).Length() + (point2 - point3).Length() + (point3 - point1).Length())/2.0);
	return sqrt(p*(p - (point1 - point2).Length())*(p - (point2 - point3).Length())*(p - (point3 - point1).Length()));

}

typedef CPoint3_tpl<int>       CdpPoint;
#endif//_POINT3_H_PHANTOM_
