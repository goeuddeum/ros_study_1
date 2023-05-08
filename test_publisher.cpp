#include "ros/ros.h" 
#include "std_msgs/Int64.h" 

int main(int argc, char** argv){
	ros::init(argc, argv, "my_test_publisher"); 
	ros::NodeHandle nh; 

	ros::Publisher pub = nh.advertise<std_msgs::Int64>("my_topic",100);
	
	ros::Rate loop_rate(4); 
	std_msgs::Int64 msg;
	msg.data=0; 
	
	while(ros::ok()){
		pub.publish(msg);
        msg.data++;
        loop_rate.sleep();
        if(msg.data>15) msg.data=0;
	}
	return 0;
}