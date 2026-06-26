#include "include/TimedQueue.h"
#include "include/base_func.h"


void testTimedQueue(){
    TimedQueue<int> time_queue(5);

    time_queue.addData(timeTConvert("2023-05-22 12:24:51"), 1);
    time_queue.addData(timeTConvert("2023-05-22 12:24:52"), 2);
    time_queue.addData(timeTConvert("2023-05-22 12:24:53"), 3);
    time_queue.addData(timeTConvert("2023-05-22 12:24:54"), 4);
    time_queue.addData(timeTConvert("2023-05-22 12:24:55"), 5);
    time_queue.addData(timeTConvert("2023-05-22 12:24:56"), 6);
    time_queue.addData(timeTConvert("2023-05-22 12:24:57"), 7);
}