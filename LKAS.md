### **Lane Keeping Assist System:**

LKAS is a feature designed to assist drivers in keeping their vehicle within its lane while driving on highways or other roads. The system uses cameras to detect lane markings and monitors the vehicle's position within the lane. If it detects that the vehicle is drifting out of its lane without the driver signaling, it can intervene by applying corrective steering inputs to gently nudge the vehicle back into the center of the lane.

The sliding window algorithm is used to build  Lane Keeping Assist System (LKAS) in MATLAB involves several steps, including lane detection, lane tracking, and steering control. Here's a basic outline of how we implemented it:

(Image of LKAS Mode)

1. **Lane Detection**:
    - Capture real-time video using a picamera.
    - Preprocess the frames (e.g., convert RGB to HSV, Warp Transformation) to enhance lane markings.
    - Implement the sliding window algorithm to detect lane markings within the image.
    - This involves dividing the image into horizontal slices and searching for lane markings within each slice using sliding windows. The difference between the position of the vehicle and the center of the lane is output.
2. **Steering Control**:
    - Determine the steering angle correction required to keep the vehicle centered within the lane. This can be based on the lateral offset calculated in the previous step.
    - Implement a control law to convert the lateral offset into a steering angle. Use PID control to determine the final steering angle.
    - Apply the calculated steering angle to the vehicle's steering system to control the direction of the vehicle and keep it within the lane.
