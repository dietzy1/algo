#include <vector>
#include <iostream>
#include <utility>

#define MAXLOADFACTOR 0.7
#define BUCKETSIZE 8

template <typename Key, typename Value>
class Dictionary
{
private:
    // Array which contains buckets of key-value pairs.
    std::vector<std::vector<std::pair<Key, Value>>> buckets;

    int bucketSize;

    unsigned long hash(const Key &key) const
    {
        return std::hash<Key>{}(key) % bucketSize;
    }

    void resize()
    {

        int newBucketSize = bucketSize * 2;
        std::vector<std::vector<std::pair<Key, Value>>> newBuckets(newBucketSize);

        // Rehash all existing key-value pairs into the new buckets
        for (const auto &bucket : buckets)
        {
            for (const auto &pair : bucket)
            {
                unsigned long newHash = hash(pair.first);
                newBuckets[newHash].push_back(pair);
            }
        }

        // Update the bucket size and replace the old buckets with the new ones
        bucketSize = newBucketSize;
        buckets = std::move(newBuckets);
    };

public:
    Dictionary()
    {
        this->bucketSize = BUCKETSIZE;
        buckets.resize(bucketSize);
    };

    ~Dictionary(){
        // Memory should clear automaticly
    };

    void insert(const Key key, const Value value)
    {
        // Calculate the hash for the key
        unsigned long hashValue = hash(key);

        // Check if the key already exists in the bucket
        for (auto &pair : buckets[hashValue])
        {
            if (pair.first == key)
            {
                // Key already exists, update the value
                pair.second = value;
                return;
            }
        }

        // Key doesn't exist, insert the key-value pair
        buckets[hashValue].emplace_back(key, value);

        // Check if resizing is needed
        if (buckets[hashValue].size() > MAXLOADFACTOR * bucketSize)
        {
            resize();
        }
    }

    void remove(const Key key)
    {
        // Calculate the hash for the key
        unsigned long hashValue = hash(key);

        // Find and remove the key if it exists in the bucket
        auto &bucket = buckets[hashValue];
        for (auto it = bucket.begin(); it != bucket.end(); ++it)
        {
            if (it->first == key)
            {
                bucket.erase(it);
                return;
            }
        }
    }

    // It will return default value if key not found
    Value find(const Key key)
    {
        // Calculate the hash for the key
        unsigned long hashValue = hash(key);

        // Search for the key in the bucket
        for (const auto &pair : buckets[hashValue])
        {
            if (pair.first == key)
            {
                return pair.second;
            }
        }

        return Value();
    }
};

int main()
{
    Dictionary<std::string, int> dict;
    dict.insert("one", 1);
    dict.insert("two", 2);
    dict.insert("three", 3);
    dict.insert("four", 4);
    dict.insert("five", 5);

    std::cout << "dict.find(\"one\"): " << dict.find("one") << std::endl;
    std::cout << "dict.find(\"two\"): " << dict.find("two") << std::endl;
    std::cout << "dict.find(\"three\"): " << dict.find("three") << std::endl;
    std::cout << "dict.find(\"four\"): " << dict.find("four") << std::endl;
    std::cout << "dict.find(\"five\"): " << dict.find("five") << std::endl;

    dict.insert("one", 10);
    dict.insert("one", 20);
    std::cout << "dict.find(\"one\"): " << dict.find("one") << std::endl;

    return 0;
}