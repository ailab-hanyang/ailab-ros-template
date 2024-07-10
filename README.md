# ailab-ros-template
ailab ros template for beginner

## 사전 요구 사항

- ROS Noetic (또는 시스템과 호환되는 다른 버전)
- Catkin 작업 공간 설정

## 패키지 구조
```bash
ailab-ros-template/
├── CMakeLists.txt
├── package.xml
├── include/
│ ├── ai.hpp
│ └── lab.hpp
├── src/
│ ├── ai.cpp
│ └── lab.cpp
└── README.md 
```
## 설치

```bash
# Workspace 제작
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src
# src 내부에 git clone
git clone https://github.com/ailab-konkuk/ailab-ros-template.git
# Build and Source bash
catkin_make
source devel/setup.bash
```
## 실행
### rosrun을 사용할 경우
```bash
roscore
rosrun ailab_ros_template ai
rosrun ailab_ros_template lab
```
### roslaunch를 사용할 경우
```bash
roslaunch ailab_ros_template ailab.launch
```
