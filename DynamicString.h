#pragma once

#include <string>

std::string::append();

class CDynamicString
{
public:
	CDynamicString();
	CDynamicString(const char* zStr);
	virtual ~CDynamicString();

	bool append(const char* zStr);

private:
	char** m_storage[];
};