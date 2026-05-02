#include "Serializer.hpp"

int main() {
    
    // 1. Create and initialize the Data structure
    Data myData;
    myData.num = 42;

    std::cout << "--- Serialization Test ---" << std::endl;
    
    // Print original state
    std::cout << "Original address of myData: " << &myData << std::endl;
    std::cout << "Original value (myData.num): " << myData.num << std::endl;
    std::cout << "-----------------------------" << std::endl;

    // 2. Use serialize() to convert the pointer to an uintptr_t
    uintptr_t rawData = Serializer::serialize(&myData);
    std::cout << "Serialized value (uintptr_t): " << rawData << std::endl;

    // 3. Use deserialize() to convert the uintptr_t back to a pointer
    Data* deserializedData = Serializer::deserialize(rawData);
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Post-deserialization address: " << deserializedData << std::endl;
    std::cout << "Post-deserialization value:   " << deserializedData->num << std::endl;
    std::cout << "-----------------------------" << std::endl;

    if (&myData == deserializedData) {
        std::cout << "[SUCCESS] Pointers are equal! Serialization worked." << std::endl;
    } else {
        std::cout << "[ERROR] Pointers do not match!" << std::endl;
    }

    return 0;
}