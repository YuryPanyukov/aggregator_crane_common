#include <ctime>
#include <vector>

template<typename Type>
class TimedQueue{
    private:
        int timeWindow;
        std::vector<time_t> timestamps;
        std::vector<Type> values;
        void pruneQueue();
    public:
        TimedQueue(int _timeWindow);
        ~TimedQueue() {}
        void addData(time_t timestamp, Type value);
        const std::vector<time_t>& getTimestamps();
        const std::vector<Type>& getValues();
        void clear();
};

template <typename Type>
inline void TimedQueue<Type>::pruneQueue(){
    while(!timestamps.empty()){
        time_t& lastTimestamp = timestamps.front();
        time_t& currentTimestamp = timestamps.back();
        if (currentTimestamp - lastTimestamp > timeWindow){
            timestamps.erase(timestamps.begin());
            values.erase(values.begin());
        }else{
            break;
        }
    }
    
}

template <typename Type>
inline TimedQueue<Type>::TimedQueue(int _timeWindow){
    timeWindow = _timeWindow;
}

template <typename Type>
inline void TimedQueue<Type>::addData(time_t timestamp, Type value){
    timestamps.push_back(timestamp);
    values.push_back(value);

    pruneQueue();
}

template <typename Type>
inline const std::vector<time_t> &TimedQueue<Type>::getTimestamps()
{
    return timestamps;
}

template <typename Type>
inline const std::vector<Type> &TimedQueue<Type>::getValues()
{
    return values;
}

template <typename Type>
inline void TimedQueue<Type>::clear(){
    
}
