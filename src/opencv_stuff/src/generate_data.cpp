// generate_data.cpp

#include <ros/ros.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/ml/ml.hpp>

#include<iostream>
#include<vector>
#include<sstream>
#include<string>

// global variables ///////////////////////////////////////////////////////////////////////////////
const int MIN_CONTOUR_AREA = 100;

const int RESIZED_IMAGE_WIDTH = 20;
const int RESIZED_IMAGE_HEIGHT = 30;

///////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv){

    ros::init(argc, argv, "opencv_stuff_node2");
    ros::NodeHandle n;

    cv::Mat matTrainingNumbers;		// input image
    cv::Mat matGrayscale;			//
    cv::Mat matBlurred;				// declare various images
    cv::Mat matThresh;				//
    cv::Mat matThreshCopy;			//

    std::vector<std::vector<cv::Point> > ptContours;		// declare contours vector
    std::vector<cv::Vec4i> v4iHierarchy;					// declare contours hierarchy

    cv::Mat matClassificationInts;		// these are our training classifications, note we will have to perform some conversions before writing to file later

                                                // these are our training images, due to the data types that the KNN object KNearest requires,
    cv::Mat matTrainingImages;					// we have to declare a single Mat, then append to it as though it's a vector,
                                                // also we will have to perform some conversions before writing to file later

    // possible chars we are interested in are digits 0 through 9, put these in vector intValidChars
    std::vector<int> intValidChars;
    intValidChars.push_back('A');
    intValidChars.push_back('a');
    intValidChars.push_back('B');
    intValidChars.push_back('b');
    intValidChars.push_back('C');
//    intValidChars.push_back('c');
    intValidChars.push_back('D');
    intValidChars.push_back('d');
    intValidChars.push_back('E');
    intValidChars.push_back('e');
    intValidChars.push_back('F');
    intValidChars.push_back('f');
    intValidChars.push_back('G');
    intValidChars.push_back('g');
    intValidChars.push_back('H');
    intValidChars.push_back('h');
    intValidChars.push_back('I');
    intValidChars.push_back('i');
    intValidChars.push_back('J');
    intValidChars.push_back('j');
    intValidChars.push_back('K');
    intValidChars.push_back('k');
    intValidChars.push_back('L');
    intValidChars.push_back('l');
    intValidChars.push_back('M');
    intValidChars.push_back('m');
    intValidChars.push_back('N');
    intValidChars.push_back('n');
    intValidChars.push_back('O');
//    intValidChars.push_back('o');
    intValidChars.push_back('P');
    intValidChars.push_back('p');
    intValidChars.push_back('Q');
    intValidChars.push_back('q');
    intValidChars.push_back('R');
    intValidChars.push_back('r');
    intValidChars.push_back('S');
//    intValidChars.push_back('s');
    intValidChars.push_back('T');
    intValidChars.push_back('t');
    intValidChars.push_back('U');
//    intValidChars.push_back('u');
    intValidChars.push_back('V');
//    intValidChars.push_back('v');
    intValidChars.push_back('W');
//    intValidChars.push_back('w');
    intValidChars.push_back('X');
//    intValidChars.push_back('x');
    intValidChars.push_back('Y');
    intValidChars.push_back('y');
    intValidChars.push_back('Z');
