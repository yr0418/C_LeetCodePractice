cmake_minimum_required(VERSION 3.17)
project(C___LeetCodePractice)

set(CMAKE_CXX_STANDARD 14)

#add_executable(C___LeetCodePractice
#        code_test/IntArray.cpp
#        code_test/NodeList.cpp
#        code_test/SqList.cpp
#        code_test/SqQueue.cpp
#        code_test/SqStack.cpp
#        ListNode/ListNode.cpp
#        TreeNode/TreeNode.cpp)
add_executable(ListNode ListNode/ListNode.cpp)
add_executable(TreeNode TreeNode/TreeNode.cpp)
