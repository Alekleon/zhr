#include "zhrf_lib.h"

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

	//	Last text error in methods of object.
	std::string AnZHRClass::LastError() const
	{
		return MError;
	}

	bool TestWaitInput()
	{
		WaitInput(FALSE);
		WaitInput();
		WaitInput();
		WaitInput(TRUE, "dfsdfdfsdf");
		WaitInput(TRUE, std::string("asdfasdf"));
		return TRUE;
	}
	bool TestErrors()
	{
		//		std::cerr << ZHR_FUNC(strerror)(636);
		//		std::cerr << strerror_s(676,;
		errno = 1;
		::perror("DDDRRR: ");
		::perror("rrrttt: \n");
		return TRUE;
	}

	bool TestBasis()
	{
		bool Result = TRUE;
		//		if (TestWaitInput() == FALSE) {
		//			Result = FALSE;
		//		}
		if (TestErrors() == FALSE) {
			Result = FALSE;
		}
		return Result;
	}

}	//	namespace ZHR_lib