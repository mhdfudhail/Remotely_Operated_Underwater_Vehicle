#!/usr/bin/env
import rospy
from std_msgs.msg import Int8

class listner():
    def __init__(self):
        rospy.init_node("sub_arduino", anonymous=True)
        self.message = ""
    def subscribe(self):
        rospy.Subscriber("/from_arduino", Int8, self.callback)
    def callback(self,msg):
        self.message = msg.data
        rospy.loginfo("Recieved data: %s", self.message)

if __name__ == '__main__':
    lst = listner()
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        lst.subscribe()
        rate.sleep()
