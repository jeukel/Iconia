#include "scan_load.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    string path00 = "img/win.png";
    string path01 = "img/fail.png";

    scan_load* sl_pic = new scan_load(&path00, &path01);
    sl_pic->scan();
    return 0;
}
