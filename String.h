/*************************************************************************
AlienKeeper Source File.
Copyright (C), AlienKeeper, 2024.
**************************************************************************/

#pragma once

class String
{
public:
	String();
	String(const char* zStr);
	String(const String& str);
	String(String&& str);
	virtual ~String();

	String& operator = (const String& str)
	{
		//TODO;
		return *this;
	};
	
	String& operator += (const String& str)
	{
		//TODO;
		return *this;
	};

	bool append(const char* zStr);
	bool compare(const char* zStr) const;
	bool empty() const;
	bool push_back(char ch);
	bool push_front(char ch);
	bool pop_back(char ch);
	bool pop_front(char ch);
	const char* c_str() const;
	int  length() const;

private:
	char* m_storage[];
};