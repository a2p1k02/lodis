# LODIS

LODIS - local dictionary server. This is my implementation of Redis.
This is just my way to write some code in C++

## Example
```c++
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
```