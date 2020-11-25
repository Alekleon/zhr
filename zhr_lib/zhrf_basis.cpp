#include "zhrf_basis.h"

#include <cassert>
#include <iostream>

#include <limits.h>

namespace ZHR_lib
{

	//	Just dully awaits for an user to press 'Enter'.
	void WaitInput(bool vToNotify, const std::string& vMessage)
	{
		if (vToNotify) {
			std::cout << vMessage;
		}
		std::cin.ignore();
	}

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

	//	Last text error in methods of object.
	std::string AnZHRClass::LastError() const
	{
		return MError;
	}

	bool TestBasis()
	{
		return TestWaitInput();
	}

	bool TestWaitInput()
	{
		ZHR_lib::WaitInput(FALSE);
		ZHR_lib::WaitInput();
		ZHR_lib::WaitInput();
		ZHR_lib::WaitInput(TRUE, "dfsdfdfsdf");
		ZHR_lib::WaitInput(TRUE, std::string("asdfasdf"));
		return TRUE;
	}

}	//	namespace ZHR_lib

