How To ...
==========

Get And Initialize
------------------

.. code-block:: console

   $ git clone https://github.com/jfasch/2022-10-24.git
   $ cd 2022-10-24/
   $ git submodule init
   $ git submodule update

Build
-----

Create build directory, and change into it ...

.. code-block:: console

   $ mkdir /tmp/2022-10-24/
   $ cd /tmp/2022-10-24

Massage source tree, create Makefiles ...

.. code-block:: console

   $ cmake ~/2022-10-24/
   -- The C compiler identification is GNU 12.2.1
   -- The CXX compiler identification is GNU 12.2.1
   -- Detecting C compiler ABI info
   -- Detecting C compiler ABI info - done
   -- Check for working C compiler: /usr/bin/cc - skipped
   -- Detecting C compile features
   -- Detecting C compile features - done
   -- Detecting CXX compiler ABI info
   -- Detecting CXX compiler ABI info - done
   -- Check for working CXX compiler: /usr/bin/c++ - skipped
   -- Detecting CXX compile features
   -- Detecting CXX compile features - done
   -- Looking for pthread.h
   -- Looking for pthread.h - found
   -- Performing Test CMAKE_HAVE_LIBC_PTHREAD
   -- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
   -- Found Threads: TRUE  
   -- Found Python: /usr/bin/python3.10 (found version "3.10.6") found components: Interpreter 
   -- Configuring done
   -- Generating done
   -- Build files have been written to: /tmp/2022-10-24

Build. First build will take a little longer because ``googletest``
has to be built.

.. code-block:: console

   $ make
   [  7%] Building CXX object googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
   [ 15%] Linking CXX static library ../../lib/libgtest.a
   [ 15%] Built target gtest
   [ 23%] Building CXX object googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
   [ 30%] Linking CXX static library ../../lib/libgmock.a
   [ 30%] Built target gmock
   [ 38%] Building CXX object googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
   [ 46%] Linking CXX static library ../../lib/libgmock_main.a
   [ 46%] Built target gmock_main
   [ 53%] Building CXX object googletest/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
   [ 61%] Linking CXX static library ../../lib/libgtest_main.a
   [ 61%] Built target gtest_main
   [ 69%] Building CXX object exercises/CMakeFiles/exercises-suite.dir/simple.cpp.o
   [ 76%] Building CXX object exercises/CMakeFiles/exercises-suite.dir/threads.cpp.o
   [ 84%] Linking CXX executable exercises-suite
   [ 84%] Built target exercises-suite
   [ 92%] Building CXX object livehacking/CMakeFiles/hello.dir/hello.cpp.o
   [100%] Linking CXX executable hello
   [100%] Built target hello
   
Run Tests
---------

In directory ``exercises/``, an executable ``exercises-suite`` is
built. Run that,

.. code-block:: console

   $ ./exercises/exercises-suite 
   Running main() from /home/jfasch/2022-10-24/googletest/googletest/src/gtest_main.cc
   [==========] Running 2 tests from 2 test suites.
   [----------] Global test environment set-up.
   [----------] 1 test from simple_suite
   [ RUN      ] simple_suite.fail
   /home/jfasch/2022-10-24/exercises/simple.cpp:5: Failure
   Expected equality of these values:
     1
     2
   [  FAILED  ] simple_suite.fail (0 ms)
   [----------] 1 test from simple_suite (0 ms total)
   
   [----------] 1 test from threads
   [ RUN      ] threads.future
   [       OK ] threads.future (2000 ms)
   [----------] 1 test from threads (2000 ms total)
   
   [----------] Global test environment tear-down
   [==========] 2 tests from 2 test suites ran. (2000 ms total)
   [  PASSED  ] 1 test.
   [  FAILED  ] 1 test, listed below:
   [  FAILED  ] simple_suite.fail
   
    1 FAILED TEST
   
You see one failing test, and one that passes.
