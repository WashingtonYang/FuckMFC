#pragma once
#include "Add.h"
class File
{
public:
	File(void);
	~File(void);
	struct member{
	CString C_Number;
	CString C_Name;
	CString C_IDNumber;
	CString C_Sex;
	CString C_Grade;
	CString C_Time;
	CString C_Hobby;
	};
	void WriteFile(void);
};

