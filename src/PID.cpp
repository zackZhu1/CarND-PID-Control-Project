#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
   this->Kp = Kp_;
   this->Ki = Ki_;
   this->Kd = Kd_;

   p_error = 0.0;
   i_error = 0.0;
   d_error = 0.0;

   prev_cte = 0.0;
   prev_cte_valid = false;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */

  if (!prev_cte_valid) {
    prev_cte = cte;
    prev_cte_valid = true;
    return;
  }

  int dt = 1;
  double diff_cte = cte - prev_cte;
  prev_cte = cte;
  int_cte += cte;

  p_error = Kp * cte;
  i_error = Ki * int_cte;
  d_error = Kd * (diff_cte / dt);

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return p_error + i_error + d_error;
}