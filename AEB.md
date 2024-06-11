# 

### Autonomous Emergency Braking

 which is a key feature in Advanced Driver Assistance Systems (ADAS). Also known as Autonomous Emergency Braking  AEB systems are designed to enhance vehicle safety by automatically applying the brakes to prevent or mitigate collisions with obstacles

we implemented Autonomous Emergency Braking (AEB) using ultrasonic sensor which  involves several steps, including sensor data acquisition, and braking control. Here's a basic outline of how we implemented it:

(AEB model image)

1. **Sensor Data Acquisition**:
    - Connect and configure the ultrasonic sensor to interface with Simulink.
    - Read distance measurements from the sensor to detect obstacles or other vehicles in the vehicle's path.
2. **Autonomous Braking Intervention**:
    - If the distance exceeds a certain threshold engage the vehicle's braking system to stop the vehicle.
