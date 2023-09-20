
#include <iostream>
#include "Week_03/list/double_list.h"

template <typename Object>
class Set
{
private:
    List<Object> list;

public:
    Set(){};

    ~Set(){};

    bool contains(const Object x)
    {
        for (int i = 0; i < list.size(); ++i)
        {
            if (list.find_kth(i) == x)
            {
                return true;
            }
        }
        return false;
    }

    void insert(const Object x)
    {
        if (!contains(x))
        {
            // Add x to the list if it's not already present.
            list.push_back(x);
        }
    }

    void remove(const Object x)
    {
        for (int i = 0; i < list.size(); ++i)
        {
            if (list.find_kth(i) == x)
            {
                // Remove x from the list if it's present.
                list.pop_front();
            }
        }
    }
};

int main()
{

    Set<int> set;
    set.insert(1);
    set.insert(2);
    set.insert(3);

    std::cout << "set.contains(1): " << set.contains(1) << std::endl;

    set.remove(1);
    std::cout << "set.contains(1): " << set.contains(1) << std::endl;

    set.insert(1);
    std::cout << "set.contains(1): " << set.contains(1) << std::endl;

    return 0;
}