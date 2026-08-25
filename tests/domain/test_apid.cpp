#include <catch2/catch_test_macros.hpp>
#include "domain/apid.hpp"

TEST_CASE("Apid stores a valid value", "[apid]") {
    Apid apid{100};
    REQUIRE(apid.value() == 100);
}

TEST_CASE("Apid accepts the maximum valid value", "[apid]") {
    Apid apid{0x7FF};
    REQUIRE(apid.value() == 0x7FF);
}