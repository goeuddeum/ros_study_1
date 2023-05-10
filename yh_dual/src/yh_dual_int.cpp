#include "ros/ros.h" //ros
#include "yh_dual/YhDual.h" //string message

void msgCallback(const yh_dual::YhDual::ConstPtr& msg)
{
    ROS_INFO("data: %d", msg->data);
}

int main(int argc, char** argv)
{
ros::init(argc, argv, "yh_dual_time"); //노드 이름 초기화
ros::NodeHandle nh; //노드 핸들 선언

ros::Subscriber sub = nh.subscribe("yh_dual_topic",100,msgCallback);      


ros::spin();     

return 0;     

}