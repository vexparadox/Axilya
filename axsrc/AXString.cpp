#include "AXString.hpp"

AXString::AXString(): allocated(false), str(nullptr){
	str = (__m128i*)calloc(32, 128);
	if(str){
		allocated = true;
		maxSize = 32*128;
	}
	puts((char*)str);
}

AXString::AXString(char* str1){
	if(str1 != nullptr){
		memcpy(str, str1, strlen(str1)+1);
		allocated = true;
	}
	puts((char*)str);
}

bool AXString::compare(const char* str1){
	if(!allocated || str1 == nullptr){
		return false;
	}
	if(strlen(str1) > maxSize){
		return false;
	}
	for(int i = 0; i < maxSize; i ++){

	}
	// __m128i result = _mm_cmpeq_epi8 (, b);
	//compare and return
	return false;
}

//on assignment
//copy to new bucket of 128 bits arrays 