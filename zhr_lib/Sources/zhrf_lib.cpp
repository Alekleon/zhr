#include "zhrf_lib.h"

namespace ZHR_lib
{

	//	Just dully awaits for an user to press 'Enter'.
	void _Fn_WaitInput(bool vToNotify, const std::string& vMessage)
	{
		if (vToNotify) {
			std::cout << vMessage;
		}
		std::cin.ignore();
	}

	//	Last text error in methods of object.
	std::string _An_ZHRClass::LastError() const
	{
		return MError;
	}

	bool TestWaitInput()
	{
		_Fn_WaitInput(FALSE);
		_Fn_WaitInput();
		_Fn_WaitInput();
		_Fn_WaitInput(TRUE, "dfsdfdfsdf");
		_Fn_WaitInput(TRUE, std::string("asdfasdf"));
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