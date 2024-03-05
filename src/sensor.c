/*
 * Sensor Device Driver
 * Source File
 * Author: Mahmood Hosseini
 * Date: March 2024
 */

#include "sensor.h"


status_t sensor_init(sensor_t *sensor) {
    sensor->bus_address = DEVICE_SENSOR_ADDRESS;
    // Perform any additional initialization if needed
    return STATUS_OK;
}

status_t sensor_get_temp(sensor_t *sensor, uint8_t *temp) {
    status_t status = i2c_read(sensor->bus_address, SENSOR_REG_TEMP, 1, temp);

    return status;
}

status_t sensor_set_setting(sensor_t *sensor, uint8_t setting) {
   uint8_t current_ctrl_reg;

     // Read the current value of CTRL_REG
    status_t read_status = i2c_read(sensor->bus_address, SESNOR_REG_CTRL, 1, &current_ctrl_reg);

    if (read_status == STATUS_OK) {
        // Modify the setting bits
		
        // Write the updated value back to CTRL_REG
        return i2c_write(sensor->bus_address, SESNOR_REG_CTRL, 1, &current_ctrl_reg);
    } else {
        return read_status;  // Return the read status if reading fails
    }
}
