#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int8

class talker():
    def __init__(self):
        rospy.init_node("arduino_pub", anonymous=True)
        self.pub = rospy.Publisher("to_arduino", Int8, queue_size=10)
        self.message = 8
        rospy.loginfo("publisher_started to publish >> to_arduino")
    def publish(self , msg=5):
        self.pub.publish(msg)
        rospy.loginfo(msg)



if __name__ == "__main__":
    tk = talker()
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        tk.publish()
        rate.sleep()
