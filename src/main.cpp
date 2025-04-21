#include <iostream>
#include "lodis/in_memory_db.h"

int main() {
    InMemoryDB db;

    db.set("mykey", "myvalue");
    std::cout << "Value: " << db.get("mykey") << std::endl;

    db.get("mykey");

    db.del("mykey");
    std::cout << "Value after delete: " << db.get("mykey") << std::endl;

    db.get("mykey");

    return 0;
}