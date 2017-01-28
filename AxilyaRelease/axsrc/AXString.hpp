#ifndef AXString_hpp
#define AXString_hpp
#include "emmintrin.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
class AXString{
private:
	__m128i* str;
	int maxSize;
	bool allocated;
public:
	AXString();
	AXString(char*);
	const char* cstr();
	bool compare(const char*);

};
#endif