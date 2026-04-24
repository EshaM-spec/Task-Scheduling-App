#include "String.h"
#include<iostream>
using namespace std;
String::String()
{
	data = nullptr;
	size = 0;
}
String::String(const String& newStr) :String()
{

	if (newStr.data == nullptr)
		return;
	size = newStr.size;
	data = new char[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = newStr.data[i];
	}
}
int String::getLength(const char* c)const
{
	if (c == nullptr)
		return 0;
	int i = 0;
	while (c[i] != '\0')
	{
		i++;

	}
	return i;
}
String::String(const char c)
{
	data = new char[2] {c};
	data[1] = '\0';
	size = 2;

}
String::String(const char* c) :String()
{
	if (c == nullptr || getLength(c) == 0)
		return;
	int n = getLength(c) + 1;
	data = new char[n];
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		data[i] = c[i];
	}
	data[i] = '\0';
	size = n;
}
String::~String()
{
	delete[]data;
	data = nullptr;
	size = 0;
}
void String::reSize(int newSize)
{
	if (newSize <= 0)
	{
		this->~String();
		return;
	}
	char* temp = new char[newSize];
	int i;
	for (i = 0; i < size && i < newSize; i++)
	{
		temp[i] = data[i];
	}
	temp[newSize - 1] = '\0';
	this->~String();
	data = temp;
	size = newSize;
}
void String::input()
{
	this->~String();
	data = new char[2];
	size = 2;
	int count = 0;
	char ch;
	while ((ch = cin.get()) != '\n')
	{

		data[count] = ch;
		if (count + 1 == size)
			reSize(size * 2);
		count++;
	}
	data[count] = '\0';
	return;
}
bool String::isEmpty()const
{
	if (data == nullptr || data[0] == '\0')
		return true;
	return false;
}
int String::getLength()const
{
	return getLength(data);
}
int String::getSize()const
{
	return size;
}
void String::display()const
{
	if (data == nullptr || data[0] == '\0')
		return;
	int n = getLength();
	for (int i = 0; i < n; i++)
	{
		cout << data[i];
	}
}
void String::shrink()
{
	if ((data == nullptr) || (data[0] == '\0'))
		return;
	int n = getLength();
	reSize(n);
}
int String::find(const String subStr, const int start)const
{
	if ((subStr.data == nullptr) || (subStr.data[0] == '\0'))
		return -1;
	if (start < getLength() && start>-1)
	{
		int j = 0;
		int n = getLength(subStr.data);
		int oldStrLen = getLength();
		int count = 0;
		for (int i = start; i < oldStrLen; i++)
		{
			if (data[i] == subStr.data[j])
			{
				for (j = 0; j < n; j++)
				{
					if (data[i] != subStr.data[j])
						j = n + 1;
					else
						i++;
				}
				if (j == n)
				{
					return i - n;
				}
				j = 0;
				i--;
			}

		}
		return -1;
	}
	else
	{
		cout << "Index Does Not Exists";
		exit(0);
	}

}
char& String::at(int index)
{
	if (data == nullptr)
		exit(0);
	if (index < getSize() && index >= 0)
		return data[index];
	cout << "Index does not exist";
	exit(0);
}
const char& String::at(const int index)const
{
	if (data == nullptr)
		exit(0);
	if (index < getSize() && index >= 0)
		return data[index];
	cout << "Index does not exist";
	exit(0);
}
int String::replace(const String old, const String newSubStr)
{
	if (old.data == nullptr)
		return 0;
	int j = 0;
	int newStrLen = getLength(newSubStr.data);
	int oldStrLen = getLength(old.data);
	int strLen = getLength();
	int count = 0;
	int i;
	for (i = 0; i < (strLen + newStrLen - oldStrLen); i++)
	{
		if (data[i] == old.data[j])
		{

			for (j = 0; j < oldStrLen; j++)
			{
				if (data[i + j] != old.data[j])
					j = oldStrLen + 1;

			}
			if (j == oldStrLen)
			{

				remove(i, oldStrLen);
				insert(i, newSubStr);
				count++;

				i = i + (newStrLen - 1);
			}
			j = 0;
		}

	}
	return count;

}
void String::insert(const int index, const String str)
{
	if (str.data == nullptr)
	{
		return;
	}
	if (data == nullptr)
	{
		int newStrLen = getLength(str.data);
		char* temp = new char[newStrLen + 1];
		for (int i = 0; i < newStrLen; i++)
			temp[i] = str.data[i];
		temp[newStrLen] = '\0';
		this->~String();
		data = temp;
		size = newStrLen + 1;

	}
	else if (index <= getLength() && index >= 0)
	{
		int strLen = getLength();
		int newStrLen = getLength(str.data);
		int newLen = strLen + newStrLen;
		char* temp = new char[strLen + newStrLen + 1];
		int i = 0, j = 0;
		int k = 0;
		for (i = 0; i < newLen; i++)
		{
			if (i == index)
			{

				for (int j = 0; j < newStrLen; j++)
				{
					temp[i] = str.data[j];
					i++;
				}
				i--;
			}
			else
			{
				temp[i] = data[k];
				k++;
			}
		}
		temp[newLen] = '\0';
		this->~String();
		data = temp;
		size = newLen + 1;
	}
	else
	{
		cout << "Index does not exist";
	}

}
void String::remove(const int index, const int count)
{
	if (index <getLength() && index>-1)
	{
		int len = getLength();
		int i;
		for (i = 0; count + i + index < len; i++)
		{
			data[index + i] = data[count + i + index];
		}

		data[index + i] = '\0';
	}
	else
	{
		cout << "Index does not exist";
	}
}
void String::makeUpper()
{
	if (isEmpty())
		return;
	for (int i = 0; i < getLength(); i++)
	{
		if (data[i] >= 97 && data[i] <= 123)
		{
			data[i] = data[i] - 32;
		}
	}
}
void String::makeLower()
{
	if (isEmpty())
		return;
	for (int i = 0; i < getLength(); i++)
	{
		if (data[i] >= 65 && data[i] <= 91)
		{
			data[i] = data[i] + 32;
		}
	}
}
void String::reverse()
{
	if (data == nullptr || data[0] == '\0')
		return;
	int n = getLength();
	char* temp = new char[n + 1];
	int k = n - 1;
	for (int i = 0; i < n; i++)
	{
		temp[i] = data[k];
		k--;
	}
	temp[n] = '\0';
	this->~String();
	data = temp;
	size = n + 1;
}
void String::trimLeft()
{
	if (isEmpty())
		return;
	int i = 0;
	while (data[i] == '\n' || data[i] == ' ' || data[i] == '\t')
	{
		remove(i);
	}
}
void String::trimRight()
{

	if (isEmpty())
		return;
	int i = getLength() - 1;
	while (data[i] == '\n' || data[i] == ' ' || data[i] == '\t')
	{
		remove(i);
		i--;
	}
}
void String::trim()
{
	trimLeft();
	trimRight();
}
int String::compare(const String s2)const
{
	if (data == nullptr || s2.data == nullptr)
	{
		cout << "invalid string";
		exit(0);
	}
	int str1Len = getLength();
	int str2Len = getLength(s2.data);
	for (int i = 0; i < str1Len && i < str2Len; i++)
	{
		if (data[i] > s2.data[i])
			return 1;
		if (data[i] < s2.data[i])
			return -1;
	}
	if (str1Len == str2Len)
		return 0;
	return str1Len > str2Len ? 1 : -1;

}
String String::left(const int count)
{
	if (isEmpty())
		exit(0);
	char* temp = new char[count + 1];
	for (int i = 0; i < count; i++)
	{
		temp[i] = data[i];
	}
	temp[count] = '\0';
	String newStr{ temp };
	return newStr;
}
String String::right(const int count)
{
	if (isEmpty())
		exit(0);
	char* temp = new char[count + 1];
	int n = getLength();
	int c = 0;
	for (int i = n - count; i < n; i++)
	{
		temp[c] = data[i];
		c++;
	}

	temp[count] = '\0';
	String newStr{ temp };
	return newStr;
}
void String::setNumber(const long long int num)
{
	int count = getNumberLength(num);
	long long int n = num;
	int c;
	char* temp = new char[count + 1];

	for (c = count - 1; c >= 0; c--)
	{
		temp[c] = (n % 10) + 48;
		n = n / 10;

	}
	temp[count] = '\0';
	this->~String();
	data = temp;
	size = count + 1;
}
int String::getNumberLength(long long int n)
{
	if (n == 0)
		return 1;
	int count = 0;
	while ((n % 10) != 0)
	{
		n = n / 10;
		count++;
	}
	return count;
}

