#ifndef INCLUDE_MASTER_HEAP_H_
#define INCLUDE_MASTER_HEAP_H_

#include <stdint.h>

/**
 * This structure defines a node in a heap structure.
 */
struct heapNode {
    /** The pointer to the data inside the heap element. */
    void* data;
    /** The position in the array. */
    unsigned int position;
};

/**
 * Initializer for a heap node.
 */
#define HEAP_ELEMENT_INIT { \
    .data     = NULL,       \
    .position = 0,          \
}

/**
 * Initializer for a heap node with a data pointer.
 *
 * @param d The pointer to the data inside the node.
 */
#define HEAP_ELEMENT_INIT_WITH_DATA(d) { \
    .data     = (void*) (d),             \
    .position = 0,                       \
}

/**
 * This structure defines a heap.
 */
struct heap {
    /** The current length of the array. */
    unsigned int length;
    /** The maximum size of the heap. */
    const unsigned int size;
    /** The heap array. */
    struct heapNode** array;
    /** The function that returns ordering value. */
    int32_t (*getValue)(void*);
    /** Whether this is a maximum heap, else it is a minimum heap. */
    const uint8_t isMax : 1;
};

/**
 * Initializer for a minimum heap.
 *
 * @param s The size of the heap array.
 * @param a The array of the heap.
 * @param f The function that weights node.
 */
#define MIN_HEAP_INIT(s,a,f) { \
    .length   = 0,             \
    .size     = s,             \
    .array    = (a),           \
    .getValue = (f),           \
    .isMax    = 0,             \
}

/**
 * Initializer for a maximum heap.
 *
 * @param s The size of the heap array.
 * @param a The array of the heap.
 * @param f The function that weights node.
 */
#define MAX_HEAP_INIT(s,a,f) { \
    .length   = 0,             \
    .size     = s,             \
    .array    = (a),           \
    .getValue = (f),           \
    .isMax    = 1,             \
}

/**
 * This function inserts a node into a minimum heap.
 *
 * @param heap The heap we want to insert a node into.
 * @param node The node we want to insert.
 *
 * @return #NULL if the heap is full, else the inserted node.
 */
struct heapNode* heapMinInsertNode(struct heap* heap, struct heapNode* node);

/**
 * This function inserts a node into a maximum heap.
 *
 * @param heap The heap we want to insert a node into.
 * @param node The node we want to insert.
 *
 * @return #NULL if the heap is full, else the inserted node.
 */
struct heapNode* heapMaxInsertNode(struct heap* heap, struct heapNode* node);

/**
 * This function remove and returns the root node from a minimum heap.
 *
 * @param heap The heap we want to remove a node.
 *
 * @return #NULL if the heap is empty, else the root node.
 */
struct headNode* heapMinDelete(struct heap* heap);

/**
 * This function remove and returns the root node from a maximum heap.
 *
 * @param heap The heap we want to remove a node.
 *
 * @return #NULL if the heap is empty, else the root node.
 */
struct headNode* heapMaxDelete(struct heap* heap);

/**
 * This function updates the position of the node in a minimum heap.
 * 
 * @param heap The heap we want to update a node.
 * @param node The node we want to update.
 *
 * @return #NULL if the node isn't in the heap, the node.
 */
struct heapNode* heapMinUpdateNode(struct heap* heap, struct heapNode* node);

/**
 * This function updates the position of the node in a maximum heap.
 * 
 * @param heap The heap we want to update a node.
 * @param node The node we want to update.
 *
 * @return #NULL if the node isn't in the heap, the node.
 */
struct heapNode* heapMaxUpdateNode(struct heap* heap, struct heapNode* node);

#endif
