#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>

#include "Utilities.hpp"
//#include "VectorFunctions.hpp"

namespace WaveformUtilities {
  
  template <class T> class Matrix {
  private:
    std::vector<std::vector<T> > Data;
  public:
    Matrix();
    Matrix(unsigned int rows, unsigned int cols); // Zero-based array
    Matrix(unsigned int rows, unsigned int cols, const T& a); // a-based array
    Matrix(const Matrix &rhs);  // Copy constructor
    Matrix& operator=(const Matrix &rhs); //assignment operator
    Matrix& operator=(const std::vector<std::vector<T> >& newData); //assignment operator
    typedef T value_type; // make T available externally
    inline std::vector<T>& operator[](const unsigned int row); //subscripting: reference to row data
    inline const std::vector<T>& operator[](const unsigned int row) const;
    Matrix operator-(const Matrix& b) const;
    Matrix operator/(const Matrix& b) const;
    inline unsigned int nrows() const { return Data.size(); }
    inline unsigned int ncols() const { return Data.size()>0 ? Data[0].size() : 0; }
    void resize(unsigned int newNRows, unsigned int newNCols); // resize (contents not preserved)
    void clear(); // empty contents of this Matrix
    void push_back(const std::vector<T>& NewRow); // Add new row at back of Data
    ~Matrix() { }
  };
  
  template <class T>
  Matrix<T>::Matrix() : Data(0) { }
  
  template <class T>
  Matrix<T>::Matrix(unsigned int rows, unsigned int cols) : Data(rows, std::vector<T>(cols)) { }
  
  template <class T>
  Matrix<T>::Matrix(unsigned int rows, unsigned int cols, const T& a) : Data(rows, std::vector<T>(cols, a)) { }
  
  template <class T>
  Matrix<T>::Matrix(const Matrix &rhs) : Data(rhs.Data) { }
  
  template <class T>
  Matrix<T>& Matrix<T>::operator=(const Matrix<T> &rhs) {
    if (this != &rhs) {
      Data = rhs.Data;
    }
    return *this;
  }
  
  template <class T>
  Matrix<T>& Matrix<T>::operator=(const std::vector<std::vector<T> > &newData) {
    for(unsigned int i=1; i<newData.size(); ++i) { // Check that the input is rectangular
      if(newData[i].size() != ncols()) {
	std::cerr << "\nnewData[" << i << "].size()=" << newData[i].size() << "\tncols()=" << ncols() << std::endl;
	throw("Input data is not rectangular");
      }
    }
    Data = newData;
    return *this;
  }
  
  template <class T>
  inline std::vector<T>& Matrix<T>::operator[](const unsigned int i) {
    #ifdef _CHECKBOUNDS_
    if (i<0 || i>=nrows()) {
      std::cerr << "\ni=" << i << "\tnrows()=" << nrows() << std::endl;
      throw("Matrix subscript out of bounds");
    }
    #endif
    return Data[i];
  }
  
  template <class T>
  inline const std::vector<T>& Matrix<T>::operator[](const unsigned int i) const {
    #ifdef _CHECKBOUNDS_
    if (i<0 || i>=nrows()) {
      std::cerr << "\ni=" << i << "\tnrows()=" << nrows() << std::endl;
      throw("Matrix subscript out of bounds");
    }
    #endif
    return Data[i];
  }
  
  template <class T>
  Matrix<T> Matrix<T>::operator-(const Matrix& b) const {
    if(nrows() != b.nrows()) {
      std::cerr << "\nthis->nrows()=" << nrows() << "\tb.nrows()=" << b.nrows() << std::endl;
      throw("Cannot subtract Matrices with unequal numbers of rows");
    }
    if(ncols() != b.ncols()) {
      std::cerr << "\nthis->ncols()=" << ncols() << "\tb.ncols()=" << b.ncols() << std::endl;
      throw("Cannot subtract Matrices with unequal numbers of cols");
    }
    Matrix c;
    c.Data = Data-b.Data;
    return c;
  }
  
  template <class T>
  Matrix<T> Matrix<T>::operator/(const Matrix& b) const {
    if(nrows() != b.nrows()) {
      std::cerr << "\nthis->nrows()=" << nrows() << "\tb.nrows()=" << b.nrows() << std::endl;
      throw("Cannot divide Matrices with unequal numbers of rows");
    }
    if(ncols() != b.ncols()) {
      std::cerr << "\nthis->ncols()=" << ncols() << "\tb.ncols()=" << b.ncols() << std::endl;
      throw("Cannot divide Matrices with unequal numbers of cols");
    }
    Matrix c;
    c.Data = Data/b.Data;
    return c;
  }
  
  template <class T>
  void Matrix<T>::resize(unsigned int newNRows, unsigned int newNCols)
  {
    if(newNCols != ncols()) {
      for(unsigned int i=0; i<nrows(); ++i) {
	Data[i].resize(newNCols);
      }
    }
    if(newNRows != nrows()) {
      Data.resize(newNRows, std::vector<T>(newNCols));
    }
    return;
  }
  
  template <class T>
  void Matrix<T>::clear()
  {
    Data.clear();
    return;
  }
  
  template <class T>
  void Matrix<T>::push_back(const std::vector<T>& NewRow) {
    if(nrows()==0) {
      Data = std::vector<std::vector<T> >(1, NewRow);
    }
    if (NewRow.size() != ncols()) {
      std::cerr << "\nNewRow.size()=" << NewRow.size() << "\tncols()=" << ncols() << std::endl;
      throw("Trying to push_back on a Matrix with data of wrong size");
    }
    Data.push_back(NewRow);
    return;
  }
  
} // namespace WaveformUtilities

#endif // MATRIX_HPP