String String::concatenate(const String s2)
{
	if (s2.data == nullptr)
	{
		String s{ data };
		return s;
	}
	int str2Len = getLength(s2.data);
	int strLen = getLength();
	char* temp = new char[strLen + str2Len + 1];
	String newStrng{ data };
	newStrng.insert(strLen, s2.data);
	newStrng.data[strLen + str2Len] = '\0';
	newStrng.size = strLen + str2Len + 1;
	return newStrng;
}
void String::concatEqual(const String& s2)
{
	if (s2.data == nullptr || s2.data[0] == '\0')
		return;
	int strLen = getLength();
	int str2Len = getLength(s2.data);
	insert(strLen, s2);
}
long long int String::convertToInteger()const
{
	int i = 0;
	long long int num = 0;
	int c = 10;
	for (i = 0; i < getLength() && data[i] != '.'; i++)
	{
		if (data[i] >= '0' && data[i] <= '9')
		{
			num = (num * c) + (data[i] - 48);

		}
	}
	return num;
}
float String::convertToFloat()const
{
	long long int integralPart = convertToInteger();
	float decimalPart = integralPart;
	float c = 10;
	for (int i = 1; i < getLength(); i++)
	{
		if (data[i - 1] == '.')
		{

			for (; i < getLength(); i++)
			{
				decimalPart = decimalPart + (data[i] - 48) / c;
				c = c * 10;
			}
		}
	}
	return decimalPart;
}