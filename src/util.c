#include "build-lisp.h"

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

_Noreturn void _error(const char *file, lint line, const char *fmt, ...) {
	fprintf(stderr, "ERROR! %s:%lld: ", file, line);

	va_list args;
	va_start(args, fmt);

	vfprintf(stderr, fmt, args);

	fputc('\n', stderr);

	va_end(args);

	exit(1);
}
