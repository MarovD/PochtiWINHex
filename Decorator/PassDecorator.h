#include <tchar.h>
#include <windows.h>

#include "Decorator.h"

class PassDecorator : public Decorator
{
public:
	PassDecorator(Iterator iterator);
	bool GetCurrent(byte *dataBuffer) override;

};



