/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifdef PAIR_CLASS

PairStyle(lj/long/coul/long,PairLJLongCoulLong)

#else

#ifndef LMP_PAIR_LJ_LONG_COUL_LONG_H
#define LMP_PAIR_LJ_LONG_COUL_LONG_H

#include "pair.h"

namespace LAMMPS_NS {

class PairLJLongCoulLong : public Pair {
 public:
  double cut_coul;

  PairLJLongCoulLong(class LAMMPS *);
  virtual ~PairLJLongCoulLong();
  virtual void compute(int, int);
  virtual void settings(int, char **);
  void coeff(int, char **);
  void init_style();
  void init_list(int, class NeighList *);
  double init_one(int, int);
  void write_restart(FILE *);
  void read_restart(FILE *);

  void write_restart_settings(FILE *);
  void read_restart_settings(FILE *);
  double single(int, int, int, int, double, double, double, double &);
  void *extract(const char *, int &);

  void compute_inner();
  void compute_middle();
  void compute_outer(int, int);

 protected:
  double cut_lj_global;
  double **cut_lj, **cut_lj_read, **cut_ljsq;
  double cut_coulsq;
  double **epsilon_read, **epsilon, **sigma_read, **sigma;
  double **lj1, **lj2, **lj3, **lj4, **offset;
  double *cut_respa;
  double qdist;
  double g_ewald;
  double g_ewald_6;
  int ewald_order, ewald_off;

  void options(char **arg, int order);
  void allocate();
};

}

#endif
#endif

/* ERROR/WARNING messages:

E: Illegal ... command

UNDOCUMENTED

W: Mixing forced for lj coefficients

UNDOCUMENTED

W: Using largest cut-off for lj/coul long long

UNDOCUMENTED

E: Cut-offs missing in pair_style lj/coul

UNDOCUMENTED

E: Coulombic cut not supported in pair_style lj/coul

UNDOCUMENTED

E: Only one cut-off allowed when requesting all long

UNDOCUMENTED

E: Incorrect args for pair coefficients

UNDOCUMENTED

E: Invoking coulombic in pair style lj/coul requires atom attribute q

UNDOCUMENTED

E: Pair style requires a KSpace style

UNDOCUMENTED

E: Pair cutoff < Respa interior cutoff

UNDOCUMENTED

*/
