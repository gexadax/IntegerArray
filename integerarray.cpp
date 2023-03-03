#include "integerarray.h"
#include "except.h"
#include <iostream>
using namespace std;

IntegerArray::IntegerArray(int length) : m_length(length) {
    if (length <= 0) {
        throw bad_length("ОШИБКА! Предоставление неправильной длины массиву!", length);
    }
    m_data = new int[length] {};
}

IntegerArray::IntegerArray(const IntegerArray& other) {
    this->m_length = other.m_length;
    this->m_data = new int[other.m_length];
    for (size_t i = 0; i < other.m_length; i++) {
        this->m_data[i] = other.m_data[i];
    }
}

IntegerArray::~IntegerArray() {
    delete[] m_data;
}

void IntegerArray::erase()
{
    delete[] m_data;    
    m_data = nullptr;
    m_length = 0;
}

int& IntegerArray::operator[](int index) {
    if (index < 0 || index >= m_length) {
        throw bad_range("ОШИБКА! Указанный индекс находится вне массива!", index);
    }
    return m_data[index];
}

void IntegerArray::reallocate(int newLength) {
    erase();
    if (newLength <= 0) {
        return;
    }    
    m_data = new int[newLength];
    m_length = newLength;
}

void IntegerArray::resize(int newLength) {    
    if (newLength == m_length) {
        return;
    }    
    if (newLength <= 0) {
        erase();
        return;
    }    
    int* data = new int[newLength];
    if (m_length > 0) {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
        for (size_t i = 0; i < elementsToCopy; i++)
            data[i] = m_data[i];
    }
    delete[] m_data;
    m_data = data;
    m_length = newLength;
}

IntegerArray& IntegerArray::operator = (const IntegerArray& a) {    
    if (&a == this) {
        return *this;
    }    
    reallocate(a.getLength());
    for (size_t i = 0; i < m_length; i++)
        m_data[i] = a.m_data[i];
    return *this;
}

void IntegerArray::insertBefore(int value, int index) {
    if (index < 0 || index > m_length) {
        throw bad_range("ОШИБКА! Указанный индекс находится вне массива!", index);
    }    
    int* data = new int[m_length + 1];

    for (size_t before = 0; before < index; before++) {
        data[before] = m_data[before];
    }   
    data[index] = value;
    for (size_t after = index; after < m_length; after++) {
        data[after + 1] = m_data[after];
    }  
    delete[] m_data;
    m_data = data;
    ++m_length;
}

void IntegerArray::remove(int index) {
    if (index < 0 || index >= m_length) {
        throw bad_range("ОШИБКА! Указанный индекс находится вне массива!", index);
    }
    if (m_length == 1) {
        erase();
        return;
    }
    int* data = new int[m_length - 1];   
    for (size_t before = 0; before < index; before++) {
        data[before] = m_data[before];
    }  
    for (size_t after = index + 1; after < m_length; after++) {
        data[after - 1] = m_data[after];
    }        
    delete[] m_data;
    m_data = data;
    --m_length;
}

void IntegerArray::insertAtBeginning(int value) {
    insertBefore(value, 0); 
}
void IntegerArray::insertAtEnd(int value) {
    insertBefore(value, m_length); 
}

int IntegerArray::getLength() const {
    return m_length; 
}

int IntegerArray::getData(int index) const {
    if (index < 0 || index >= m_length) {
        throw bad_range("ОШИБКА! Указанный индекс находится вне массива!", index);
    }
    return m_data[index];
}

void IntegerArray::showInfo() const {
    if (m_length > 0) {
        cout << "Длина массива равна: " << m_length << '\n' << endl;
        cout << "Массив содержит числа: ";
        for (size_t i = 0; i < m_length; i++) {
            cout << m_data[i];
            if (i != m_length - 1) {//Проверяет является ли текущий элемент последним в массиве и добавляет после него пробел
                cout << " ";
            }
        }
        cout << '\n' << endl;
    }
    else {
        cout << "Длина массива равна: " << m_length << '\n' << endl;
    }
}