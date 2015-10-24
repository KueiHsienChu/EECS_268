#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(const char* msg) : std::runtime_error(msg)
{
}

