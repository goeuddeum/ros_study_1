#include "ros/ros.h"
#include "service_tutorial/AddTwoInts.h"//서비스 헤더 파일
                                        //빌드 시 자동 생성

//서비스 요청이 있을 경우 샐행되는 함수
//서비스 요청은 req, 서비스 응답은 res로 사용
bool mul_two_ints(service_tutorial::AddTwoInts::Request& req,
                service_tutorial::AddTwoInts::Response& res)
{
    res.result = req.a * req.b;
    ROS_INFO("request: a = %d, b = %d", req.a, req.b);
    ROS_INFO("response: result=%d", res.result);
    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "server_second");
    ros::NodeHandle nh;
    
    //서비스 서버(server_second)를  선언한다.
    //서비스 이름은(mul_two_ints)이고, 요청이 왔을 때 콜백함수 (mul_two_ints)를 실행한다.
    //(service_tutorial) 패키지의 (AddTwoInts) 서비스 파일을 이용한다.
    ros::ServiceServer server = nh.advertiseService("mul_two_ints", mul_two_ints);
    
    ROS_INFO("Service server ready.");

    ros::spin();
}
                                