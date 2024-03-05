/*
 * Sensor Device Driver
 * Header File
 * Author: Mahmood Hosseini
 * Date: March 2024
 */

#ifndef SENSOR_HEADER_H
#define SENSOR_HEADER_H

#include "i2c.h"


/* SENSOR I2C device address */
#define DEVICE_SENSOR_ADDRESS (uint8_t)0x1f  


// Constants for SENSOR registers
#define SESNOR_REG_CTRL     0x01
#define SENSOR_REG_TEMP     0x02


typedef struct {
    uint8_t bus_address;
} sensor_t;


status_t sensor_init(sensor_t *sensor);
status_t sensor_get_temp(sensor_t *sensor, uint8_t *temp);
status_t sensor_set_setting(sensor_t *sensor, uint8_t setting);


#endif
