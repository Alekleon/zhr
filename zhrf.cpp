#include "zhrf.h"
#include "zhrf_basis.h"

#include <iostream>
#include <cassert>

int main(int vArgc, char * ppArgs[])
{
	ZHR_lib::AnZHRClass QQQ;
	zhr_assert(QQQ.LastError().empty() == FALSE);
	ZHR_lib::WaitInput();
}