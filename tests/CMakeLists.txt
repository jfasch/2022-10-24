ADD_EXECUTABLE(
  design-patterns-c++-exercises-suite

  # <starting point>
  
  sensor-utils-suite.cpp
  server-thread-suite.cpp
  social-db-suite.cpp
  # </starting point>

  proxy-remote-suite.cpp
)

TARGET_LINK_LIBRARIES(
  design-patterns-c++-exercises-suite gtest_main 

  design-patterns  
  Threads::Threads
)
