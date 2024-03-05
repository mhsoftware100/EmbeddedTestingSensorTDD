# EmbeddedTestingSensorTDD
This is a simple test-driven project for an embedded system, demonstrating the interaction with a temperature sensor using the I2C interface. The project includes a temperature sensor driver (sensor.c and sensor.h) and I2C functions (i2c.c and i2c.h), with unit tests implemented using the Unity test framework.


## How to Use

#### Install Make:
Ensure that Make is installed on your Linux system. You can install it using the package manager specific to your distribution. For example, on Debian/Ubuntu-based systems, you can run:
''''
sudo apt-get install make
''''

#### Compile the Project:
Navigate to the project directory and run the following command to compile the project:
''''
make
''''

#### Run Tests:
Execute the following command to run the unit test cases:
''''
make test.
''''

Feel free to explore the code and modify it according to your requirements. If you encounter any issues or have questions, don't hesitate to reach out. Happy coding!