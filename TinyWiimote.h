// Copyright (c) 2020 Daiki Yasuda
//
// This is licensed under
// - Creative Commons Attribution-NonCommercial 3.0 Unported
// - https://creativecommons.org/licenses/by-nc/3.0/
// - Or see LICENSE.md
//
// The short of it is...
//   You are free to:
//     Share — copy and redistribute the material in any medium or format
//     Adapt — remix, transform, and build upon the material
//   Under the following terms:
//     NonCommercial — You may not use the material for commercial purposes.

#ifndef _TINY_WIIMOTE_H_
#define _TINY_WIIMOTE_H_

#define RECIEVED_DATA_MAX_LEN     (50)
struct TinyWiimoteData {
  uint8_t number;
  uint8_t data[RECIEVED_DATA_MAX_LEN];
  uint8_t len;
};
#define TWII_OFFSET_BTNS1 (2)
#define TWII_OFFSET_BTNS2 (3)

typedef struct tinywii_device_callback {
    void (*hci_send_packet)(uint8_t *data, size_t len);
    void (*hci_recv_packet)(uint8_t *data, size_t len);
} TwHciInterface;

// typedef struct {
//         size_t len;
//         uint8_t data[];
// } queuedata_t;
// #define RX_QUEUE_SIZE 32
// #define TX_QUEUE_SIZE 32
// extern xQueueHandle rxQueue;
// extern xQueueHandle txQueue;

void TinyWiimoteInit(TwHciInterface hciInterface);
int TinyWiimoteAvailable(void);
TinyWiimoteData TinyWiimoteRead(void);

void TinyWiimoteResetDevice(void);
bool TinyWiimoteDeviceIsInited(void);
void handleHciEvent(uint8_t event_code, uint8_t len, uint8_t* data);
void handleAclData(uint8_t* data, size_t len);
void handleHciData(uint8_t* data, size_t len);

// void handleRxQueue(void);
// void handleTxQueue(void);

char* format2Hex(uint8_t* data, uint16_t len);

#endif // _TINY_WIIMOTE_H_
