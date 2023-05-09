#include "ros/ros.h"
#include "service_tutorial/AddTwoInts.h"
#include<cstdlib>
int main(int argc, char** argv)
{
    ros::init(argc, argv,"client_second");

    if(argc != 3)
    {
        ROS_INFO("command: rosrun servic_second client_second arg1 arg2");
        ROS_INFO("arg1, arg2: int32 number");
        return 1;
    }

    ros::NodeHandle nh;
    //서비스 클라이언트(client_second)를 선언한다
    //서비스 이름은(mul_two_ints)이고, 패키지 (service_tutorial)의 (AddTwoInts)서비스 파일을 사용한다.
    ros::ServiceClient client =nh.serviceClient<service_tutorial::AddTwoInts>("mul_two_ints");

    service_tutorial::AddTwoInts srv;
    srv.request.a=atoi(argv[1]);
    srv.request.b=atoi(argv[2]);

    if(client.call(srv))
    {
        ROS_INFO("request: a=%d", srv.request.a, srv.request.b);
        ROS_INFO("response: result=%d", srv.response.result);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }
    return 0;
}

