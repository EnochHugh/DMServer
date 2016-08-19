#pragma once
#include "amqpcpp/include/message.h"
#include "DMServiceHandle.h"
#include "DMRouter.h"

//服务框架为集中控制式，service是集中控制器。

class DMService
{
public:
	virtual int init()=0;

    virtual void dispatch(DMMessage& message) { _router->send(message); };
    
    virtual void publish(DMMessage& message) { _router->publish(message); };

    virtual void receive(const AMQP::Message &message);
	
	virtual void stop(int reason) {};

	void setHandle(DMServiceHandle* handle) { _handle = handle; };
	void setRouter(DMRouter* router) { _router = router; };
protected:
	virtual void onStart(int reason) {};

	DMServiceHandle* _handle;
	DMRouter* _router;
};
