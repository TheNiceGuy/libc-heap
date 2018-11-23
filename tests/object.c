#include "object.h"

int32_t getValue(void* data) {
    struct object* obj = (struct object*) data;

#ifdef TEST_MIN_HEAP
    return  obj->content;
#endif

#ifdef TEST_MAX_HEAP
    return -obj->content;
#endif
}
