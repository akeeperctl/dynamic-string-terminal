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
	char* pBegin = m_storage = new char[str.length()];
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

	if (*pBegin == 0)
		len++;

	return len;
}

bool String::clear()
{
	if (m_storage != nullptr)
	{
		delete m_storage;
		m_storage = nullptr;
	}

	return true;
}

bool String::empty() const
{
	return length() <= 0;
}
