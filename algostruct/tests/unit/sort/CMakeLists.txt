cmake_minimum_required(VERSION 3.12)

create_algostruct_unit_test(NAME Sort_QuickNonrecTest SRC_TEST data_generation.cpp quick_sort_nonrec.cpp)
create_algostruct_unit_test(NAME Sort_QuickEliminateTest SRC_TEST data_generation.cpp quick_sort_eliminate.cpp)
create_algostruct_unit_test(NAME Sort_TreeTest SRC_TEST data_generation.cpp tree_sort.cpp)
create_algostruct_unit_test(NAME Sort_BucketTest SRC_TEST data_generation.cpp bucket_sort.cpp)
create_algostruct_unit_test(NAME Sort_RadixTest SRC_TEST data_generation.cpp radix_sort.cpp)
create_algostruct_unit_test(NAME Sort_KMergeTest SRC_TEST data_generation.cpp k_merge_sort.cpp)
create_algostruct_unit_test(NAME Sort_BubbleTest SRC_TEST data_generation.cpp bubble_sort.cpp)
create_algostruct_unit_test(NAME Sort_Insertion SRC_TEST data_generation.cpp insertion_sort.cpp)
create_algostruct_unit_test(NAME Sort_DHeapTest SRC_TEST data_generation.cpp d_heap_sort.cpp)
create_algostruct_unit_test(NAME Sort_CoiledTest SRC_TEST data_generation.cpp coiled_sort.cpp)
create_algostruct_unit_test(NAME Sort_CountTest SRC_TEST data_generation.cpp count_sort.cpp)
