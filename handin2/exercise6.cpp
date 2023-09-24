
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
        List<Object> tempList;
        for (int i = 0; i < list.size(); ++i)
        {
            Object temp = list.pop_back();

            if (temp != x)
            {
                tempList.push_front(temp);
                // Remove x from the list if it's present.
            }
            if (temp == x)
            {
                break;
            }
        }

        for (int i = 0; i < tempList.size(); ++i)
        {
            list.push_front(tempList.pop_back());
        }
    }
};

int main()
{

    Set<int> set;
    set.insert(1);
    set.insert(2);
    set.insert(3);
    set.insert(4);
    set.insert(5);

    std::cout << "1 exists? " << set.contains(1) << std::endl;

    set.remove(4);
    std::cout << "4 exist? " << set.contains(4) << std::endl;

    set.insert(3);
    std::cout << "3 exists?: " << set.contains(3) << std::endl;

    std::cout << "2 exists?: " << set.contains(2) << std::endl;
    std::cout << "5 exists?: " << set.contains(5) << std::endl;

    return 0;
}