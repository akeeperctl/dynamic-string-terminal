/*************************************************************************
AlienKeeper Source File.
Copyright (C), AlienKeeper, 2024.
**************************************************************************/

#include "String.h"
#include "cstrings_library.h"

String::String()
	: m_storage(nullptr)
{
}

String::String(const char* zStr)
	: m_storage(nullptr)
{
	int len = cstrings::len(zStr);
	char* pBegin = m_storage = new char[len];

	for (const char* pInputBegin = zStr; *pInputBegin != 0; pInputBegin++, pBegin++)
	{
		*pBegin = *pInputBegin;
	}

	*pBegin = 0;
}

String::String(const String& str)
	: m_storage(nullptr)
{
	char* pBegin = m_storage = new char[str.length() + 1];
	const char* pInputBegin = str.m_storage;

	for (; *pInputBegin != 0; pInputBegin++, pBegin++)
	{
		*pBegin = *pInputBegin;
	}

	*pBegin = 0;
}

String::String(String&& other)
{
	m_storage = other.m_storage;
	other.m_storage = nullptr;
}

String::~String()
{
	clear();
}

const char* String::c_str() const
{
	return m_storage;
}

String& String::to_lower()
{
	for (char* pBegin = m_storage; *pBegin != 0; pBegin++)
	{
		*pBegin = cstrings::lower(*pBegin);
	}

	return *this;
}

int String::length() const
{
	int len = 0;
	const char* pBegin = m_storage;

	if (pBegin == nullptr)
		return len;

	// Если нуль-терминатор в начале строки, то длина строки равна 0
	if (*pBegin == 0)
		return 0;

	for (; *pBegin != 0; pBegin++)
		len++;

	return len;
}

int String::compare(const String& other) const
{
	// проверка nullptr 
	if (m_storage == nullptr && other.m_storage == nullptr)
	{
		return 0; // одинаковые
	}
	else if (m_storage == nullptr)
	{
		return -1; // this меньше чем other
	}
	else if (other.m_storage == nullptr)
	{
		return 1; // this больше чем other
	}

	// проверка больше/меньше от начала до конца строки
	const char* pMyBegin = m_storage;
	const char* pOtherBegin = other.m_storage;

	for (; *pMyBegin != 0 && *pOtherBegin != 0; pMyBegin++, pOtherBegin++)
	{
		const char char1 = cstrings::lower(*pMyBegin);
		const char char2 = cstrings::lower(*pOtherBegin);

		if (char1 < char2)
		{
			return -1; // номер символа в this меньше чем в other
		}
		else if (char1 > char2)
		{
			return 1; // номер символа в this больше чем в other
		}
	}

	return 0;

	// проверка разницы размера строк
	//if (*pMyBegin == 0 && *pOtherBegin == 0)
	//{
	//	return 0; // одинаковые
	//}
	//else if (*pMyBegin == 0)
	//{
	//	return -1; // this меньше чем other
	//}	
	//else if (*pOtherBegin == 0)
	//{
	//	return 1; // this больше чем other
	//}
}

bool String::clear()
{
	if (m_storage != nullptr)
	{
		delete[] m_storage;
		m_storage = nullptr;
	}

	return true;
}

bool String::empty() const
{
	return length() <= 0;
}
