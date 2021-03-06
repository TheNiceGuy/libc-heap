#include <assert.h>
#include <stdlib.h>
#include <heap.h>
#include "object.h"

#define HEAP_SIZE 8

struct object objects[HEAP_SIZE];
struct heapNode nodes[HEAP_SIZE];
struct heapNode* array[HEAP_SIZE] = {[0 ... HEAP_SIZE-1] = NULL};
struct heap heap = TEST_HEAP_INIT(HEAP_SIZE, array, &compare);

int main() {
    /* create a heap */
    for(int i = 1; i < HEAP_SIZE; i++) {
        nodes[i].data = (void*) &objects[i];
        objects[i].content = i;
        heapInsertNode(&heap, &nodes[i]);
    }

    /* make sure heap was correctly created */
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &nodes[1]);
    assert(heap.array[2] == &nodes[2]);
    assert(heap.array[3] == &nodes[3]);
    assert(heap.array[4] == &nodes[4]);
    assert(heap.array[5] == &nodes[5]);
    assert(heap.array[6] == &nodes[6]);
    assert(heap.array[7] == &nodes[7]);
    assert(heap.array[1]->position == 1);
    assert(heap.array[2]->position == 2);
    assert(heap.array[3]->position == 3);
    assert(heap.array[4]->position == 4);
    assert(heap.array[5]->position == 5);
    assert(heap.array[6]->position == 6);
    assert(heap.array[7]->position == 7);
    assert(heap.length == 7);

    /* percolate root a single level */
    objects[1].content = 3;
    heapPercolateDown(&heap, 1);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &nodes[2]);
    assert(heap.array[2] == &nodes[1]);
    assert(heap.array[3] == &nodes[3]);
    assert(heap.array[4] == &nodes[4]);
    assert(heap.array[5] == &nodes[5]);
    assert(heap.array[6] == &nodes[6]);
    assert(heap.array[7] == &nodes[7]);
    assert(heap.array[1]->position == 1);
    assert(heap.array[2]->position == 2);
    assert(heap.array[3]->position == 3);
    assert(heap.array[4]->position == 4);
    assert(heap.array[5]->position == 5);
    assert(heap.array[6]->position == 6);
    assert(heap.array[7]->position == 7);
    assert(heap.length == 7);

    /* percolate the same node again, it shouldn't move */
    heapPercolateDown(&heap, 2);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &nodes[2]);
    assert(heap.array[2] == &nodes[1]);
    assert(heap.array[3] == &nodes[3]);
    assert(heap.array[4] == &nodes[4]);
    assert(heap.array[5] == &nodes[5]);
    assert(heap.array[6] == &nodes[6]);
    assert(heap.array[7] == &nodes[7]);
    assert(heap.array[1]->position == 1);
    assert(heap.array[2]->position == 2);
    assert(heap.array[3]->position == 3);
    assert(heap.array[4]->position == 4);
    assert(heap.array[5]->position == 5);
    assert(heap.array[6]->position == 6);
    assert(heap.array[7]->position == 7);
    assert(heap.length == 7);

    /* percolate root all the way down */
    objects[2].content = 2*HEAP_SIZE;
    heapPercolateDown(&heap, 1);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &nodes[1]);
    assert(heap.array[2] == &nodes[4]);
    assert(heap.array[3] == &nodes[3]);
    assert(heap.array[4] == &nodes[2]);
    assert(heap.array[5] == &nodes[5]);
    assert(heap.array[6] == &nodes[6]);
    assert(heap.array[7] == &nodes[7]);
    assert(heap.array[1]->position == 1);
    assert(heap.array[2]->position == 2);
    assert(heap.array[3]->position == 3);
    assert(heap.array[4]->position == 4);
    assert(heap.array[5]->position == 5);
    assert(heap.array[6]->position == 6);
    assert(heap.array[7]->position == 7);
    assert(heap.length == 7);

    /* percolate the same node again, it shouldn't move */
    heapPercolateDown(&heap, 4);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &nodes[1]);
    assert(heap.array[2] == &nodes[4]);
    assert(heap.array[3] == &nodes[3]);
    assert(heap.array[4] == &nodes[2]);
    assert(heap.array[5] == &nodes[5]);
    assert(heap.array[6] == &nodes[6]);
    assert(heap.array[7] == &nodes[7]);
    assert(heap.array[1]->position == 1);
    assert(heap.array[2]->position == 2);
    assert(heap.array[3]->position == 3);
    assert(heap.array[4]->position == 4);
    assert(heap.array[5]->position == 5);
    assert(heap.array[6]->position == 6);
    assert(heap.array[7]->position == 7);
    assert(heap.length == 7);

    /* percolate a node in the second level */
    objects[3].content = 4*HEAP_SIZE;
    heapPercolateDown(&heap, 3);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &nodes[1]);
    assert(heap.array[2] == &nodes[4]);
    assert(heap.array[3] == &nodes[6]);
    assert(heap.array[4] == &nodes[2]);
    assert(heap.array[5] == &nodes[5]);
    assert(heap.array[6] == &nodes[3]);
    assert(heap.array[7] == &nodes[7]);
    assert(heap.array[1]->position == 1);
    assert(heap.array[2]->position == 2);
    assert(heap.array[3]->position == 3);
    assert(heap.array[4]->position == 4);
    assert(heap.array[5]->position == 5);
    assert(heap.array[6]->position == 6);
    assert(heap.array[7]->position == 7);
    assert(heap.length == 7);

    /* percolate root and cause a right sided swap */
    objects[1].content = 7;
    heapPercolateDown(&heap, 1);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &nodes[4]);
    assert(heap.array[2] == &nodes[5]);
    assert(heap.array[3] == &nodes[6]);
    assert(heap.array[4] == &nodes[2]);
    assert(heap.array[5] == &nodes[1]);
    assert(heap.array[6] == &nodes[3]);
    assert(heap.array[7] == &nodes[7]);
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
