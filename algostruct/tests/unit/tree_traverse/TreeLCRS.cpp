#include <gtest/gtest.h>
#include <tree_traverse/TreeLCRS.h>
#include <numeric>

namespace algostruct {
    TEST(TEST_TREE_LCRS, SIMPLE_TESTS) {
        VertexLCRS vertex1(1);
        VertexLCRS vertex2(2), vertex3(3), vertex4(13), vertex5(14);
        vertex2.linkAsChild(&vertex1);
        vertex3.linkAsSibling(&vertex2);
        vertex4.linkAsSibling(&vertex3);
        vertex5.linkAsSibling(&vertex4);
        VertexLCRS vertex2_1(4), vertex2_2(11), vertex2_3(12);
        vertex2_1.linkAsChild(&vertex3);
        vertex2_2.linkAsSibling(&vertex2_1);
        vertex2_3.linkAsSibling(&vertex2_2);
        VertexLCRS vertex3_1(5), vertex3_2(6), vertex3_3(10);
        vertex3_1.linkAsChild(&vertex2_1);
        vertex3_2.linkAsSibling(&vertex3_1);
        vertex3_3.linkAsSibling(&vertex3_2);
        VertexLCRS vertex4_1(7);
        vertex4_1.linkAsChild(&vertex3_2);
        VertexLCRS vertex5_1(8), vertex5_2(9);
        vertex5_1.linkAsChild(&vertex4_1);
        vertex5_2.linkAsSibling(&vertex5_1);
        std::vector<int> vec(14);
        std::iota(vec.begin(), vec.end(), 1);
        size_t index = 0;
        for (auto& data : vertex1) {
            ASSERT_EQ(vec[index], data);
            ++index;
        }
    }
}