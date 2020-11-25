#include "zhrf.h"
#include "zhrf_basis.h"

int main(int vArgc, char * ppArgs[])
{
	zhr_assert (ZHR_lib::TestBasis());
	ZHR_lib::WaitInput();
}