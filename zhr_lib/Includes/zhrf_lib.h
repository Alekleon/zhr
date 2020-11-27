#pragma once

#include "zhrf_basis.h"

namespace ZHR_lib
{

	///////////////////////////////////////////////////////////////////////////
	//	ALL SORTS OF THINGS

	//	Just dully awaits for the user to press 'Enter'.
	void WaitInput(bool vToNotify = TRUE, const std::string& rMessage = "Please press 'Enter' to continue...");

	//	ALL SORTS OF THINGS
	///////////////////////////////////////////////////////////////////////////

	class AnZHRClass {

	protected:
		std::string MError = "";
	public:
		//	Last text error in methods of object.
		std::string LastError() const;

	};	//	class AnZHRClass

	bool TestWaitInput();
	bool TestErrors();
	bool TestBasis();

}	//	namespace ZHR_lib