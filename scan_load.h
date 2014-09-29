#ifndef SCAN_LOAD_H
#define SCAN_LOAD_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace cv;

class scan_load
{
public:
    scan_load(string *Ppath00,string *Ppath01);
    int scan();
private:
    string path00;
    string path01;
};

#endif // SCAN_LOAD_H
