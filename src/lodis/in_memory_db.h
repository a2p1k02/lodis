#ifndef IN_MEMORY_DB_H_
#define IN_MEMORY_DB_H_

#include <unordered_map>
#include <memory>
#include <thread>

#include "data_item.h"

class InMemoryDB{
private:
    std::unordered_map<std::string, std::unique_ptr<DataItem>> data;
    std::mutex mutex;
    std::thread cleanup_old_data;
    bool stop_cleanup = false;

    void cleanup();

public:
    explicit InMemoryDB();
    ~InMemoryDB();

    void set(const std::string& key, const std::string& value);
    std::string get(const std::string& key);
    void del(const std::string& key);
};

#endif //IN_MEMORY_DB_H_
