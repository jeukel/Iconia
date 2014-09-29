#include "scan_load.h"
#include "genetico/genetico.h"
#include "constants/constants.h"

scan_load::scan_load(string *Ppath00,string *Ppath01)
{
    this->path00 = *Ppath00;
    this->path01 = *Ppath01;
}

int scan_load::scan()
{
    Mat I, J;
    I = imread(path00);
    J = imread(path01);

    if (!I.data || !J.data)
    {
        cout << "The image" << path00 << " or "
             << "The image" << path01 << " could not be loaded." << endl;
        return -1;
    }

    Mat K,Kp;
    cvtColor(I, K, CV_BGR2GRAY);
    cvtColor(J, L, CV_BGR2GRAY);

    //GaussianBlur(K, K, cv::Size(7,7), 1.5, 1.5);
    //GaussianBlur(L, L, cv::Size(7,7), 1.5, 1.5);

    //**************************************************//

    for(int i = 0; i < K.rows ; i++){

        for(int j = 0; j < K.cols ; j++){

            //cout <<(int) K.at<Vec3b>(i, j)[0] <<endl;

            if(L.at<Vec3b>(i,j) != K.at<Vec3b>(i,j)){
                //cout << "Entré en: " << j << " interaciones" << endl;

                short fitness;
                fitness = K.at<Vec3b>(i,j)[0];

                if(K.at<Vec3b>(i,j)[0] == 0){
                   fitness = 1;
                }

                Genetico* gen = new Genetico(fitness);
                //cout << (short) K.at<Vec3b>(i,j)[0] << endl;

                short bestfit;
                bestfit = gen->start(50,200);

                //L.at<Vec3b>(i,j)[0] = (unsigned char) bestfit;
                cout << "Y cambié un pixel." << endl;

            } else{
                cout << "No entré en: " << j << " interaciones" << endl;
            }
        }
    }

    //**************************************************//
    imshow("output00",K);
    imshow("output01",L);

    waitKey(36000);
    return 0;
}
