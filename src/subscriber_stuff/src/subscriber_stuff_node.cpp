#include <ros/ros.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv_stuff/MyImage.h>
#include <cv_bridge/cv_bridge.h>

void myCallback(const opencv_stuff::MyImage image)
{
    sensor_msgs::Image temp = image.image;
    cv_bridge::CvImagePtr cv_img;
    try
    {
        cv_img = cv_bridge::toCvCopy(temp, temp.encoding);
    }
    catch(cv_bridge::Exception& e)
    {
        ROS_ERROR("error: %s" , e.what());
        return;
    }

    cv::imshow("view", cv_img->image);
    cv::waitKey(30);

    ROS_INFO_STREAM("I got the message " << (int)image.imageId);
}

int main(int argv, char** argc)
{
    ros::init(argv, argc, "subscriber_stuff_node");
    ros::NodeHandle nh;

    ros::Rate loop_rate(10);

    ros::Subscriber sub = nh.subscribe("my_image", 1, myCallback);

    while(ros::ok())
    {
        ros::spinOnce();
        loop_rate.sleep();
    }

    //ros::spin();
}
