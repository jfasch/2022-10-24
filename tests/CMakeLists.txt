ADD_EXECUTABLE(
  design-patterns-c++-exercises-suite

  # <starting point>
  
  sensor-utils-suite.cpp
  server-thread-suite.cpp
  social-db-suite.cpp
  # </starting point>

  composite-suite-basic.cpp
  command-suite.cpp
  interpreter-suite.cpp

  abstract-factory-suite-vendor1.cpp
  abstract-factory-suite-vendor2.cpp

  factory-suite.cpp
)

TARGET_LINK_LIBRARIES(
  design-patterns-c++-exercises-suite gtest_main 

  design-patterns  
  Threads::Threads
)

ADD_EXECUTABLE(vector-initializer-list vector-initializer-list.cpp)


ADD_EXECUTABLE(sensor-i2c-nonabstract sensor-i2c-nonabstract.cpp)
TARGET_LINK_LIBRARIES(
  sensor-i2c-nonabstract  
  design-patterns  
)

ADD_EXECUTABLE(sensor-i2c-abstract sensor-i2c-abstract.cpp)
TARGET_LINK_LIBRARIES(
  sensor-i2c-abstract  
  design-patterns  
)

ADD_EXECUTABLE(sensor-unique-ptr sensor-unique-ptr.cpp)
TARGET_LINK_LIBRARIES(
  sensor-unique-ptr
  design-patterns  
)

ADD_EXECUTABLE(sensor-shared-ptr sensor-shared-ptr.cpp)
TARGET_LINK_LIBRARIES(
  sensor-shared-ptr
  design-patterns  
)
