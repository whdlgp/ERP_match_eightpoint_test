#pragma once

#include "feature_matcher.hpp"
#include "erp_rotation.hpp"
#include <omp.h>

#define RAD(x) M_PI*(x)/180.0
#define DEGREE(x) 180.0*(x)/M_PI

class spherical_surf
{
    public:
    void set_omp(int num_proc);
    void do_all(const cv::Mat &im_left, const cv::Mat &im_right, std::vector<cv::KeyPoint>& left_key, std::vector<cv::KeyPoint>& right_key, int& match_size, cv::Mat& match_output, int& total_key_num);

    private:
    cv::Mat crop_rotated_image(float pitch_rot, const cv::Mat& im);
    void rotate_keypoint(float pitch_rot_inv, std::vector<cv::KeyPoint>& key, int width, int height);

    erp_rotation erp_rot;

    int num_proc;
    std::vector<cv::KeyPoint> left_key_tmp;
    std::vector<cv::KeyPoint> right_key_tmp;
    cv::Mat descriptor_left_tmp;
    cv::Mat descriptor_right_tmp;
    std::vector<cv::DMatch> matches;
};