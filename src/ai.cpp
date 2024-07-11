#include "ai.hpp"

////////////////////////////////////////////


ClassExample1::ClassExample1() {
    // Publisher Init
    m_aiPub =
            m_nh.advertise<std_msgs::UInt16>("ai", 1000);

    // Subscirber Init
    m_labSub =
            m_nh.subscribe("lab", 1000, &ClassExample1::getCallback, this);

    // Parameter

}

ClassExample1::~ClassExample1() {}

// Callback Function
void ClassExample1::getCallback(const std_msgs::UInt16::ConstPtr &msg)
{
    ROS_INFO("AI GET: [%d]", msg->data);
    m_i_lab.data = msg->data;
}

// Algorithm
void ClassExample1::function() {
    // Algorithm
    m_o_ai.data = count++;

    // Publish
    m_aiPub.publish(m_o_ai);

    ROS_INFO("AI SEND: [%d]", m_o_ai.data);
}    


int main(int argc, char **argv) {
    ros::init(argc, argv, "ai");

    ClassExample1 class_example1_obj;

    // Loop Rate
    ros::Rate loop_rate(10);

    while (ros::ok()) {
        class_example1_obj.function();

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}