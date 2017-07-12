#include <iostream>
#include <vector>

struct rObj{
    std::vector<uint8_t> raw;
};

struct sObj : public rObj {
    std::string data;
};

struct iObj : public rObj {
    uint32_t data;
};

void parseIObj(iObj obj) {
    std::cout << "normal" << std::endl;
}

uint32_t&& parseIObj(iObj obj, bool) {
    std::cout << "rval" << std::endl;
}

int main(int, char**){
    iObj obj;
    parseIObj(obj);
    uint32_t val = parseIObj(obj, true);
    return 0;
}
