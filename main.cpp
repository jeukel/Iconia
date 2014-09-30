#include "scan_load.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "constants/constants.h"

using namespace cv;
using namespace std;

int main()
{
    scan_load* sl_pic = new scan_load(&constants.path00, &constants.path01);
    sl_pic->scan();
    return 0;
}
