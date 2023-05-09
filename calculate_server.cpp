#include "ros/ros.h"
#include "param_tutorial/Calculate.h"//서비스 헤더 파일
                                        //빌드 시 자동 생성
#define PLUS 1
#define MINUS 2
#define MULTIPLICATION 3
#define DIVISION 4

int my_operator= PLUS;

bool calculation(param_tutorial::Calculate::Request& req,
                param_tutorial::Calculate::Response& res)
{
    switch (my_operator)
    {
        case PLUS:
            res.result = req.a + req.b;
            break;
        case MINUS:
            res.result = req.a - req.b;
            break;
        case MULTIPLICATION:
            res.result = req.a * req.b;
            break;
        case DIVISION:
            res.result = req.a / req.b;
            break;
    }
    ROS_INFO("a: %d, b: %d, result :%d", req.a, req.b, res.result);
    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc,argv,"calculate_server");
    ros::NodeHandle nh;
    //파라미터 서버에 있는 변수의 값을 설정
    nh.setParam("calculation_method", PLUS); //파라미터 값 초기 설정

    ros::ServiceServer server = nh.advertiseService("calculate",calculation);

    ros::Rate loop_rate(10);

    ROS_INFO("Calculate server ready.");

    while (ros::ok())
    {
        nh.getParam("calculation_method", my_operator); //파리미터 값 읽기
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
