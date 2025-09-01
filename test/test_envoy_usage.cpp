#include "simdutf.h" 
#include <iostream>
#include <cstring>

// Test that mimics envoy's usage pattern
int main() {
    std::cout << "Testing envoy-style simdutf usage..." << std::endl;
    
    const char* test_str = "Hello from envoy!";
    size_t len = strlen(test_str);
    
    // Basic validation test
    if (simdutf::validate_utf8(test_str, len)) {
        std::cout << "✓ UTF-8 validation works" << std::endl;
    } else {
        std::cout << "✗ UTF-8 validation failed" << std::endl;
        return 1;
    }
    
    // Basic conversion test  
    size_t utf16_len = simdutf::utf16_length_from_utf8(test_str, len);
    if (utf16_len > 0) {
        std::cout << "✓ UTF-8 to UTF-16 length calculation works: " << utf16_len << std::endl;
    } else {
        std::cout << "✗ UTF-8 to UTF-16 length calculation failed" << std::endl;
        return 1;
    }
    
    std::cout << "All envoy-style tests passed!" << std::endl;
    return 0;
}