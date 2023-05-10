#include "ros/ros.h" //ros
#include "yh_dual/YhDual.h" //string message

int main(int argc, char** argv){
ros::init(argc, argv, "yh_dual_pub"); //노드 이름 초기화
ros::NodeHandle nh; // ros와 통신을 위한 핸들 선언

//퍼블리셔 선언    
//패키지(std_msgs)의 메시지파일(String)을 이용한 퍼ㅡㄹ리셔(pub)를 만든다    
//토픽은(my_topic), 퍼블리셔큐(queue)사이즈는 (100)   
ros::Publisher pub = nh.advertise<yh_dual::YhDual>("yh_dual_topic",100);   

ros::Rate loop_rate(8); //10Hz 루프    

yh_dual::YhDual msg;   
msg.data=0; // msg 에 Hello 넣음    

while(ros::ok()){    
    msg.stamp= ros::Time::now();
	pub.publish(msg);    
	loop_rate.sleep();	  
    msg.data++;
}    
return 0;   

}