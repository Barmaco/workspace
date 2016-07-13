#pragma once

#include "../src/extension.h"
#include "pthread.h"

class NetDelegate : public extension::ServerNetDelegate
{
public:
	SINGLE_DELEGATE_INSTANCE_FUNC(NetDelegate);
private:
	NetDelegate();
	virtual ~NetDelegate();

public:
	virtual void onMessageReceived(SOCKET st, extension::Buffer& buffer);
};

