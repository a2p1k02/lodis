#ifndef DATA_ITEM_H_
#define DATA_ITEM_H_
#include <string>

struct DataItem {
    std::string value;
    explicit DataItem(const std::string& value);
};

#endif //DATA_ITEM_H_
