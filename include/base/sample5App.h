//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef SAMPLE5APP_H
#define SAMPLE5APP_H

#include "MooseApp.h"

class sample5App;

template <>
InputParameters validParams<sample5App>();

class sample5App : public MooseApp
{
public:
  sample5App(InputParameters parameters);
  virtual ~sample5App();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);
};

#endif /* SAMPLE5APP_H */
