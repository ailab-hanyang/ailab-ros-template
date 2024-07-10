#ifndef __AI_HPP__
#define __AI_HPP__
#pragma once

#include "ros/ros.h"
#include "std_msgs/UInt16.h"

class ClassExample1 {
public:
    ClassExample1();
    ~ClassExample1();

private:
    // Node Init
    ros::NodeHandle m_nh;

    // Publisher
    ros::Publisher m_aiPub;

    // Subscriber
    ros::Subscriber m_labSub;

    // Inputs
    std_msgs::UInt16 m_i_lab;

    // Outputs
    std_msgs::UInt16 m_o_ai;

    // Member variable
    unsigned int count = 0;

public:
    // Callback Function
    void getCallback(const std_msgs::UInt16::ConstPtr &msg);

    // Algorithm
    void function();    
};

#endif