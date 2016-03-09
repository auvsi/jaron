#include <ros/ros.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <myVideoWriter.h>
#include <opencv_stuff/MyImage.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <string>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>


#include <opencv2/video/tracking.hpp>


int x,y;
cv::Point2f p(0,0);
cv::Point2f q(0,0);
cv::Mat xal;
cv::Mat frame2;
void drawimage()
{

//    ROS_INFO_STREAM("I got the message 2 " << (int)q.x << " " << (int)q.y);

    std::vector<cv::Point2f> points[2];
    points[0].push_back(q);


    std::vector<uchar> status;
    std::vector<float> err;

    cv::calcOpticalFlowPyrLK(
                xal,
                frame2,
                points[0],
                points[1],
                status,
                err
                );
    cv::Point2f how_far = points[1][0] - points[0][0];
    how_far *= 2;
//    q = points[1][0];
    q += how_far;
    cv::line(xal,cv::Point(q.x,q.y+5),cv::Point(q.x,q.y-5),cv::Scalar(0,0,255),2,8);
    cv::line(xal,cv::Point(q.x+5,q.y),cv::Point(q.x-5,q.y),cv::Scalar(0,0,255),2,8);
    cv::imshow("My Window", xal);

}

void CallBackFunc(int event, int x, int y, int flags, void *ptr )
{
    if ( event == cv::EVENT_LBUTTONDOWN )
    {
        //cv::Point*p = (cv::Point*)ptr;
        q.x = x;
        q.y = y;
        drawimage();

    }
    else if  ( event == cv::EVENT_RBUTTONDOWN )
    {
        //cv::Point*q = (cv::Point*)ptr;
        q.x = x;
        q.y = y;
        drawimage();


    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "opencv_stuff_node");
    ros::NodeHandle n;



    char *outText;
    
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }
    
    // Open input image with leptonica library
    Pix *image = pixRead("test.jpg");
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);

    // Destroy used object and release memory
    api->End();
    delete [] outText;
    pixDestroy(&image);

    return 0;


    std::vector<cv::Point> features_prev, features_next;

    cv::VideoCapture v1;
    v1.open(0);

    v1 >> xal;

    v1 >> frame2;

    ros::Publisher servo_pub = n.advertise<opencv_stuff::MyImage>("servo", 1);


    for(;;)
    {


        v1 >> xal;
        v1 >> frame2;


//    xal =cv::imread("/home/jaron/catkin_ws/src/opencv_stuff/f16.jpg", CV_LOAD_IMAGE_COLOR);
    //Create a window
    cv::namedWindow("My Window", 1);

    //set the callback function for any mouse event
    cv::setMouseCallback("My Window", CallBackFunc,&p);
    cv::setMouseCallback("My Window", CallBackFunc,&q);

    //show the image
//    cv::imshow("My Window", xal);
    drawimage();

    // Wait until user press some key
//    cv::waitKey(0);
    if(cv::waitKey(30) >= 0) break;

    }


//    ros::Publisher image_pub = n.advertise<opencv_stuff::MyImage>("my_image", 1);

//    cv::Mat image;
//    image = cv::imread("/home/jaron/catkin_ws/src/opencv_stuff/f16.jpg", CV_LOAD_IMAGE_COLOR);


//    opencv_stuff::MyImage msg;
//    msg.imageId = 250;



//    msg.image = image;

/*
    if(image.data){
//        cv::imshow( "Display window", image );
//        cv::waitKey(0);
    }
    else{
        ROS_INFO_STREAM("Error " << 3);
    }

    cv::VideoCapture v1;
    cv::Mat frame1;
    v1.open(1);

    for(;;)
    {
        v1 >> frame1;

        cv_bridge::CvImage cv_img;

        cv_img.image = frame1;

        cv_img.encoding = sensor_msgs::image_encodings::BGR8;
        msg.image = *cv_img.toImageMsg();

        image_pub.publish(msg);

        //cv::imshow("Display window",frame1);
        //if(cv::waitKey(30) >= 0) break;
    }



//    myVideoWriter temp = myVideoWriter();

*/
}





