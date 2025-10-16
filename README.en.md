# 🖥️ Motion Capture Alert

**🌐 Choose language: Ընտրեք լեզուն:** 

[🇦🇲 Հայերեն](README.md) | [🇬🇧 English](README.en.md)

---

**Motion Capture Alert** is a project designed for motion detection and user notification when changes are detected in frames captured from a camera connected to the computer.  

The project combines **C++** and **C#** to ensure high-performance frame processing and seamless communication with the user.

---

## ⚙️ Main Idea

- The camera continuously captures frames using all files included in the project.  
- Each new frame is compared with previous ones.  
- If a change is detected over several consecutive comparisons:  
  - Frames are saved on the computer.  
  - A notification is sent to the user's email.  

> **Note:** All necessary files for camera operation are included in the project; no additional downloads are required.

---

## 🧩 Project Structure

| Part | Description |
|------|----------------|
| **C++ module** | Responsible for reading frames from the camera, converting them to RGB matrices, and calculating differences between frames. |
| **C# module** | Receives data from the C++ module and sends email notifications to the user. |
| **Linux libraries** | Used for capturing and processing frames. |
| **Custom algorithms** | Frame comparison and difference detection implemented without external libraries. |

---

## 🧠 Key Features

- Real-time motion detection  
- Intelligent frame comparison to reduce false alerts  
- Automatic storage of detected frames  
- Email notifications when motion is detected  

---

## 🛠️ Installation and Usage

1. Connect the camera to your computer.  
2. Open the project in a Linux environment.  
3. Ensure C++ and C# compilers are installed.  
4. Build the project using the **makefile**:

```bash

# Build and run
make
./motion_capture_alert

# The program starts monitoring the camera
# If motion is detected:
# - Frames are saved in ./captured_frames/
# - User receives an email notification

