#include <iostream>
#include "integerarray.h"
#include "except.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    IntegerArray array(10);
    for (size_t i = 0; i < array.getLength(); i++) {
        array[i] = i + 1;
    }
    try {
        array.resize(8);
        array.remove(3);
        array.insertAtEnd(50);
        array.insertAtBeginning(30);
        array.insertBefore(40, 5);
        array.showInfo();
    }
    catch (const bad_range& br) {
        cout << br.what() << " Значение, вызвавшее ошибку: " << br.getError_data();
    }
    catch (const bad_length& bl) {
        cout << bl.what() << " Значение, вызвавшее ошибку: " << bl.getError_data();
    }
    catch (exception& e) {
        cout << e.what();
    }

    
    try {        
        IntegerArray array1(0);// Объявляем массив из 0 элементов
    }
    catch (const bad_length& bl) {
        cout << bl.what() << endl << "Значение, вызвавшее ошибку: " << bl.getError_data() << '\n' << endl;
    }

    
    try {         
        array.insertBefore(3, 11);// Добавляем элемент выходящий за границу массива        
    }
    catch (const bad_range& br) {
        cout << br.what() << endl << "Значение, вызвавшее ошибку: " << br.getError_data() << '\n' << endl;
    }
    try {        
        array.remove(10);//Удаляем элемент вне массива
    }
    catch (const bad_range& br) {
        cout << br.what() << endl << "Значение, вызвавшее ошибку: " << br.getError_data() << '\n' << endl;
    }
    try {       
        array.getData(-1);//Получаем информацию об элементе за границей массива
    }
    catch (const bad_range& br) {
        cout << br.what() << endl << "Значение, вызвавшее ошибку: " << br.getError_data() << '\n' << endl;
    }    
    return 0;
}