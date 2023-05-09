#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy 
from param_tutorial.srv import Calculate, CalculateResponse

PLUS = 1
MINUS = 2
MULTIPLICATION = 3
DIVISION = 4

def calculation(req):
    my_operator = rospy.get_param("calculation_method")
    if my_operator ==PLUS:
        result = req.a + req.b
    elif my_operator == MINUS:
        result = req.a - req.b
    elif my_operator == MULTIPLICATION:
        result = req.a * req.b
    elif my_operator == DIVISION:
        result = req.a / req.b

    rospy.loginfo(f"a: {req.a}, b:{req.b}, result: {result}")
    response = CalculateResponse()
    response.result = result
    return response

if __name__ == "__main__":
    rospy.init_node("calculate_server")

    rospy.set_param("calculation_method", PLUS)

    server = rospy.Service("calculate", Calculate, calculation)
    rospy.loginfo("Calcuate sever ready.")
    rospy.spin()