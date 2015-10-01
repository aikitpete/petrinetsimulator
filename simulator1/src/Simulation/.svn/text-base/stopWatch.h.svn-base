#ifndef STOPWATCH
#define STOPWATCH

#if defined(__WIN64__) || defined(WIN64) || defined(__WIN64)
	#include <windows.h>
#elif defined(__WIN32__) || defined(__CYGWIN32__) || defined(WIN32) || defined(__WIN32)
	#include <windows.h>
#elif defined(__UNIX__) || (UNIX)
	#include <sys/time.h>
	#include <stddef.h>
#else
	#error "Unable to detect OS"
#endif

class stopWatch {
private:
#if defined(__WIN64__) || defined(WIN64) || defined(__WIN64)
	LARGE_INTEGER t1, t2, tick;
#elif defined(__WIN32__) || defined(__CYGWIN32__) || defined(WIN32) || defined(__WIN32)
	LARGE_INTEGER t1, t2, tick;
#elif defined(__UNIX__) || (UNIX)
	struct timeval t1, t2;
#else
	#error "Unable to detect OS"
#endif	

	bool running;
    double diffTime;
	double getTime();
	void markTime();

public:
	stopWatch();
	~stopWatch();
	void start(void);
	void stop(void);
	double elapsedTime(void);
};

#endif
