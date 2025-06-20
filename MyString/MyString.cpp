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

	/*MyString operator +(const MyString& other) {
	 MyString newStr;
	 int thislenght = strlen(this.str);
	 newStr.str = new
	}*/

private:
	char* str;
};


int main()
{
	setlocale(LC_ALL, "RU");
	MyString str("Hello");
	MyString str2("World");

	MyString result;
	MyString result56;

	cout << "-----" << endl;
	cout << "Hi";
	cout << "delete";

	str = str2;
	
	return 0;
}
