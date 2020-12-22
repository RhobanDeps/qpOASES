#include <qpOASES.hpp>
#include <qpOASES/Types.hpp>
#include <qpOASES/Eigen.hpp>

using namespace qpOASES;

Eigen::VectorXd QPsolve(Eigen::MatrixXd H, Eigen::VectorXd g, Eigen::VectorXd* lb, Eigen::VectorXd* ub,
                        Eigen::MatrixXd* A, Eigen::VectorXd* lbA, Eigen::VectorXd* ubA, int* nWSR,
                        real_t* const cputime)
{
  real_t* _H = H.data();
  real_t* _g = g.data();

  real_t* _A = (A == nullptr) ? (nullptr) : A->data();
  real_t* _lbA = (lbA == nullptr) ? (nullptr) : lbA->data();
  real_t* _ubA = (ubA == nullptr) ? (nullptr) : ubA->data();

  real_t* _lb = (lb == nullptr) ? (nullptr) : lb->data();
  real_t* _ub = (ub == nullptr) ? (nullptr) : ub->data();

  int _nWSR = 100;
  if (nWSR != nullptr)
  {
    _nWSR = *nWSR;
  }

  QProblem qp(g.size(), A == nullptr ? 0 : A->rows());

  qp.init(_H, _g, _A, _lb, _ub, _lbA, _ubA, _nWSR, cputime);

  if (nWSR != nullptr)
  {
    *nWSR = _nWSR;
  }

  Eigen::VectorXd solution(g.size());
  qp.getPrimalSolution(solution.data());

  return solution;
}