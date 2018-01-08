#pragma once
#include "Dialog2.h"
// CMySocket ÃüÁîÄ¿±ê

class CMySocket : public CAsyncSocket
{
public:
	CMySocket();
	virtual ~CMySocket();
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
};


