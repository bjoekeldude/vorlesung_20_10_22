#include "tesla.hpp"

int main(){
    tesla_t meinWagen{};

    std::cout << meinWagen.getInfo() << std::endl;
    std::cout << std::to_string( meinWagen.getInfo().length() ) << std::endl;

}