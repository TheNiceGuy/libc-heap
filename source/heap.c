#include <stdlib.h>
#include <heap.h>

void heapSwapNode(struct heap* heap, unsigned int n1, unsigned int n2) {
    /* update position */
    if(heap->array[n1] != NULL) heap->array[n1]->position = n2;
    if(heap->array[n2] != NULL) heap->array[n2]->position = n1;

    /* swap pointer */
    struct heapNode* tempNode = heap->array[n1];
    heap->array[n1] = heap->array[n2];
    heap->array[n2] = tempNode;
}

int heapCompareTo(struct heap* heap, unsigned int n1, unsigned int n2) {
    return heap->compare(heap->array[n1]->data, heap->array[n2]->data);
}

/**************************/
/* minimum heap functions */
/**************************/

struct heapNode* heapMinInsertNode(struct heap* heap, struct heapNode* node) {
    /* check if there's space available */
    if(heap->length == heap->size-1) return NULL;

    /* percolate up */
    unsigned int hole = ++heap->length;
    for(heap->array[0] = node; heapCompareTo(heap, 0, hole/2); hole /= 2)
        heapSwapNode(heap, hole, hole/2);

    /* insert the new node */
    heapSwapNode(heap, hole, 0);

    return node;
}

void heapMinPercolateDown(struct heap* heap, unsigned int hole) {
    unsigned int child;
    for(; 2*hole <= heap->length; hole = child) {
        /* check if we percolate left or right */
        child = 2*hole;
        if(child != heap->length)
            if(heapCompareTo(heap, child+1, child)) child++;

        /* swap if heap property would still be respected */
        if(heapCompareTo(heap, child, hole))
            heapSwapNode(heap, child, hole);
        else
            break;
    }
}

struct heapNode* heapMinDeleteNode(struct heap* heap) {
    /* check if there's something in the heap */
    if(heap->length == 0) return NULL;

    /* get the root node */
    struct heapNode* node = heap->array[1];
    heap->array[1] = NULL;

    /* swap the root and the last node */
    heapSwapNode(heap, 1, heap->length--);

    /* percolate down root node */
    heapMinPercolateDown(heap, 1);

    /* remove the node from the heap */
    node->position = 0;
    return node;
}

struct heapNode* heapMinUpdateNode(struct heap* heap, struct heapNode* node) {
    /* make sure the node is in the heap */
    unsigned int position = node->position;
    if(position == 0) return NULL;

    /* if it is on top, percolate down */
    if(position == 1) {
        heapMinPercolateDown(heap, position);
        return node;
    }

    /* percolate up if possible */
    unsigned int parent = position/2;    
    if(heapCompareTo(heap, position, parent)) {
        while(1) {
            /* swap nodes */
            heapSwapNode(heap, position, parent);
            position = parent;

            /* exit if the node is now at root */
            if(position == 1) break;

            /* exit if we can't go higher */
            parent = position/2;
            if(!heapCompareTo(heap, position, parent)) break;
        }
        return node;
    }

    /* we can't go up, percolate down */
    heapMinPercolateDown(heap, position);
    return node;
}

/**************************/
/* maximum heap functions */
/**************************/

struct heapNode* heapMaxInsertNode(struct heap* heap, struct heapNode* node) {
    /* check if there's space available */
    if(heap->length == heap->size-1) return NULL;

    /* percolate up */
    unsigned int hole = ++heap->length;
    for(heap->array[0] = node; heapCompareTo(heap, 0, hole/2); hole /= 2)
        heapSwapNode(heap, hole, hole/2);

    /* insert the new node */
    heapSwapNode(heap, hole, 0);

    return node;
}

void heapMaxPercolateDown(struct heap* heap, unsigned int hole) {
    unsigned int child;
    for(; 2*hole <= heap->length; hole = child) {
        /* check if we percolate left or right */
        child = 2*hole;
        if(child != heap->length)
            if(heapCompareTo(heap, child+1, child)) child++;

        /* swap if heap property would still be respected */
        if(heapCompareTo(heap, child, hole))
            heapSwapNode(heap, child, hole);
        else
            break;
    }
}

struct heapNode* heapMaxDeleteNode(struct heap* heap) {
    /* check if there's something in the heap */
    if(heap->length == 0) return NULL;

    /* get the root node */
    struct heapNode* node = heap->array[1];
    heap->array[1] = NULL;

    /* swap the root and the last node */
    heapSwapNode(heap, 1, heap->length--);

    /* percolate down root node */
    heapMaxPercolateDown(heap, 1);

    /* remove the node from the heap */
    node->position = 0;
    return node;
}

struct heapNode* heapMaxUpdateNode(struct heap* heap, struct heapNode* node) {
    /* make sure the node is in the heap */
    unsigned int position = node->position;
    if(position == 0) return NULL;

    /* if it is on top, percolate down */
    if(position == 1) {
        heapMaxPercolateDown(heap, position);
        return node;
    }

    /* percolate up if possible */
    unsigned int parent = position/2;    
    if(heapCompareTo(heap, position, parent)) {
        while(1) {
            /* swap nodes */
            heapSwapNode(heap, position, parent);
            position = parent;

            /* exit if the node is now at root */
            if(position == 1) break;

            /* exit if we can't go higher */
            parent = position/2;
            if(!heapCompareTo(heap, position, parent)) break;
        }
        return node;
    }

    /* we can't go up, percolate down */
    heapMaxPercolateDown(heap, position);
    return node;
} 
