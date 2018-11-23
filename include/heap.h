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
    unsigned int size;
    /** The heap array. */
    struct heapNode** array;
    /** The function that returns ordering value. */
    int32_t (*getValue)(void*);
    /** Whether this is a maximum heap, else it is a minimum heap. */
    uint8_t isMax : 1;
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
#ifdef NOT_DEFINED
/**
 * This macro returns the index of the parent of a node.
 *
 * @param The node which we want the parent index.
 */
#define heapGetParentIndex(n) ((n)->position/2)

/**
 * This macro returns the index of the left child of a node.
 *
 * @param The node which we want the left child index.
 */
#define heapGetLeftChildIndex(n) (2*(n)->position)

/**
 * This macro returns the index of the right child of a node.
 *
 * @param The node which we want the right child index.
 */
#define heapGetRightChildIndex(n) (2*(n)->position+1)

/**
 * This function swaps two nodes in the heap.
 *
 * @param heap  The pointer to the heap structure.
 * @param node1 The pointer to the first heap node to swap.
 * @param node2 The pointer to the second heap node to swap.
 */
void heapSwap(struct heap* heap, struct heapNode* node1, struct heapNode* node2);

/**
 * This macro swaps a node with its parent.
 *
 * @param h The pointer to the heap structure.
 * @param n The pointer to the node we want to swap with its parent.
 */
#define heapSwapParent(h,n) {                             \
    int index = heapGetParentIndex(n);                    \
    if(index != 0) heapSwap((h), (n), (h)->array[index]); \
}

/**
 * This macro swaps a node with its left child.
 *
 * @param h The pointer to the heap structure.
 * @param n The pointer to the node we want to swap with its left child.
 */
#define heapSwapLeftChild(h,n) {                                 \
    int index = heapGetLeftChildIndex((n));                      \
    if(index < (h)->size) heapSwap((h), (n), (h)->array[index]); \
}

/**
 * This macro swaps a node with its right child.
 *
 * @param h The pointer to the heap structure.
 * @param n The pointer to the node we want to swap with its right child.
 */
#define heapSwapRightChild(h,n) {                                \
    int index = heapGetRightChildIndex((n));                     \
    if(index < (h)->size) heapSwap((h), (n), (h)->array[index]); \
}

/**
 * This function updates the position of a node in the heap. It should be
 * called when the content of the data in the heap node has changed.
 *
 * @param heap The pointer to the heap structure.
 * @param node The pointer to the node to update.
 */
struct heapNode* heapUpdateNode(struct heap* heap, struct heapNode* node);
/**
 * This function inserts a node into the heap. The position of the heap node
 * should be zero. The node shouldn't already be a heap.
 *
 * @param heap The pointer to the heap structure.
 * @param node The pointer to the node to insert.
 */
#endif

struct heapNode* heapMinInsertNode(struct heap* heap, struct heapNode* node);

struct headNode* heapDelete(struct heap* heap);

#endif
