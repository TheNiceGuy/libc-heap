#include "object.h"

uint8_t compare(void* data1, void* data2) {
    struct object* obj1 = (struct object*) data1;
    struct object* obj2 = (struct object*) data2;

#ifdef TEST_MIN_HEAP
    return (( obj1->content) < ( obj2->content)) ? 1 : 0;
#endif

#ifdef TEST_MAX_HEAP
    return ((-obj1->content) > (-obj2->content)) ? 1 : 0;
#endif
}
