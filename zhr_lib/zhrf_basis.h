
#pragma once

#include <string>

#ifdef TRUE 
#	undef TRUE
#endif
#ifdef FALSE 
#	undef FALSE
#endif
#define	TRUE	true
#define FALSE	false

namespace ZHR_lib
{

#define zhr_assert(expression) assert (expression)
	/*
#define zhr_assert(expression) (void)(														\
            (!!(expression))	||															\
            (	_wassert(_CRT_WIDE(#expression), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)),\
				abort(), 0																	\
			)																				\
	)

	//	Write out an vrError. If vToAssert tries to assert.
	void Assert(const std::string& vrError, bool vToAssert = FALSE);

	//	Write out an vrError. If vToFail makes program failure.
	void Fail(const std::string & vrError, bool vToFail = FALSE);
	*/

	//	Just dully awaits any user's keyboard answer ('Enter', f.i.)
	void WaitInput();

	class AnZHRClass {

	protected:
		std::string MError = "";
	public:
		//	Last text error in methods of object.
		std::string LastError() const;

	};	//	class AnZHRClass

}	//	namespace ZHR_lib
