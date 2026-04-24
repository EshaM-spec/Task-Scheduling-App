#ifndef STRING_H
#define STRING_H
class String
{

	char* data;
	int size;
	int getNumberLength(long long int n);
	int getLength(const char* c)const;
public:

	String(const String&);
	String();
	String(const char c);
	String(const char* c);
	~String();
	void reSize(int newSize);
	void input();
	bool isEmpty()const;
	int getLength()const;
	int getSize()const;
	void display()const;
	void shrink();
	int find(const String subStr, const int start = 0)const;
	void insert(const int index, const String str);
	void remove(const int index, const int count = 1);
	int replace(const String old, const String newSubStr);
	void makeUpper();
	void makeLower();
	void setNumber(const long long int num);
	void reverse();
	void trimLeft();
	void trimRight();
	void trim();
	int compare(const String s2)const;
	char& at(const int index);
	const char& at(const int index)const;
	String left(const int count);
	String right(const int count);
	String concatenate(const String s2);
	void concatEqual(const String& s2);
	long long int convertToInteger()const;
	float convertToFloat()const;
};
#endif