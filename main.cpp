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
        cout << br.what() << " ��������, ��������� ������: " << br.getError_data();
    }
    catch (const bad_length& bl) {
        cout << bl.what() << " ��������, ��������� ������: " << bl.getError_data();
    }
    catch (exception& e) {
        cout << e.what();
    }

    
    try {        
        IntegerArray array1(0);// ��������� ������ �� 0 ���������
    }
    catch (const bad_length& bl) {
        cout << bl.what() << endl << "��������, ��������� ������: " << bl.getError_data() << '\n' << endl;
    }

    
    try {         
        array.insertBefore(3, 11);// ��������� ������� ��������� �� ������� �������        
    }
    catch (const bad_range& br) {
        cout << br.what() << endl << "��������, ��������� ������: " << br.getError_data() << '\n' << endl;
    }
    try {        
        array.remove(10);//������� ������� ��� �������
    }
    catch (const bad_range& br) {
        cout << br.what() << endl << "��������, ��������� ������: " << br.getError_data() << '\n' << endl;
    }
    try {       
        array.getData(-1);//�������� ���������� �� �������� �� �������� �������
    }
    catch (const bad_range& br) {
        cout << br.what() << endl << "��������, ��������� ������: " << br.getError_data() << '\n' << endl;
    }    
    return 0;
}