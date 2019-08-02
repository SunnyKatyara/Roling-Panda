#!/usr/bin/env python
import rospy
from geometry_msgs.msg import PoseArray, Pose

if __name__ == '__main__':
    rospy.init_node('pose_array')
    pub = rospy.Publisher("/cartesian/panda_right_mount_link/wp", PoseArray)
    while not rospy.is_shutdown():
        poseArray = PoseArray()
        poseArray.header.stamp = rospy.Time.now()
        poseArray.header.frame_id = "ci/world_odom"
        for i in range(1, 5):
            somePose = Pose()
            somePose.position.x = 0.8
            somePose.position.y = 0.7
            somePose.position.z = i

            somePose.orientation.x = 0.0
            somePose.orientation.y = 0.0
            somePose.orientation.z = 0.0
            somePose.orientation.w = 1.0

            poseArray.poses.append(somePose)

        pub.publish(poseArray)
