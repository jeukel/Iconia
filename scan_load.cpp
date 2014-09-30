#include "scan_load.h"
#include "genetico/genetico.h"
#include "constants/constants.h"

/*!
 * \brief scan_load::scan_load Constructor.
 * \param Ppath00 Path for original picture.
 * \param Ppath01 Path for edited picture.
 */
scan_load::scan_load(string *Ppath00,string *Ppath01)
{
    this->path00 = *Ppath00;
    this->path01 = *Ppath01;
}

/*!
 * \brief scan_load::scan Creates the encapsulator Mat to hold the images the applies
 * filters managing ONLY ONE CHANNEL for easy genetic deduction.
 * \return
 */
int scan_load::scan()
{
    //**************************************************//
    //
    Mat I, J;
    I = imread(path00);
    J = imread(path01);

    if (!I.data || !J.data)
    {
        cout << "The image" << path00 << " or "
             << "The image" << path01 << " could not be loaded." << endl;
        return -1;
    }

    //**************************************************//
    // Apply gray filters for both mats.
    Mat K,L;
    cvtColor(I, K, CV_BGR2GRAY);
    cvtColor(J, L, CV_BGR2GRAY);

    //GaussianBlur(K, K, cv::Size(7,7), 1.5, 1.5);
    //GaussianBlur(L, L, cv::Size(7,7), 1.5, 1.5);

    //**************************************************//
    // Scan by row and cols
    for(int i = 0; i < K.rows ; i++){
        for(int j = 0; j < K.cols ; j++){

            // If the same pixel on orig_ima and ima are diferent,
            // run genetic algorithm to find out the color using
            // the the orig_ima color as fitness.
            if(L.at<Vec3b>(i,j) != K.at<Vec3b>(i,j)){

                cout << "Entré en: " << j << " interaciones" << endl;

                short fitness;

                //If the color is white
                if(K.at<Vec3b>(i,j)[0] == 0){
                   fitness = 1;
                }else{
                    fitness = K.at<Vec3b>(i,j)[0];
                }

                //Creates genetic object
                Genetico* gen = new Genetico(fitness);

                short bestfit;
                bestfit = gen->start(constants.Generations,constants.Density);

                L.at<Vec3b>(i,j)[0] = (unsigned char) bestfit;

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
