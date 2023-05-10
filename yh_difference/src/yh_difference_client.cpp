#include "ros/ros.h"
#include "yh_difference/YhDifference.h"
#include<cstdlib>
int main(int argc, char** argv)
{
    ros::init(argc, argv,"yh_difference_client");

    if(argc != 3)
    {
        ROS_INFO("rosrun yh_difference yh_difference_client a b");
        ROS_INFO("a, b: int32 number");
        return 1;
    }

    ros::NodeHandle nh;
    //서비스 클라이언트(yh_difference_client)를 선언한다
    //서비스 이름은(yh_difference_service)이고, 패키지 (service_tutorial)의 (YhDifference)서비스 파일을 사용한다.
    ros::ServiceClient client =nh.serviceClient<yh_difference::YhDifference>("yh_difference_service");

    yh_difference::YhDifference srv;
    srv.request.a=atoi(argv[1]);
    srv.request.b=atoi(argv[2]);

    if(client.call(srv))
    {
        ROS_INFO("result: %d", srv.response.result);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }
    return 0;
}