//    intValidChars.push_back('z');
    intValidChars.push_back('_');
    intValidChars.push_back('0');
    intValidChars.push_back('1');
    intValidChars.push_back('2');
    intValidChars.push_back('3');
    intValidChars.push_back('4');
    intValidChars.push_back('5');
    intValidChars.push_back('6');
    intValidChars.push_back('7');
    intValidChars.push_back('8');
    intValidChars.push_back('9');


    std::string letters = "abcdefghijklmnopqrstuvwxyz_0123456789";
    for(int i = 0; i < letters.size();i++){
        std::string letter;
        std::stringstream ss;
        ss << letters[i];
        ss >> letter;
        matTrainingNumbers = cv::imread("/home/jaron/catkin_ws/training_images/" +letter + ".jpg");			// read in training numbers image
        std::cout << "training_images/" +letter + ".jpg\n";
    //    matTrainingNumbers = cv::imread("pinta_load.jpg");			// read in training numbers image

        if (matTrainingNumbers.empty()) {							// if unable to open image
            std::cout << "error: image not read from file\n\n";		// show error message on command line
            return(0);												// and exit program
        }

        cv::cvtColor(matTrainingNumbers, matGrayscale, CV_BGR2GRAY);		// convert to grayscale

        cv::GaussianBlur(matGrayscale,			// input image
            matBlurred,							// output image
            cv::Size(5, 5),						// smoothing window width and height in pixels
            0);									// sigma value, determines how much the image will be blurred, zero makes function choose the sigma value

        // filter image from grayscale to black and white
        cv::adaptiveThreshold(matBlurred,							// input image
            matThresh,							// output image
            255,									// make pixels that pass the threshold full white
            cv::ADAPTIVE_THRESH_GAUSSIAN_C,		// use gaussian rather than mean, seems to give better results
            cv::THRESH_BINARY_INV,				// invert so foreground will be white, background will be black
            11,									// size of a pixel neighborhood used to calculate threshold value
            2);									// constant subtracted from the mean or weighted mean

        cv::imshow("matThresh", matThresh);			// show threshold image for reference

        matThreshCopy = matThresh.clone();			// make a copy of the thresh image, this in necessary b/c findContours modifies the image

        cv::findContours(matThreshCopy,					// input image, make sure to use a copy since the function will modify this image in the course of finding contours
            ptContours,					// output contours
            v4iHierarchy,					// output hierarchy
            cv::RETR_EXTERNAL,				// retrieve the outermost contours only
            cv::CHAIN_APPROX_SIMPLE);		// compress horizontal, vertical, and diagonal segments and leave only their end points

        for (int i = 0; i < ptContours.size(); i++) {						// for each contour
            if (cv::contourArea(ptContours[i]) > MIN_CONTOUR_AREA) {			// if contour is big enough to consider
                cv::Rect boundingRect = cv::boundingRect(ptContours[i]);			// get the bounding rect

                cv::rectangle(matTrainingNumbers, boundingRect, cv::Scalar(0, 0, 255), 2);		// draw red rectangle around each contour as we ask user for input

                cv::Mat matROI = matThresh(boundingRect);			// get ROI image of bounding rect

                cv::Mat matROIResized;
                cv::resize(matROI, matROIResized, cv::Size(RESIZED_IMAGE_WIDTH, RESIZED_IMAGE_HEIGHT));		// resize image, this will be more consistent for recognition and storage

                cv::imshow("matROI", matROI);								// show ROI image for reference
                cv::imshow("matROIResized", matROIResized);					// show resized ROI image for reference
                cv::imshow("matTrainingNumbers", matTrainingNumbers);		// show training numbers image, this will now have red rectangles drawn on it

                int waiting = -1;
                int intChar = cv::waitKey(0);           // get key press
                while(waiting != 10){                   // added shift
                        waiting = cv::waitKey(0);
                        if(waiting != 10){
                            intChar = waiting - 65536;
                        }
                }

    //            std::string inputString;
    //            std::getline(std::cin, inputString);
    //            intChar = inputString[0];

                std::cout << intChar << std::endl;

                if (intChar == 27) {		// if esc key was pressed
                    return(0);				// exit program
                }
                else if (std::find(intValidChars.begin(), intValidChars.end(), intChar) != intValidChars.end()) {  // else if the char is in the list of chars we are looking for . . .

                    matClassificationInts.push_back(intChar);		// append classification char to integer list of chars (we will convert later before writing to file)

                    cv::Mat matImageFloat;							// now add the training image (some conversion is necessary first) . . .
                    matROIResized.convertTo(matImageFloat, CV_32FC1);		// convert Mat to float

                    cv::Mat matImageReshaped = matImageFloat.reshape(1, 1);		// flatten

                    matTrainingImages.push_back(matImageReshaped);		// add to Mat as though it was a vector, this is necessary due to the
                                                                        // data types that KNearest.train accepts
                    std::cout << "matImageReshaped "<< std::endl;
                }	// end if
            }	// end if
        }	// end for


        std::cout << "saving to files\n\n";
        // save classifications to file ///////////////////////////////////////////////////////

        cv::Mat matClassificationFloats;
        matClassificationInts.convertTo(matClassificationFloats, CV_32FC1);			// convert ints to floats

        cv::FileStorage fsClassifications("classifications.xml", cv::FileStorage::WRITE);			// open the classifications file

        if (fsClassifications.isOpened() == false) {														// if the file was not opened successfully
            std::cout << "error, unable to open training classifications file, exiting program\n\n";		// show error message
            return(0);																						// and exit program
        }

        fsClassifications << "classifications" << matClassificationFloats;		// write classifications into classifications section of classifications file
        fsClassifications.release();											// close the classifications file

        // save training images to file ///////////////////////////////////////////////////////

        cv::FileStorage fsTrainingImages("images.xml", cv::FileStorage::WRITE);			// open the training images file

        if (fsTrainingImages.isOpened() == false) {													// if the file was not opened successfully
            std::cout << "error, unable to open training images file, exiting program\n\n";			// show error message
            return(0);																				// and exit program
        }

        fsTrainingImages << "images" << matTrainingImages;		// write training images into images section of images file
        fsTrainingImages.release();								// close the training images file
    }
    std::cout << "training complete\n\n";
    return(0);
}
