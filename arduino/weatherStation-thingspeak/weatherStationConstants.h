#ifndef weatherStationConstants_hpp
#define weatherStationConstants_hpp

const int HH10D_OFFSET(7732);
const int HH10D_SENSITIVITY(402);

const float ELEVATION_IN_METERS(62.7);

// Ethernet library does not take const inputs so we cannot make this const
byte MAC_ADDRESS[] = {0x13, 0xdb, 0x29, 0x54, 0xde, 0xb9};

const unsigned long THINGSPEAK_CHANNEL(????);
const char* THINGSPEAK_API_KEY("API_KEY");

const unsigned long LOOP_DELAY(1000 * 60 * 5);

#endif
