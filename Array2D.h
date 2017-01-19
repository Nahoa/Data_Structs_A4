#pragma once
#include "Exception.h"
#include "Row.h"

template<typename T>
class Array2D
{
public:
	Array2D();
	Array2D(int row, int column);
	Array2D(const Array2D & copy);
	~Array2D();
	Array2D& operator=(const Array2D & rhs);
	Row<T> operator[](int index);
	int getRow()const;
	void setRow(int row);
	int getColumn()const;
	void setColumn(int column);
	T & Select(int row, int column);
	void Display();
	void Purge();

private:
	T ** m_array;
	int m_row;
	int m_col;
};

template<typename T>
inline Array2D<T>::Array2D() : m_row(0), m_col(0), m_array(nullptr)
{
}

template<typename T>
inline Array2D<T>::Array2D(int row, int column) : m_row(row), m_col(column), m_array(nullptr)
{
	if (row < 0 || column < 0)
	{
		throw Exception("Cannot have a negative number");
	}
	m_array = new T *[row];

	for (int i = 0; i < row; i++)
	{
		m_array[i] = new T[column];
	}
}

template<typename T>
inline Array2D<T>::Array2D(const Array2D & copy) : m_array(nullptr), m_col(copy.m_col), m_row(copy.m_row)
{
	*this = copy;
}

template<typename T>
inline Array2D<T>::~Array2D()
{
	Purge();
}

template<typename T>
inline Array2D<T> & Array2D<T>::operator=(const Array2D & rhs)
{
	//add copy ctor stuff into here
	if (this != &rhs)
	{
		if (rhs.m_array != nullptr)
		{
			Purge();

			m_array = new T*[rhs.m_row];	//Create new rows 
			for (int i = 0; i < rhs.m_row; i++)
			{
				m_array[i] = new T[rhs.m_col];	//make new columns for each row 
				for (int j = 0; j < rhs.m_col; j++)
				{
					m_array[i][j] = rhs.m_array[i][j];	//copy over data
				}
			}
		}
		m_col = rhs.m_col;
		m_row = rhs.m_row;
	}
	return *this;
}

template<typename T>
Row<T> Array2D<T>::operator[](int index)
{
	if (index < 0)
	{
		throw Exception("Cannot access a negative index");
	}

	return Row<T>(*this, index);
}

template<typename T>
inline int Array2D<T>::getRow() const
{
	return m_row;
}

template<typename T>
inline void Array2D<T>::setRow(int row)
{
	if (row < 0) // if row is neg throw exception
	{
		throw Exception("Cannot access a negative row");
	}

	int tempcol = m_col; // creates a new length for the array

	T ** temp = new T *[row];	//Create new array
	for (int i = 0; i < row; i++)
	{
		temp[i] = new T[m_col];	
	}

	for (int i = 0; i < m_row && i < row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			temp[i][j] = m_array[i][j];	
		}
	}
	Purge();
	m_row = row; // reassigns the old m_row to the new row
	m_col = tempcol;
	m_array = temp; // the OG array gets assigned to the temp

}

template<typename T>
inline int Array2D<T>::getColumn() const
{
	return m_col;
}

template<typename T>
inline void Array2D<T>::setColumn(int column)
{
	if (column < 0)
	{
		Purge();
		throw Exception("Cannot access a negative column");
	}

	// creates a new length for the temp array

	int temprow = m_row;

	T ** temp = new T *[m_row];	//Create temp array
	for (int i = 0; i < m_row; i++)
	{
		temp[i] = new T[column];	//For each row create columns
	}

	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < column && j < m_col; j++)
		{
			temp[i][j] = m_array[i][j];	//copy over data to temp/new
		}
	}
	Purge();
	m_col = column; // makes m_col the column that was entered
	m_row = temprow;
	m_array = temp; // assigns the old m_array to the new temp created array

}

template<typename T>
inline T & Array2D<T>::Select(int row, int column)
{
	if (row < 0 || row >= m_row) // checks to see if row index is out of bounds
	{
		Purge();
		throw Exception("Invalid row index");
	}
	else if (column < 0 || column >= m_col) // checks to see if column index is out of bounds
	{
		Purge();
		throw Exception("Invalid column index");
	}

	//int index = (row * m_col) + column; // creates the index at that point in the array
	return m_array[row][column];
}

template<typename T>
inline void Array2D<T>::Display()
{
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			cout << m_array[i][j] << " ";
		}
		cout << endl;
	}
}

template<typename T>
inline void Array2D<T>::Purge()
{
	if (m_array != nullptr)
	{

		for (int i = 0; i < m_row; i++)
		{
			delete[] m_array[i];
			m_array[i] = nullptr;
		}

	}

	delete[] m_array;
	m_array = nullptr;
	m_col = 0;
	m_row = 0;
}