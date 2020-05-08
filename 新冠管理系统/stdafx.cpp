// stdafx.cpp : 只包括标准包含文件的源文件
// 软件小组.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用

void gettime(string& str)
{
	time_t rawtime;
	struct tm ptminfo;
	time(&rawtime);
	localtime_s(&ptminfo, &rawtime);
	stringstream sstr;
	sstr << "时间：" << setfill('0') << setw(2) << ptminfo.tm_year + 1900 << "-" << setfill('0') << setw(2) << ptminfo.tm_mon + 1 << "-" << setfill('0') << setw(2) << ptminfo.tm_mday
		<< " " << setfill('0') << setw(2) << ptminfo.tm_hour << ":" << setfill('0') << setw(2) << ptminfo.tm_min << ":" << setfill('0') << setw(2) << ptminfo.tm_sec << "	";

	str = sstr.str();
}
