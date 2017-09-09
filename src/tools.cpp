#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */

  VectorXd rmse(4);
  rmse << 0,0,0,0;

  // check the validity of estimations and ground_truth
  if(estimations.size() != ground_truth.size() || estimations.size() == 0){
    cout << "Invalid data input" << endl;
    return rmse;
  }

  for(int i=0; i < estimations.size(); i++){

    VectorXd residual = estimations[i] - ground_truth[i];

    residual = residual.array()*residual.array();
    rmse += residual;
  }

  //calculate the mean and squared root
  rmse = rmse/estimations.size();
  rmse = rmse.array().sqrt();

  return rmse;
}