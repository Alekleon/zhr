#include "zhrf.h"
#include "zhrf_lib.h"

int main(int vArgc, char * ppArgs[])
{
	ZHR_ASSERT (ZHR_lib::TestBasis(), "Tests failed...\n");
	ZHR_lib::_Fn_WaitInput();
}