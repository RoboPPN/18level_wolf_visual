#include "configure.h"
#include "control.h"
class SolveP4p
{
public:
    SolveP4p()
    {
        //读取摄像头标定xml文件
        FileStorage fs(CAMERA_PARAM_FILE, FileStorage::READ);
        //读取相机内参和畸变矩阵
        fs["camera-matrix"] >> cameraMatrix;
        fs["distortion"] >> distCoeffs;
        cout << cameraMatrix << endl;
        cout << distCoeffs << endl;
        cout << "RM_SolveAngle is readied" << endl;
    }
    ~SolveP4p() {}

    //坐标赋值
    float arrange_Point(RotatedRect rects, float _w, float _h);
    float run_SolvePnp(float _W, float _H);
    void get_angle();
    void calcu_depth();
    //小孔成像
    float Pinhole_imaging(RotatedRect rects, float _h);

    Point armor_point;
    vector<Point2f> target2d;
    Mat cameraMatrix, distCoeffs, rotM, rotT;
    Mat rvec = Mat::zeros(3, 3, CV_64FC1);
    Mat tvec = Mat::zeros(3, 1, CV_64FC1);
    Mat rvec_invert = Mat::zeros(3, 3, CV_64FC1);
    Mat world_point = Mat::zeros(3, 1, CV_8UC1);
    vector<Point3f> object_3d;
    int dist = 0;
    int theta_x;
    int theta_y;
    int theta_z;
};