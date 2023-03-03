#pragma once

class IntegerArray 
{
private:
    int m_length{};
    int* m_data{};

public:
    IntegerArray() = default;

    IntegerArray(int length);
    
    IntegerArray(const IntegerArray& other);

    ~IntegerArray();

    void erase();

    int& operator[](int index);// Перегружаем оператор, получаем элемент по индексу

    // Изменяет размер массива. Любые существующие элементы будут уничтожены. Эта функция работает быстро.
    void reallocate(int newLength);

    // Изменяет размер массива. Любые существующие элементы будут сохранены. Эта функция работает медленно.
    void resize(int newLength);

    IntegerArray& operator = (const IntegerArray& a);   

    void insertBefore(int value, int index);

    void remove(int index);

    void insertAtBeginning(int value);

    void insertAtEnd(int value);

    int getLength() const;

    // получение элемента по индексу с помощью передачи индекса в функцию
    int getData(int index) const;

    void showInfo() const;
};
