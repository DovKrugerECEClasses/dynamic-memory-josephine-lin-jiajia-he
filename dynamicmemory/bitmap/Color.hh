//
// Created by Jacklyn He on 2018/11/15.
//

#ifndef COLOR_H
#define COLOR_H

#endif
class Color {
private:
    uint32_t rgba;

public:
    Color(uint8_t r, uint8_t g, uint32_t b) {
        rgba = r + g * 256 + b * 256 * 256;
    }

    uint32_t get() {
        return rgba;
    }
};

