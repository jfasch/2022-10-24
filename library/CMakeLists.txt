ADD_LIBRARY(
  design-patterns

  # <starting point>

  sensor.h
  sensor-random.h
  sensor-const.h
  sensor-i2c.h
  sensor-i2c-vendor1.h
  sensor-i2c-vendor2.h

  sensor-utils.h
  queue.h
  server-thread.h
  server-thread.cpp

  social-db.h
  social-db.cpp

  # </starting point>


  # <exercises>

  # put your stuff here

  # </exercises>
)  

TARGET_INCLUDE_DIRECTORIES(design-patterns PUBLIC .)
