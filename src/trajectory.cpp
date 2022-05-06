#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <trajectory_msgs/MultiDOFJointTrajectory.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "test_publish");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<trajectory_msgs::MultiDOFJointTrajectory>("/red/tracker/input_trajectory", 50);
    ros::Rate r(10);
    trajectory_msgs::MultiDOFJointTrajectory tj;
    trajectory_msgs::MultiDOFJointTrajectory tt;
    tj.header.frame_id = "base_link";
    tj.points.resize(7);
    tj.points[0].transforms.resize(10);
    tj.points[1].transforms.resize(10);
    tj.points[2].transforms.resize(10);
    tj.points[3].transforms.resize(10);
    tj.points[4].transforms.resize(10);
    tj.points[5].transforms.resize(10);
    tj.points[6].transforms.resize(10);
    tj.points[7].transforms.resize(10);

    for(int q=0;q<10;q++)
    {
        tj.points[0].transforms[q].translation.z = 2 + q;
    }
    
   
    for(int j=0;j<10;j++)
    {
        tj.points[1].transforms[j].translation.z = 11;
        tj.points[1].transforms[j].translation.x = (j+1)*-1;
        tj.points[1].transforms[j].translation.y = j+1;

    }
    
    
    for(int k=0;k<10;k++)
    {
        tj.points[2].transforms[k].translation.x = -10;
        tj.points[2].transforms[k].translation.y = 10;
        tj.points[2].transforms[k].translation.z = 11 - k;
    }

    for(int l=0;l<10;l++)
    {
        tj.points[3].transforms[l].translation.x = -10;
        tj.points[3].transforms[l].translation.y = 10;
        tj.points[3].transforms[l].translation.z = 2 + l;
    }
    
    for(int m=0;m<10;m++)
    {
        tj.points[4].transforms[m].translation.z = 11;
        tj.points[4].transforms[m].translation.x = (9-m)*-1;
        tj.points[4].transforms[m].translation.y = 9-m;

    }
    for(int n=0;n<10;n++)
    {
        tj.points[5].transforms[n].translation.z = 11 - n;
    }

    for(int o=0;o<10;o++)
    {
        tj.points[6].transforms[o].translation.z = 2+o;
    }

    ROS_INFO("ROM: Preparing trajectory points.");
    
    for(int i=1;i<6;i++) {  
        if (i<4) { pub.publish(tt); }
        else { pub.publish(tj); ROS_INFO("ROM: Publishing MultiDOFJointTrajectory."); }
        ros::spinOnce();
        r.sleep();
    }
    
    ros::Duration(50.0).sleep();
    ROS_INFO("ROM: Shutdown node.");
    ros::shutdown();
    
    return 0;
}