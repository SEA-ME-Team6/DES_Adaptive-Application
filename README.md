# DES_Adaptive-Application

### Images & Introduction
![IMG_9783](https://github.com/SEA-ME-Team6/DES_Adaptive-Application/assets/106136905/475b990c-e120-4c40-bc05-60da683e9e58)
This project aims to develop an Advanced Driver Assistance System (ADAS) application based on the AUTOSAR Adaptive Platform. The ADAS application will communicate with an existing Piracer Head Unit application, enabling enhanced functionality and integration within the automotive system.

### Key Concepts

1. **Developing AUTOSAR Adaptive Applications**: This involves creating Adaptive AUTOSAR applications for functions like Lane Keeping Assist System (LKAS) and Autonomous Emergency Braking(AEB) using **MATLAB/Simulink**.
2. **Adaptive AUTOSAR Platform on Raspberry Pi**: The applications are executed on a Raspberry Pi platform, which serves as the platform for hosting the AUTOSAR Adaptive Platform and running the ADAS applications.
3. **Integration with Head Unit**: An ADAS Application Interface will be added to the existing Piracer Head Unit application to facilitate communication between the ADAS system and the vehicle's interface.
4. **External Communication via SOME/IP**: Communication between the two Raspberry Pis (one hosting the ADAS application and the other connected to the Piracer) will be established using SOME/IP-based Ethernet communication protocol. This enables the exchange of data and control signals between the two systems

### Adaptive AUTOSAR

Adaptive AUTOSAR refers to the latest iteration of the AUTOSAR (AUTomotive Open System ARchitecture) standard, which aims to address the increasing complexity of automotive software in modern vehicles. Unlike Classic AUTOSAR, which primarily focuses on embedded control units (ECUs) in traditional automotive electronic architectures, Adaptive AUTOSAR is designed for use in high-performance computing platforms, such as advanced driver assistance systems (ADAS), autonomous driving, and connected car applications.
</br>

### Adaptive AUTOSAR Application(ADAS)

Adaptive AUTOSAR finds applications across various domains within the automotive industry, particularly in vehicles requiring advanced computing capabilities and connectivity. among them one is ADAS 

**Advanced Driver Assistance Systems (ADAS)**: Adaptive AUTOSAR is instrumental in developing sophisticated ADAS functionalities such as adaptive cruise control, lane-keeping assistance, automatic emergency braking, and pedestrian detection. These systems rely on high-performance computing platforms and sensor fusion algorithms to enhance driver safety and convenience.

These are the two application we devoloped in this project with **Simulink**:  

**1. [LKAS](https://github.com/SEA-ME-Team6/DES_Adaptive-Application/blob/main/LKAS.md)**
</br>
**2. [AEB](https://github.com/SEA-ME-Team6/DES_Adaptive-Application/blob/main/AEB.md)**
</br>


Project Overview

![System Structure](https://github.com/SEA-ME-Team6/DES_Adative-Application/assets/106136905/68134ff2-53bd-4723-b158-2850ae3e43a1)
Two Raspberry Pis are employed: one for the existing project's extension, serving as the Head Unit and Piracer operation, and the other including the Adaptive Platform for executing the ADAS Application.

The ADAS App can be activated through the Head Unit interface, and the signal is transmitted via SOME/IP external communication to another Raspberry Pi, determining the activation status of the ADAS Application.

On the Raspberry Pi with the Adaptive Platform, the selected ADAS Application is activated, and ultimately, the control value is transmitted to the Raspberry Pi connected to Piracer via SOME/IP external communication.
</br>
</br>
