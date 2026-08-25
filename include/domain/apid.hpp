#pragma once

/**
 * @brief An 11-bit CCSDS Application Process Identifier.
 *
 * Identifies which subsystem a Space Packet was sent by or is addressed
 * to. Immutable value object.
 */
class Apid {
public:
    /**
     * @brief Constructs an Apid from a raw value.
     * @param value The raw APID value.
     * @throws std::domain_error if value exceeds 0x7FF.
     */
    explicit Apid(unsigned short value) : value_(value) {
        if (value > 0x7FF) {
            throw std::domain_error("Apid value exceeds 11-bit range (max 0x7FF)");
        }
    }

    /**
     * @brief Returns the underlying APID value.
     * @return The raw value this Apid was constructed with.
     */
    unsigned short value() const noexcept { return value_; }

private:
    unsigned short value_;
};