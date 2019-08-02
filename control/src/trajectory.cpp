#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <cstdlib>
#include <trajectory_msgs/JointTrajectoryPoint.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

sensor_msgs::JointState JS;

  string 
  float joint_position[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
  float joint_velocity[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
  float joint_acceleration = 0.01;
  float joint_effort = 0.001;


void jointStateCallback(const sensor_msgs::JointState msg) 
{ 

  joint_position[0]=msg.position[0];
  joint_position[1]=msg.position[1];
  joint_position[2]=msg.position[2];
  joint_position[3]=msg.position[3];
  joint_position[4]=msg.position[4];
  joint_position[5]=msg.position[5];
  joint_position[6]=msg.position[6];
  joint_position[7]=msg.position[7];
  joint_position[8]=msg.position[8];
  joint_position[9]=msg.position[9];
  joint_position[10]=msg.position[10];
  joint_position[11]=msg.position[11];
  joint_velocity[0]=msg.velocity[0];
  joint_velocity[1]=msg.velocity[1];
  joint_velocity[2]=msg.velocity[2];
  joint_velocity[3]=msg.velocity[3];
  joint_velocity[4]=msg.velocity[4];
  joint_velocity[5]=msg.velocity[5];
  joint_velocity[6]=msg.velocity[6];
  joint_velocity[7]=msg.velocity[7];
  joint_velocity[8]=msg.velocity[8];
  joint_velocity[9]=msg.velocity[9];
  joint_velocity[11]=msg.velocity[10];
  joint_velocity[12]=msg.velocity[12];
}


int main(int argc, char** argv) { 
  ros::init(argc, argv, "mover_node");

  ros::NodeHandle n;
  ros::AsyncSpinner spinner(1);
  spinner.start();

  bool success;

  ros::Publisher joint_pub = n.advertise<trajectory_msgs::JointTrajectory>("/panda/panda_arm_controller/command", 10, true);
  ros::Subscriber joint_sub = n.subscribe<sensor_msgs::JointState>("/catersian/solution", 1, jointStateCallback);

  trajectory_msgs::JointTrajectory JT;
  
  JT.joint_names.resize(12);
  JT.joint_names[0] = "panda_joint_x";
  JT.joint_names[1] = "panda_joint_y";
  JT.joint_names[2] = "panda_joint_theta";
  JT.joint_names[3] = "schunk_pw70_joint_pan";
  JT.joint_names[4] = "schunk_pw70_joint_tilt";
  JT.joint_names[5] = "panda_joint_1";
  JT.joint_names[6] = "panda_joint_2";
  JT.joint_names[7] = "panda_joint_3";
  JT.joint_names[8] = "panda_joint_4";
  JT.joint_names[9] = "panda_joint_5";
  JT.joint_names[10] = "panda_joint_6";
  JT.joint_names[11] = "panda_joint_7";

  JT.points.resize(2);
  JT.points[0].positions.resize(JT.joint_names.size());
  JT.points[1].positions.resize(JT.joint_names.size());

  while(ros::ok()) {

    if(JS.position.size() != 0)
    {
      cout << JT << endl;

      JT.points[0].time_from_start = ros::Duration(0.0001);
      JT.points[0].positions = JS.position;
      
      JT.points[1].positions.resize(12);
      JT.points[1].positions[0] = joint_position[0];
      JT.points[1].positions[1] = joint_position[1];
      JT.points[1].positions[2] = joint_position[2];
      JT.points[1].positions[3] = joint_position[3];
      JT.points[1].positions[4] = joint_position[4];
      JT.points[1].positions[5] = joint_position[5];
      JT.points[1].positions[6] = joint_position[6];
      JT.points[1].positions[7] = joint_position[7];
      JT.points[1].positions[8] = joint_position[8];
      JT.points[1].positions[9] = joint_position[9];
      JT.points[1].positions[10] = joint_position[10];
      JT.points[1].positions[11] = joint_position[11];
      JT.points[1].time_from_start = ros::Duration(1);
      JT.points[1].velocities.resize(12);
      JT.points[1].velocities[0] = joint_velocity[0];
      JT.points[1].velocities[1] = joint_velocity[1];
      JT.points[1].velocities[2] = joint_velocity[2];
      JT.points[1].velocities[3] = joint_velocity[3];
      JT.points[1].velocities[4] = joint_velocity[4];
      JT.points[1].velocities[5] = joint_velocity[5];
      JT.points[1].velocities[6] = joint_velocity[6];
      JT.points[1].velocities[7] = joint_velocity[7];
      JT.points[1].velocities[8] = joint_velocity[8];
      JT.points[1].velocities[9] = joint_velocity[9];
      JT.points[1].velocities[10] = joint_velocity[10];
      JT.points[1].velocities[11] = joint_velocity[11];
      JT.points[1].time_from_start = ros::Duration(1);
      JT.points[1].accelerations.resize(12);
      JT.points[1].accelerations[0] = joint_acceleration;
      JT.points[1].accelerations[1] = joint_acceleration;
      JT.points[1].accelerations[2] = joint_acceleration;
      JT.points[1].accelerations[3] = joint_acceleration;
      JT.points[1].accelerations[4] = joint_acceleration;
      JT.points[1].accelerations[5] = joint_acceleration;
      JT.points[1].accelerations[6] = joint_acceleration;
      JT.points[1].accelerations[7] = joint_acceleration;
      JT.points[1].accelerations[8] = joint_acceleration;
      JT.points[1].accelerations[9] = joint_acceleration;
      JT.points[1].accelerations[10] = joint_acceleration;
      JT.points[1].accelerations[11] = joint_acceleration;
      JT.points[1].time_from_start = ros::Duration(1);
      JT.points[1].effort.resize(12);
      JT.points[1].effort[0] = joint_effort;
      JT.points[1].effort[1] = joint_effort;
      JT.points[1].effort[2] = joint_effort;
      JT.points[1].effort[3] = joint_effort;
      JT.points[1].effort[4] = joint_effort;
      JT.points[1].effort[5] = joint_effort;
      JT.points[1].effort[6] = joint_effort;
      JT.points[1].effort[7] = joint_effort;
      JT.points[1].effort[8] = joint_effort;
      JT.points[1].effort[9] = joint_effort;
      JT.points[1].effort[10] = joint_effort;
      JT.points[1].effort[11] = joint_effort;
      JT.points[1].time_from_start = ros::Duration(1);

      joint_pub.publish(JT);
    }
  } 
  ros::shutdown();

  return 0;
}
