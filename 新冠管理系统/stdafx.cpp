// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// ���С��.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

// TODO: �� STDAFX.H �������κ�����ĸ���ͷ�ļ���
//�������ڴ��ļ�������

void gettime(string& str)
{
	time_t rawtime;
	struct tm ptminfo;
	time(&rawtime);
	localtime_s(&ptminfo, &rawtime);
	stringstream sstr;
	sstr << "ʱ�䣺" << setfill('0') << setw(2) << ptminfo.tm_year + 1900 << "-" << setfill('0') << setw(2) << ptminfo.tm_mon + 1 << "-" << setfill('0') << setw(2) << ptminfo.tm_mday
		<< " " << setfill('0') << setw(2) << ptminfo.tm_hour << ":" << setfill('0') << setw(2) << ptminfo.tm_min << ":" << setfill('0') << setw(2) << ptminfo.tm_sec << "	";

	str = sstr.str();
}
