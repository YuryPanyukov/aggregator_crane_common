#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "Headers/TimedQueue.h"

using namespace std;

// function to parse a date or time string.
chrono::system_clock::time_point GFG(const string& datetimeString, const string& format)
{
    tm tmStruct = {};
    istringstream ss(datetimeString);
    ss >> get_time(&tmStruct, format.c_str());
    return chrono::system_clock::from_time_t(
        mktime(&tmStruct));
}

// Function to format a time_t value into a date or time string.
string DateTime(const chrono::system_clock::time_point& timePoint,
         const string& format)
{
    time_t time
        = chrono::system_clock::to_time_t(timePoint);
    tm* timeinfo = localtime(&time);
    char buffer[70];
    strftime(buffer, sizeof(buffer), format.c_str(),
             timeinfo);
    return buffer;
}

time_t timeTConvert(const string datetimeString, const string format = "%Y-%m-%d %H:%M:%S"){
    chrono::system_clock::time_point parsedTime = GFG(datetimeString, format);
    string formattedTime = DateTime(parsedTime, format);
    return chrono::system_clock::to_time_t(parsedTime);
}


int main()
{
    const string datetimeString = "2023-05-22 12:24:52";
    const string format = "%Y-%m-%d %H:%M:%S";
    chrono::system_clock::time_point parsedTime = GFG(datetimeString, format);
    string formattedTime = DateTime(parsedTime, format);
    cout << "Parsed Time: "
         << chrono::system_clock::to_time_t(parsedTime)
         << endl;
    cout << "Formatted Time: " << formattedTime << endl;

    TimedQueue<int> time_queue(5);

    time_queue.addData(timeTConvert("2023-05-22 12:24:51"), 1);
    time_queue.addData(timeTConvert("2023-05-22 12:24:52"), 2);
    time_queue.addData(timeTConvert("2023-05-22 12:24:53"), 3);
    time_queue.addData(timeTConvert("2023-05-22 12:24:54"), 4);
    time_queue.addData(timeTConvert("2023-05-22 12:24:55"), 5);
    time_queue.addData(timeTConvert("2023-05-22 12:24:56"), 6);
    time_queue.addData(timeTConvert("2023-05-22 12:24:57"), 7);


    return 0;
}