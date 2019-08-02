#!/usr/bin/env python
import rospy
import actionlib
from actionlib import SimpleActionClient
from actionlib_msgs.msg import *
from actionlib.msg import *
from cartesian_interface.msg import ReachPoseAction, ReachPoseGoal

def feedback_cb(msg):
    print 'feedback recieved:', msg

# Starting with the clinet
def call_server():
    
    client = actionlib.SimpleActionClient('/cartesian/panda_right_mount_link/reach', ReachPoseAction)
    client.wait_for_server()

    goal = ReachPoseGoal()
    goal.frames = 'ci/world_odom'
    goal.time = 5
    goal.incremental = 'false'

    client.send_goal(goal, feedback_cb=feedback_cb)
    client.wait_for_result()

    result = client.get_result()
    return result

if __name__ == '__main__':
    
    try:
       rospy.init_node('move_panda')
       
       result= call_server()
       
       print 'The result is:', result
    
    except rospy.ROSInterruptException as e:
       print 'Something went wrong:', e







 


