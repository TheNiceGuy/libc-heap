######################
# minimum heap tests #
######################
project(test_min_heap)

add_executable(heapMinInsertNode_test
    object.c
    heapInsertNode.c
    ${SOURCES}/heap.c
)
target_compile_definitions(heapMinInsertNode_test PUBLIC TEST_MIN_HEAP)
add_test(heapMinInsertNode heapMinInsertNode_test)

add_executable(heapMinPercolateDown_test
    object.c
    heapPercolateDown.c
    ${SOURCES}/heap.c
)
target_compile_definitions(heapMinPercolateDown_test PUBLIC TEST_MIN_HEAP)
add_test(heapMinPercolateDown heapMinPercolateDown_test)
set_property(TEST heapMinPercolateDown APPEND PROPERTY DEPENDS heapMinInsertNode)

add_executable(heapMinDeleteNode_test
    object.c
    heapDeleteNode.c
    ${SOURCES}/heap.c
)
target_compile_definitions(heapMinDeleteNode_test PUBLIC TEST_MIN_HEAP)
add_test(heapMinDeleteNode heapMinDeleteNode_test)
set_property(TEST heapMinDeleteNode APPEND PROPERTY DEPENDS heapMinInsertNode)

add_executable(heapMinUpdateNode_test
    object.c
    heapUpdateNode.c
    ${SOURCES}/heap.c
)
target_compile_definitions(heapMinUpdateNode_test PUBLIC TEST_MIN_HEAP)
add_test(heapMinUpdateNode heapMinUpdateNode_test)
set_property(TEST heapMinUpdateNode APPEND PROPERTY DEPENDS heapMinInsertNode)
set_property(TEST heapMinUpdateNode APPEND PROPERTY DEPENDS heapMinPercolateDown)

######################
# maximum heap tests #
######################
project(test_max_heap)

add_executable(heapMaxInsertNode_test
    object.c
    heapInsertNode.c
    ${SOURCES}/heap.c
)
target_compile_definitions(heapMaxInsertNode_test PUBLIC TEST_MAX_HEAP)
add_test(heapMaxInsertNode heapMaxInsertNode_test)

add_executable(heapMaxPercolateDown_test
    object.c
    heapPercolateDown.c
    ${SOURCES}/heap.c
)
target_compile_definitions(heapMaxPercolateDown_test PUBLIC TEST_MAX_HEAP)
add_test(heapMaxPercolateDown heapMaxPercolateDown_test)
set_property(TEST heapMaxPercolateDown APPEND PROPERTY DEPENDS heapMaxInsertNode)

add_executable(heapMaxDeleteNode_test
    object.c
    heapDeleteNode.c
    ${SOURCES}/heap.c
)
target_compile_definitions(heapMaxDeleteNode_test PUBLIC TEST_MAX_HEAP)
add_test(heapMaxDeleteNode heapMaxDeleteNode_test)
set_property(TEST heapMaxDeleteNode APPEND PROPERTY DEPENDS heapMaxInsertNode)

add_executable(heapMaxUpdateNode_test
    object.c
    heapUpdateNode.c
    ${SOURCES}/heap.c
)
target_compile_definitions(heapMaxUpdateNode_test PUBLIC TEST_MAX_HEAP)
add_test(heapMaxUpdateNode heapMaxUpdateNode_test)
set_property(TEST heapMaxUpdateNode APPEND PROPERTY DEPENDS heapMaxInsertNode)
set_property(TEST heapMaxUpdateNode APPEND PROPERTY DEPENDS heapMaxPercolateDown)
