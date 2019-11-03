#include "Clock.h"
#include "Windows.h"
using namespace df;


Clock::Clock() {
	SYSTEMTIME current;
	GetSystemTime(&current);

	//set to current time in milliseconds
	m_previous_time = (current.wMinute * 60 * 1000000) + (current.wSecond * 1000000) + (current.wMilliseconds * 1000);

}

//reset previous time
long int Clock::delta() {
	//GetSystemTime(); //fills a systemTime structure with number of minutes, seconds, milliseconds
	//system time before in this case is previous_time 

	SYSTEMTIME after_delta;

	GetSystemTime(&after_delta); //get current time

	long int after_delta_msec = (after_delta.wMinute * 60 * 1000000) + (after_delta.wSecond * 1000000) + (after_delta.wMilliseconds * 1000);
	long int elapsedTime = after_delta_msec - m_previous_time;
	m_previous_time = after_delta_msec;

	if (elapsedTime < 0) {
		return -1;
	}
	else {
		return elapsedTime;
	}
	


}

//doesn't reset previous time
long int Clock::split() const{

	SYSTEMTIME after_delta;

	GetSystemTime(&after_delta); //get current time

	long int after_delta_msec = (after_delta.wMinute * 60 * 1000000) + (after_delta.wSecond * 1000000) + (after_delta.wMilliseconds * 1000);
	long int elapsedTime = after_delta_msec - m_previous_time;

	if (elapsedTime < 0) {
		return -1;
	}
	else {
		return elapsedTime;
	}
}
