#include "lab.hpp"

#define PLUS 1
#define MINUS 2
#define MULTIPLICATION 3
#define DIVISION 4
 
////////////////////////////////////////////

ClassExample2::ClassExample2() {
    // Publisher Init
    m_labPub =
            m_nh.advertise<std_msgs::UInt16>("lab", 1000);

    // Subscirber Init
    m_aiSub =
            m_nh.subscribe("ai", 1000, &ClassExample2::getCallback, this);

    // Parameter
    m_nh.param("lab/calculation_method", m_p_method, 1);
    m_nh.param("lab/calculation_number", m_p_number, 1000);
}
ClassExample2::~ClassExample2() {}

// Callback Function
void ClassExample2::getCallback(const std_msgs::UInt16::ConstPtr &msg)
{
  ROS_WARN("LAB GET: [%d]", msg->data);

  switch (m_p_method) {
    case PLUS:
      m_i_ai.data = msg->data + m_p_number;
      break;
    case MINUS:
      m_i_ai.data = msg->data - m_p_number;
      break;
    case MULTIPLICATION:
      m_i_ai.data = msg->data * m_p_number;
      break;
    case DIVISION:
      if (m_p_number == 0) {
        m_i_ai.data = 0;
      } else {
        m_i_ai.data = msg->data / m_p_number;
      }
      break;
  }
}

// Algorithm
void ClassExample2::function() {
    // Algorithm
    m_o_lab.data = m_i_ai.data;
    
    // Publish
    m_labPub.publish(m_o_lab);
}    

int main(int argc, char **argv) {
    ros::init(argc, argv, "lab");

    ClassExample2 class_example2_obj;

    // Loop Rate
    ros::Rate loop_rate(10);

    while (ros::ok()) {
        class_example2_obj.function();

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}