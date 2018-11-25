#ifndef INCLUDE_TESTS_HEAP_OBJECT_
#define INCLUDE_TESTS_HEAP_OBJECT_

#include <stdint.h>
#include <heap.h>

struct object {
    int32_t content;
};

uint8_t compare(void* data1, void* data2);

struct heapNode* heapMinInsertNode(struct heap* heap, struct heapNode* node);
void heapMinPercolateDown(struct heap* heap, unsigned int hole);
struct heapNode* heapMinDeleteNode(struct heap* heap);
struct heapNode* heapMinUpdateNode(struct heap* heap, struct heapNode* node);

struct heapNode* heapMaxInsertNode(struct heap* heap, struct heapNode* node);
void heapMaxPercolateDown(struct heap* heap, unsigned int hole);
struct heapNode* heapMaxDeleteNode(struct heap* heap);
struct heapNode* heapMaxUpdateNode(struct heap* heap, struct heapNode* node);

#if defined TEST_MIN_HEAP && defined TEST_MAX_HEAP
    #error Both TEST_MIN_HEAP and TEST_MAX_HEAP are defined
#endif

#ifdef TEST_MIN_HEAP
    #define TEST_HEAP_INIT    MIN_HEAP_INIT
    #define heapInsertNode    heapMinInsertNode
    #define heapPercolateDown heapMinPercolateDown
    #define heapDeleteNode    heapMinDeleteNode
    #define heapUpdateNode    heapMinUpdateNode
#endif

#ifdef TEST_MAX_HEAP
    #define TEST_HEAP_INIT    MAX_HEAP_INIT
    #define heapInsertNode    heapMaxInsertNode
    #define heapPercolateDown heapMaxPercolateDown
    #define heapDeleteNode    heapMaxDeleteNode
    #define heapUpdateNode    heapMaxUpdateNode
#endif

#endif

