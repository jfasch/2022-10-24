ADD_EXECUTABLE(
  exercises-suite

  simple.cpp
  threads.cpp
)
TARGET_LINK_LIBRARIES(exercises-suite gtest_main Threads::Threads)
