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
     */
    explicit Apid(unsigned short value) : value_(value) {}

    /**
     * @brief Returns the underlying APID value.
     * @return The raw value this Apid was constructed with.
     */
    unsigned short value() const noexcept { return value_; }

private:
    unsigned short value_;
};