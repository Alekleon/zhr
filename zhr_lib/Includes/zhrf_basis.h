#pragma once

//	If NDEBUG is not defined assert function operates.
//	cmake rules this macro, pure VS doesn't.
//#undef DEBUG
//#undef NDEBUG
//#define DEBUG
//#define NDEBUG
#include <cassert>

#include <iostream>

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

	//	Prefix for most "depricated" C-functions.
#ifdef WIN32
#	define ZHR_DEPR_FUNC(FunctionName) _##FunctionName
#else
#	define ZHR_DEPR_FUNC(FunctionName) FunctionName
#endif

	//	Regardless configuration if Expression is fault we must
	//	write out Message and abort program execution.
#define ZHR_ASSERT(Expression, Message)	(void) (		\
		!!(Expression) || (								\
			std::cerr << (Message),						\
			assert(Expression),							\
			abort(), 0									\
		)												\
	)

	//	Prefix for zhr functions
#define ZHR_FUNC _F_
	//	Prefix for zhr classes
#define ZHR_CLASS _An_
	//	Prefix for zhr enumerations
#define ZHR_ENUM _E_

}	//	namespace ZHR_lib
