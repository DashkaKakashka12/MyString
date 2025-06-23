#include <iostream>
#include "MyString.h"

using namespace std;

class MyString {
private:
	char* str; //массив символов. хранит строку которую мы в него передали
	int lenght;

public:

	MyString() { //конструктор без параментров
		str = nullptr;
		lenght = 0;
	}

	MyString(const char* str) { // конструктор с параметрами. при создании объекта надо сразу передавать строку
		this->lenght = strlen(str);
		this->str = new char[this->lenght + 1]; // создаём новый массив размером с кол-во символов полученного массива + терминирующий 0
		for (int i = 0; i < this->lenght; i++)
		{
			this->str[i] = str[i];
		}

		this->str[this->lenght] = '\0';
	}

	~MyString() { //деструктор  удаляет наш массив
		delete[] this->str;
	}

	void Print() {
		cout << "Текст: " << str << endl;
	}


	MyString(const MyString& other) { // конструктор копирования. работает как и обычный с параметрами, надо передавать только другой объект нашего класса(копируемый)
		this->lenght = strlen(other.str);
		this->str = new char[this->lenght + 1];
		for (int i = 0; i < this->lenght; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[this->lenght] = '\0';
	}

	

	MyString& operator = (const MyString& other) { // перегруженный оператор присваивания
		if (this->str != nullptr) { // проверка есть ли в текущем объекте данные, если есть, то удаляем
			delete[] str;
		}

		this->lenght = strlen(other.str);
		this->str = new char[this->lenght + 1];
		for (int i = 0; i < this->lenght; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[this->lenght] = '\0';

		return*this;
	}

	MyString operator +(const MyString& other) { //оператор для конкатенации
		MyString newStr;

		int thislenght = strlen(this->str);
		int otherlenght = strlen(other.str); // получаем длинну обоих строк

		newStr.lenght = thislenght + otherlenght; //определяем длину новой общей строки

		 newStr.str = new char[thislenght + otherlenght + 1]; //создаём новый массив строк размером обоих + терминирующий
		 int i = 0;

		 for (; i < thislenght; i++)
		 {
			newStr.str[i] = this->str[i];
		 } // заполняем первой стракой

		 for (int t = 0; t < otherlenght; t++,i++) // с места на котором остановились(i++) заполняем второй строкой
		 {
		 newStr.str[i] = other.str[t];

		 }

		 newStr.str[thislenght + otherlenght] = '\0';


		 return newStr;
	}

	int Lenght() {
		
		return lenght;
	}

	bool operator == (const MyString& other) {
		if (this->lenght != other.lenght) {
			return false;
		}

		for (int i = 0; i < this->lenght; i++) {
			if (this->str[i] != other.str[i]) {
				return false;
			}
			
		}

		return true;
	}

	bool operator != (const MyString& other) {
		return !(this->operator==(other));
	}


	char& operator[](int index) {
		return this->str[index];
	}

	MyString(MyString&& other) noexcept { // конструктор перемещения.
		this->lenght = other.lenght;
		this->str = other.str;
	
		 (other.str = nullptr);
	}

};



int main()
{
	setlocale(LC_ALL, "RU");
	MyString str("Hello");
	MyString str2("World2");

	//str = str2;

	MyString result = str + str2;
	result.Print();


	/*cout << "Размер строки 1: " << str.Lenght()<< endl;
	cout << "Размер строки 2: " << str2.Lenght()<< endl;
	cout << "Размер строки 3: " << result.Lenght()<< endl;*/


	/*cout << (str == str2) << endl;
	cout << (str != str2) << endl;*/


	//cout << str[2] << endl;
	/*str.Print();
	str[0] = 'p';
	str.Print();*/


	return 0;
}
