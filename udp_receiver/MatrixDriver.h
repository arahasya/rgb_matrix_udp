//
// Created by robert on 8/15/19.
//

#ifndef UDP_RECEIVER_MATRIXDRIVER_H
#define UDP_RECEIVER_MATRIXDRIVER_H

#include <cstdint>
#include <cstddef>
#include <pthread.h>

class MatrixDriver {
public:
    MatrixDriver(int rowLength, int rowsPerPanel, int pwmBits);
    ~MatrixDriver();

    void flipBuffer();

    void clearFrame();

    void setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b);
    void setPixel(int x, int y, uint8_t *rgb);
    void setPixels(int &x, int &y, uint8_t *rgb, int pixelCount);

    typedef uint16_t pwm_lut[256];
    pwm_lut& getPwmMapping() { return pwmMapping; }

private:
    uint32_t pixelsPerRow;
    uint32_t rowsPerScan;
    uint8_t pwmBits;
    uint8_t nextBuffer;

    uint32_t sizeFrameBuffer;
    uint32_t *frameRaw;
    uint32_t *frameBuffer[2];
    uint32_t *gpioRegister, *gpioSet, *gpioClr;
    pthread_t threadGpio;
    pthread_mutex_t mutexBuffer;
    pthread_cond_t condBuffer;

    pwm_lut pwmMapping;

    void initFrameBuffer(uint32_t *fb);
    void initGpio();
    void sendFrame(const uint32_t *fb);

};

void createPwmLutCie1931(uint8_t bits, float brightness, MatrixDriver::pwm_lut &pwmLut);

#endif //UDP_RECEIVER_MATRIXDRIVER_H