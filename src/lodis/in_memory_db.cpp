#include "in_memory_db.h"

#include <iostream>
#include <mutex>

InMemoryDB::InMemoryDB() {
    this->cleanup_old_data = std::thread(&InMemoryDB::cleanup, this);
};

InMemoryDB::~InMemoryDB() {
    this->stop_cleanup = true;
    if (cleanup_old_data.joinable()) {
        cleanup_old_data.join();
    }
}

void InMemoryDB::cleanup() {
    while (!this->stop_cleanup) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::unique_lock lock(mutex);

        for (auto it = this->data.begin(); it != this->data.end();) {
            it = this->data.erase(it);
        }
    }
}

void InMemoryDB::set(const std::string &key, const std::string &value) {
    std::lock_guard lock(mutex);
    data[key] = std::make_unique<DataItem>(value);
    std::cout << "SET " << key << " = " << value << std::endl;
}

std::string InMemoryDB::get(const std::string &key) {
    std::lock_guard lock(mutex);
    const auto it = this->data.find(key);

    if (it == data.end()) {
        return "(nil)";
    }

    std::cout << "GET " << key << " = " << it->second->value << std::endl;
    return it->second->value;
}

void InMemoryDB::del(const std::string &key) {
    std::lock_guard lock(mutex);
    const auto it = this->data.find(key);

    if (it == data.end()) {
        std::cout << "KEY " << key << " NOT FOUND" << std::endl;
    } else {
        this->data.erase(it);
    }
}
