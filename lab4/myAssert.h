
#pragma once

#ifndef _ASSERT_H_INCLUDED_
#define _ASSERT_H_INCLUDED_

extern void _assert_failed (const char *assertion, const char *file, unsigned int line);

#ifdef NDEBUG
#	define myAssert(expr)	(void (0))
#else
#	define myAssert(x)   ((x)?((void) 0):_assert_failed (#x, __FILE__, __LINE__))
#endif

#endif // _ASSERT_H_INCLUDED_

