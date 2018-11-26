#include <assert.h>
#include <stdlib.h>
#include <heap.h>
#include "object.h"

#define HEAP_SIZE 8

struct heapNode* array[HEAP_SIZE] = {[0 ... HEAP_SIZE-1] = NULL};
struct heap heap = TEST_HEAP_INIT(HEAP_SIZE, array, &compare);

int main() {
    /* insert a node, initial placement */
    struct object obj1 = {.content = 10};
    struct heapNode node1 = HEAP_ELEMENT_INIT_WITH_DATA(&obj1);
    assert(heapInsertNode(&heap, &node1) != NULL);
    assert(heapInsertNode(&heap, &node1) == NULL);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &node1);
    assert(heap.array[2] == NULL);
    assert(heap.array[3] == NULL);
    assert(heap.array[4] == NULL);
    assert(heap.array[5] == NULL);
    assert(heap.array[6] == NULL);
    assert(heap.array[7] == NULL);
    assert(heap.array[1]->position == 1);
    assert(heap.length == 1);

    /* insert a node, no percolate up */
    struct object obj2 = {.content = 15};
    struct heapNode node2 = HEAP_ELEMENT_INIT_WITH_DATA(&obj2);
    assert(heapInsertNode(&heap, &node2) != NULL);
    assert(heapInsertNode(&heap, &node2) == NULL);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &node1);
    assert(heap.array[2] == &node2);
    assert(heap.array[3] == NULL);
    assert(heap.array[4] == NULL);
    assert(heap.array[5] == NULL);
    assert(heap.array[6] == NULL);
    assert(heap.array[7] == NULL);
    assert(heap.array[1]->position == 1);
    assert(heap.array[2]->position == 2);
    assert(heap.length == 2);

    /* insert a node, percolate all the way up */
    struct object obj3 = {.content = 5};
    struct heapNode node3 = HEAP_ELEMENT_INIT_WITH_DATA(&obj3);
    assert(heapInsertNode(&heap, &node3) != NULL);
    assert(heapInsertNode(&heap, &node3) == NULL);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &node3);
    assert(heap.array[2] == &node2);
    assert(heap.array[3] == &node1);
    assert(heap.array[4] == NULL);
    assert(heap.array[5] == NULL);
    assert(heap.array[6] == NULL);
    assert(heap.array[7] == NULL);
    assert(heap.array[1]->position == 1);
    assert(heap.array[2]->position == 2);
    assert(heap.array[3]->position == 3);
    assert(heap.length == 3);

    /* insert a node, no percolate up */
    struct object obj4 = {.content = 20};
    struct heapNode node4 = HEAP_ELEMENT_INIT_WITH_DATA(&obj4);
    assert(heapInsertNode(&heap, &node4) != NULL);
    assert(heapInsertNode(&heap, &node4) == NULL);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &node3);
    assert(heap.array[2] == &node2);
    assert(heap.array[3] == &node1);
    assert(heap.array[4] == &node4);
    assert(heap.array[5] == NULL);
    assert(heap.array[6] == NULL);
    assert(heap.array[7] == NULL);
    assert(heap.array[1]->position == 1);
    assert(heap.array[2]->position == 2);
    assert(heap.array[3]->position == 3);
    assert(heap.array[4]->position == 4);
    assert(heap.length == 4);

    /* insert a node, percolate up from right child */
    struct object obj5 = {.content = 12};
    struct heapNode node5 = HEAP_ELEMENT_INIT_WITH_DATA(&obj5);
    assert(heapInsertNode(&heap, &node5) != NULL);
    assert(heapInsertNode(&heap, &node5) == NULL);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &node3);
    assert(heap.array[2] == &node5);
    assert(heap.array[3] == &node1);
    assert(heap.array[4] == &node4);
    assert(heap.array[5] == &node2);
    assert(heap.array[6] == NULL);
    assert(heap.array[7] == NULL);
    assert(heap.array[1]->position == 1);
    assert(heap.array[2]->position == 2);
    assert(heap.array[3]->position == 3);
    assert(heap.array[4]->position == 4);
    assert(heap.array[5]->position == 5);
    assert(heap.length == 5);

    /* insert a node, percolate up from left child */
    struct object obj6 = {.content = 8};
    struct heapNode node6 = HEAP_ELEMENT_INIT_WITH_DATA(&obj6);
    assert(heapInsertNode(&heap, &node6) != NULL);
    assert(heapInsertNode(&heap, &node6) == NULL);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &node3);
    assert(heap.array[2] == &node5);
    assert(heap.array[3] == &node6);
    assert(heap.array[4] == &node4);
    assert(heap.array[5] == &node2);
    assert(heap.array[6] == &node1);
    assert(heap.array[7] == NULL);
    assert(heap.array[1]->position == 1);
    assert(heap.array[2]->position == 2);
    assert(heap.array[3]->position == 3);
    assert(heap.array[4]->position == 4);
    assert(heap.array[5]->position == 5);
    assert(heap.array[6]->position == 6);
    assert(heap.length == 6);

    /* insert a node, no percolate up */
    struct object obj7 = {.content = 20};
    struct heapNode node7 = HEAP_ELEMENT_INIT_WITH_DATA(&obj7);
    assert(heapInsertNode(&heap, &node7) != NULL);
    assert(heapInsertNode(&heap, &node7) == NULL);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &node3);
    assert(heap.array[2] == &node5);
    assert(heap.array[3] == &node6);
    assert(heap.array[4] == &node4);
    assert(heap.array[5] == &node2);
    assert(heap.array[6] == &node1);
    assert(heap.array[7] == &node7);
    assert(heap.array[1]->position == 1);
    assert(heap.array[2]->position == 2);
    assert(heap.array[3]->position == 3);
    assert(heap.array[4]->position == 4);
    assert(heap.array[5]->position == 5);
    assert(heap.array[6]->position == 6);
    assert(heap.array[7]->position == 7);
    assert(heap.length == 7);

    /* insert a node, heap is full */
    struct object obj8 = {.content = 40};
    struct heapNode node8 = HEAP_ELEMENT_INIT_WITH_DATA(&obj8);
    assert(heapInsertNode(&heap, &node8) == NULL);
    assert(heapInsertNode(&heap, &node8) == NULL);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &node3);
    assert(heap.array[2] == &node5);
    assert(heap.array[3] == &node6);
    assert(heap.array[4] == &node4);
    assert(heap.array[5] == &node2);
    assert(heap.array[6] == &node1);
    assert(heap.array[7] == &node7);
    assert(heap.array[1]->position == 1);
    assert(heap.array[2]->position == 2);
    assert(heap.array[3]->position == 3);
    assert(heap.array[4]->position == 4);
    assert(heap.array[5]->position == 5);
    assert(heap.array[6]->position == 6);
    assert(heap.array[7]->position == 7);
    assert(heap.length == 7);

    return 0;
}
