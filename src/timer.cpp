/*
 *
 * Este archivo pertenece al proyecto 'proyecto3',
 * creado por José Manuel De Torres Domínguez.
 *
 *
 */
/*
 * time.cpp
 *
 *  Created on: 6 de feb. de 2017
 *      Author: jarico
 */

#include "timer.h"
#include <time.h>


#ifdef __MACH__

#include <mach/mach_time.h>
#include <sys/time.h>
#define ORWL_NANO (+1.0E-9)
#define ORWL_GIGA UINT64_C(1000000000)

static double orwl_timebase = 0.0;
static uint64_t orwl_timestart = 0;

 double Timer::getTime (void) {

	if (!orwl_timestart) {
		mach_timebase_info_data_t tb = { 0 };
		mach_timebase_info(&tb);
		orwl_timebase = tb.numer;
		orwl_timebase /= tb.denom;
		orwl_timestart = mach_absolute_time();
	}
	struct timespec t;
	double diff = (mach_absolute_time() - orwl_timestart) * orwl_timebase;
	t.tv_sec = diff * ORWL_NANO;
	t.tv_nsec = diff - (t.tv_sec * ORWL_GIGA);

	return ((double) t.tv_sec + 1.0e-9
			* (double) t.tv_nsec);
}

#elif _WIN32

#include <windows.h>
//#include <time.h>
double Timer::getTime (void) {
   //return (double)clock() / (double)CLOCKS_PER_SEC;
	LARGE_INTEGER tick;
	LARGE_INTEGER Frequency;

	QueryPerformanceFrequency(&Frequency); 
	QueryPerformanceCounter(&tick);

	double t = static_cast<double>(tick.QuadPart) / Frequency.QuadPart;
	return (double)t;
}

#else

 double Timer::getTime (void) {

	struct timespec t;

	clock_gettime(CLOCK_REALTIME, &t);

	return ((double) t.tv_sec + 1.0e-9 * (double) t.tv_nsec);
}

#endif

 /*
  *
  * Este archivo pertenece al proyecto 'proyecto3',
  * creado por José Manuel De Torres Domínguez.
  *
  *
  */


