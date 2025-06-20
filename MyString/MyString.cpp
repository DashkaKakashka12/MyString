#include <iostream>

using namespace std;

class MyString {
public:

	MyString() {
		str = nullptr;
	}

	MyString(const char* str) {
		int length = strlen(str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';

	}

	~MyString() {

		delete[] this->str;
	}

	void Print() {
		cout << "Текст: " << str << endl;
	}

	MyString& operator = (const MyString& other) {
		if (this->str != nullptr) {
			delete[] str;
		}

		int length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return*this;
	}

	 MyString operator +(const MyString& other) {

	 MyString newStr;

	 int thislenght = strlen(this->str);
	 int otherlenght = strlen(other.str);
	 newStr.str = new char[thislenght + otherlenght + 1];
	 int i = 0;

	 for (; i < thislenght; i++)
	 {
		newStr.str[i] = this->str[i];
	 }

	 for (int t = 0; t < otherlenght; t++,i++)
	 {
		 newStr.str[i] = other.str[t];

	 }

	 newStr.str[thislenght + otherlenght] = '\0';

	 return newStr;
	}

private:
	char* str;
};


int main()
{
	setlocale(LC_ALL, "RU");
	MyString str("Hello");
	MyString str2("World");

	//str = str2;

	MyString result;
	result = str + str2;


	return 0;
}
