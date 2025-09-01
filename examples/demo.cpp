#include "simdutf.h"
#include <iostream>
#include <string>
#include <vector>

// Simple test program demonstrating simdutf usage that envoy might use
int main() {
    // Test UTF-8 validation
    std::string test_utf8 = "Hello, 世界! 🌍";
    bool is_valid = simdutf::validate_utf8(test_utf8.c_str(), test_utf8.length());
    std::cout << "UTF-8 validation: " << (is_valid ? "PASS" : "FAIL") << std::endl;
    
    // Test UTF-8 to UTF-16 conversion
    size_t expected_length = simdutf::utf16_length_from_utf8(test_utf8.c_str(), test_utf8.length());
    std::vector<char16_t> utf16_output(expected_length);
    
    size_t converted = simdutf::convert_utf8_to_utf16le(
        test_utf8.c_str(), test_utf8.length(),
        utf16_output.data()
    );
    
    std::cout << "UTF-8 to UTF-16 conversion: " << 
        (converted > 0 ? "PASS" : "FAIL") << 
        " (converted " << converted << " characters)" << std::endl;
    
    // Test UTF-16 back to UTF-8
    size_t expected_utf8_length = simdutf::utf8_length_from_utf16le(utf16_output.data(), converted);
    std::vector<char> utf8_back(expected_utf8_length);
    
    size_t converted_back = simdutf::convert_utf16le_to_utf8(
        utf16_output.data(), converted,
        utf8_back.data()
    );
    
    std::cout << "UTF-16 to UTF-8 conversion: " << 
        (converted_back > 0 ? "PASS" : "FAIL") << 
        " (converted " << converted_back << " bytes)" << std::endl;
    
    // Verify round-trip
    std::string result(utf8_back.data(), converted_back);
    bool round_trip_ok = (result == test_utf8);
    std::cout << "Round-trip test: " << (round_trip_ok ? "PASS" : "FAIL") << std::endl;
    
    std::cout << "All tests completed!" << std::endl;
    return (is_valid && converted > 0 && converted_back > 0 && round_trip_ok) ? 0 : 1;
}