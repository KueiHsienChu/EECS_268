#ifndef PVE
#define PVE
#include <stdexcept>

class PreconditionViolationException : public std::runtime_error
{
	public:
		PreconditionViolationException(const char* msg);
};

#endif
