#include <assert.h>
#include <stdlib.h>
#include <heap.h>
#include "object.h"

#define HEAP_SIZE 8

struct object objects[HEAP_SIZE];
struct heapNode nodes[HEAP_SIZE];
struct heapNode* array[HEAP_SIZE] = {[0 ... HEAP_SIZE-1] = NULL};
struct heap heap = TEST_HEAP_INIT(HEAP_SIZE, array, &getValue);

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

    /* remove root */
    assert(heapDeleteNode(&heap) == &nodes[1]);
    assert(nodes[1].position == 0);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &nodes[2]);
    assert(heap.array[2] == &nodes[4]);
    assert(heap.array[3] == &nodes[3]);
    assert(heap.array[4] == &nodes[7]);
    assert(heap.array[5] == &nodes[5]);
    assert(heap.array[6] == &nodes[6]);
    assert(heap.array[7] == NULL);
    assert(heap.array[1]->position == 1);
    assert(heap.array[2]->position == 2);
    assert(heap.array[3]->position == 3);
    assert(heap.array[4]->position == 4);
    assert(heap.array[5]->position == 5);
    assert(heap.array[6]->position == 6);
    assert(heap.length == 6);

    /* remove root */
    assert(heapDeleteNode(&heap) == &nodes[2]);
    assert(nodes[2].position == 0);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &nodes[3]);
    assert(heap.array[2] == &nodes[4]);
    assert(heap.array[3] == &nodes[6]);
    assert(heap.array[4] == &nodes[7]);
    assert(heap.array[5] == &nodes[5]);
    assert(heap.array[6] == NULL);
    assert(heap.array[7] == NULL);
    assert(heap.array[1]->position == 1);
    assert(heap.array[2]->position == 2);
    assert(heap.array[3]->position == 3);
    assert(heap.array[4]->position == 4);
    assert(heap.array[5]->position == 5);
    assert(heap.length == 5);

    /* remove root */
    assert(heapDeleteNode(&heap) == &nodes[3]);
    assert(nodes[3].position == 0);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &nodes[4]);
    assert(heap.array[2] == &nodes[5]);
    assert(heap.array[3] == &nodes[6]);
    assert(heap.array[4] == &nodes[7]);
    assert(heap.array[5] == NULL);
    assert(heap.array[6] == NULL);
    assert(heap.array[7] == NULL);
    assert(heap.array[1]->position == 1);
    assert(heap.array[2]->position == 2);
    assert(heap.array[3]->position == 3);
    assert(heap.array[4]->position == 4);
    assert(heap.length == 4);

    /* remove root */
    assert(heapDeleteNode(&heap) == &nodes[4]);
    assert(nodes[4].position == 0);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &nodes[5]);
    assert(heap.array[2] == &nodes[7]);
    assert(heap.array[3] == &nodes[6]);
    assert(heap.array[4] == NULL);
    assert(heap.array[5] == NULL);
    assert(heap.array[6] == NULL);
    assert(heap.array[7] == NULL);
    assert(heap.array[1]->position == 1);
    assert(heap.array[2]->position == 2);
    assert(heap.array[3]->position == 3);
    assert(heap.length == 3);

    /* remove root */
    assert(heapDeleteNode(&heap) == &nodes[5]);
    assert(nodes[5].position == 0);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &nodes[6]);
    assert(heap.array[2] == &nodes[7]);
    assert(heap.array[3] == NULL);
    assert(heap.array[4] == NULL);
    assert(heap.array[5] == NULL);
    assert(heap.array[6] == NULL);
    assert(heap.array[7] == NULL);
    assert(heap.array[1]->position == 1);
    assert(heap.array[2]->position == 2);
    assert(heap.length == 2);

    /* remove root */
    assert(heapDeleteNode(&heap) == &nodes[6]);
    assert(nodes[6].position == 0);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == &nodes[7]);
    assert(heap.array[2] == NULL);
    assert(heap.array[3] == NULL);
    assert(heap.array[4] == NULL);
    assert(heap.array[5] == NULL);
    assert(heap.array[6] == NULL);
    assert(heap.array[7] == NULL);
    assert(heap.array[1]->position == 1);
    assert(heap.length == 1);

    /* remove root */
    assert(heapDeleteNode(&heap) == &nodes[7]);
    assert(nodes[7].position == 0);
    assert(heap.array[0] == NULL);
    assert(heap.array[1] == NULL);
    assert(heap.array[2] == NULL);
    assert(heap.array[3] == NULL);
    assert(heap.array[4] == NULL);
    assert(heap.array[5] == NULL);
    assert(heap.array[6] == NULL);
    assert(heap.array[7] == NULL);
    assert(heap.length == 0);

    return 0;
}
