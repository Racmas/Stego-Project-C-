#include <iostream>
#include <ostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <bitset>
#include <vector>

cv::Mat getImage(const std::string& imageLocation){
   cv::Mat image = cv::imread(imageLocation, cv::IMREAD_COLOR);

    if (image.empty()){
        std::cerr << "Failed To Load Image" << std::endl;
    }
    return(image);
}

std::vector<int> string2Binary(std::string& inputString){
    std::vector<int> binaryList;
    
    for (std::size_t i = 0; i < inputString.size(); ++i){
        binaryList.push_back(std::bitset<8>(inputString.c_str()[i]).to_ulong());
    }
    
    return binaryList;
}

int main (){
    std::string imageLocation = "external/images/Drivers Licence.png";

    cv::Mat image = getImage(imageLocation);
    
    std::vector binaryList = string2Binary(imageLocation);


    for(auto i : binaryList){
        std::cout << binaryList[i] << std::endl;
    }    

    int x = 100;
    int y = 100;

    cv::Vec3b pixel = image.at<cv::Vec3b>(y,x);

    int blue = pixel[0];
    int green = pixel[1];
    int red = pixel[2];

    std::cout << blue << " " << green << " " << red << std::endl;

}
