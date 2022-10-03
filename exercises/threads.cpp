#include <gtest/gtest.h>

#include <future>
#include <chrono>

using namespace std::literals::chrono_literals;


TEST(threads, future)
{
    std::promise<int> promise;
    std::thread t([&promise](){
        std::this_thread::sleep_for(2s);
        promise.set_value(42);
    });

    auto future = promise.get_future();
    int value = future.get();
    ASSERT_EQ(value, 42);

    t.join();
}
