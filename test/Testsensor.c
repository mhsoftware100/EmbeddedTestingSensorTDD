/*
 * Sensor Device Driver
 * Test File
 * Author: Mahmood Hosseini
 * Date: March 2024
 */

#include "sensor.h"
#include "unity.h"


// Global sensor variable
static sensor_t sensor;

void setUp(void) {
    // Initialize the sensor
    sensor_init(&sensor);
}

void tearDown(void) {
    // None
}


void test_get_temperature(void) {
    uint8_t temp;

    // Call the function to get output temperature sensor
    TEST_ASSERT_EQUAL(STATUS_OK, sensor_get_temp(&sensor, &temp));

    TEST_ASSERT_EQUAL(0xff, temp);
}

void test_set_setting(void) {
    uint8_t setting = 0x10; // Example value for testing

    TEST_ASSERT_EQUAL(STATUS_OK, sensor_set_setting(&sensor, setting));
}



int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_get_temperature);
    RUN_TEST(test_set_setting);
  

    UNITY_END();
    return 0;
}
