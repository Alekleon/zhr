#include "zhrf_basis.h"

#include <cassert>
#include <iostream>

namespace ZHR_lib
{
/*
	//	Write out an vrError. If vToAssert tries to assert.
	void Assert(const std::string & vrError, bool vToAssert)
	{
		if (vrError.empty() == FALSE)
			std::cerr << vrError << std::endl;
		if (vToAssert == TRUE)
			assert(FALSE);
	}

	//	Write out an vrError. If vToFail makes program failure.
	void Fail(const std::string& vrError, bool vToFail)
	{
		if (vrError.empty() == FALSE)
			std::cerr << vrError << std::endl;
		if (vToFail == TRUE)
			assert(FALSE);
	}
	*/

	//	Just dully awaits any user's keyboard answer (Enter, f.i.)
	void WaitInput()
	{
		std::string TempStr;
		std::getline(std::cin, TempStr);
	}

	//	Last text error in methods of object.
	std::string AnZHRClass::LastError() const
	{
		return MError;
	}

}	//	namespace ZHR_lib

