#ifndef __LAB_HPP__
#define __LAB_HPP__
#pragma once

#include "ros/ros.h"
#include "std_msgs/UInt16.h"

class ClassExample2 {
public:
    ClassExample2();
    ~ClassExample2();

private:
    // Node Init
    ros::NodeHandle m_nh;

    // Publisher
    ros::Publisher m_labPub;

    // Subscriber
    ros::Subscriber m_aiSub;

    // Inputs
    std_msgs::UInt16 m_i_ai;

    // Outputs
    std_msgs::UInt16 m_o_lab;

    // Member variable
    bool m_is_ai = false;
    int m_p_method = 0;
    int m_p_number = 0;

public:
    // Callback Function
    void getCallback(const std_msgs::UInt16::ConstPtr &msg);

    // Algorithm
    void function();    
};

#endif