template <class Type>
class arrayQueue : public queueADT<Type>
{
private:
    int maxQueueSize;
    int queueFront;
    int queueRear;
    Type *list;

public:
    arrayQueue(int size = 100)
    {
        if (size <= 0)
            size = 100;
        maxQueueSize = size;
        queueFront = 0;
        queueRear = -1;
        list = new Type[maxQueueSize];
    }

    bool isEmptyQueue() const override
    {
        return queueFront == queueRear + 1;
    }

    bool isFullQueue() const override
    {
        return queueRear == maxQueueSize - 1;
    }

    void initializeQueue() override
    {
        queueFront = 0;
        queueRear = -1;
    }

    Type front() const override
    {
        if (isEmptyQueue())
        {
            throw underflow_error("Queue is empty!");
        }
        return list[queueFront];
    }

    Type back() const override
    {
        if (isEmptyQueue())
        {
            throw underflow_error("Queue is empty!");
        }
        return list[queueRear];
    }

    void addQueue(const Type &newElement) override
    {
        if (isFullQueue())
        {
            throw overflow_error("Queue is full!");
        }
        list[++queueRear] = newElement;
    }

    void deleteQueue() override
    {
        if (isEmptyQueue())
        {
            throw underflow_error("Queue is empty!");
        }
        queueFront++;
    }

    ~arrayQueue()
    {
        delete[] list;
    }
};
