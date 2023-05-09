#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from param_tutorial.srv import Calculate, CalculateRequest
import sys

if __name__== "__main__":
    rospy.init_node("calculate_client")

    if len(sys.argv) !=3 :
        rospy.loginfo("rosrun param_tutorial calculate_client.py a b")
        rospy.loginfo("a, b: int32 number")
        sys.exit(1)

    client = rospy.ServiceProxy("calculate", Calculate)

    req= CalculateRequest()
    req.a=int(sys.argv[1])
    req.b=int(sys.argv[2])

    try:
        response = client(req)
    except rospy.ServiceException as e:
        rospy.logerr("Failed : %s", e)
    else:
        rospy.loginfo(f"a: {req.a},b:{req.b},result:{response.result}")
