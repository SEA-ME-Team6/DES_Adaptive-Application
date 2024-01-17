# DES_Adative-Application

## **Project Overview**

The objective of this project is to develop an application (ADAS) based on the AUTOSAR Adaptive Platform that communicates with the previously developed Piracer Head Unit application.
</br>
</br>

## **Background Information**

In the automotive industry, a new paradigm has emerged with the formation of electric vehicles and autonomous driving. This has led to unprecedented convergence of IT technologies in the automotive field, particularly in areas such as In-Vehicle-Infotainment (IVI), Advanced Driver Assistance System (ADAS), and Vehicle-to-X (V2X). To overcome the limitations of the traditional AUTOSAR Classic Platform and meet the requirements of future automotive functionalities, the AUTOSAR Adaptive Platform has been defined.
</br>
</br>

## **Technical Requirements**

- Develop **AUTOSAR Adaptive Applications(LKAS, PDC)** using Matlab/Simulink.
- Execute applications on a Raspberry Pi, including the **AUTOSAR Adaptive Platform**.
- Add ADAS Application Interface to the **Head Unit**.
- External communication between two Raspberry Pis using **SOME/IP-based Ethernet**.
- Use of **Yocto** as the build system for the Raspberry Pi image.
</br>


## **System Architecture**

Two Raspberry Pis are employed: one for the existing project's extension, serving as the Head Unit and Piracer operation, and the other including the Adaptive Platform for executing the ADAS Application.

The ADAS App can be activated through the Head Unit interface, and the signal is transmitted via SOME/IP external communication to another Raspberry Pi, determining the activation status of the ADAS Application.

On the Raspberry Pi with the Adaptive Platform, the selected ADAS Application is activated, and ultimately, the control value is transmitted to the Raspberry Pi connected to Piracer via SOME/IP external communication.
</br>

![System Structure](https://github.com/SEA-ME-Team6/DES_Adative-Application/assets/106136905/68134ff2-53bd-4723-b158-2850ae3e43a1)

</br>
</br>

## **Implementation**

1. Develop AUTOSAR Adaptive Application using Matlab/Simulink.
2. Establish AUTOSAR Platform and integrate it with the Application.
3. Add ADAS Interface to the Head Unit.
4. Implement SOME/IP-based Ethernet external communication between the two Raspberry Pis.
