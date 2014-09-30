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
    //constants* K = new constants();
    //scan_load* sl_pic = new scan_load(K->path00, K->path01);
    string dir0 = "/home/jeukel/ownCloud/TEC/" +
                  "EclipseWorkspace/Iconia/img/win.png";
    string dir1 = "/home/jeukel/ownCloud/TEC/" +
                  "EclipseWorkspace/Iconia/img/fail.png";
    scan_load* sl_pic = new scan_load(&dir0, &dir1);
    sl_pic->scan();
    return 0;

}
