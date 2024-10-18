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

	String& operator = (const String& other)
	{
		if (this == &other)
			return *this;

		clear();

		m_storage = new char[other.length()];

		char* pMyBegin = this->m_storage;
		const char* pOtherBegin = other.c_str();

		for (; *pOtherBegin != 0; pOtherBegin++, pMyBegin++)
		{
			*pMyBegin = *pOtherBegin;
		}

		*pMyBegin = 0;

		return *this;
	};
	
	String& operator += (const String& other)
	{
		const int myLen = this->length();
		const int otherLen = other.length();

		char* resizedStorage = new char[myLen + otherLen];
		char* pResizedBegin = resizedStorage;
		char* pMyBegin = m_storage;
		const char* pOtherBegin = other.c_str();

		// Добавили текущие символы
		for (; *pMyBegin != 0; pMyBegin++, pResizedBegin++)
			*pResizedBegin = *pMyBegin;

		// Добавили новые символы
		for (; *pOtherBegin != 0; pOtherBegin++, pResizedBegin++)
			*pResizedBegin = *pOtherBegin;

		// 0 - терминатор
		*pResizedBegin = 0;

		clear();
		m_storage = resizedStorage;

		return *this;
	};

	bool operator == (const String& other)
	{
		const int myLen = this->length();
		const int otherLen = other.length();

		if (myLen != otherLen)
			return false;

		char* pMyBegin = m_storage;
		const char* pOtherBegin = other.c_str();

		for (int i = 0; i < otherLen; i++, pMyBegin++, pOtherBegin++)
		{
			if (*pMyBegin != *pOtherBegin)
				return false;
		}

		return true;
	};	
	
	operator const char*()
	{
		return m_storage;
	};

	bool clear();
	bool empty() const;
	const char* c_str() const;

	/// @brief Получить длину без учета 0-терминатора
	int  length() const;

private:
	char* m_storage;
};

inline String operator + (const String& str1, const String& str2)
{
	const int str1Len = str1.length();
	const int str2Len = str2.length();

	char* resizedStorage = new char[str1Len + str2Len + 1];
	char* pResizedBegin = resizedStorage;

	const char* pStr1Begin = str1.c_str();
	const char* pStr2Begin = str2.c_str();

	// Добавили текущие символы
	for (; *pStr1Begin != 0; pStr1Begin++, pResizedBegin++)
		*pResizedBegin = *pStr1Begin;

	// Добавили новые символы
	for (; *pStr2Begin != 0; pStr2Begin++, pResizedBegin++)
		*pResizedBegin = *pStr2Begin;

	// 0 - терминатор
	*pResizedBegin = 0;

	return resizedStorage;
};