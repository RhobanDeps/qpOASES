#ifndef QPOASES_EIGEN_HPP
#define QPOASES_EIGEN_HPP

#include <qpOASES.hpp>
#include <Eigen/Core>

Eigen::VectorXd QPsolve(Eigen::MatrixXd H, Eigen::VectorXd g, Eigen::VectorXd* lb = nullptr,
                        Eigen::VectorXd* ub = nullptr, Eigen::MatrixXd* A = nullptr, Eigen::VectorXd* lbA = nullptr,
                        Eigen::VectorXd* ubA = nullptr, int* nWSR = nullptr, qpOASES::real_t* const cputime = nullptr);

#endif
