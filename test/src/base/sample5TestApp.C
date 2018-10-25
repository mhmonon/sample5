//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "sample5TestApp.h"
#include "sample5App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<sample5TestApp>()
{
  InputParameters params = validParams<sample5App>();
  return params;
}

sample5TestApp::sample5TestApp(InputParameters parameters) : MooseApp(parameters)
{
  sample5TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

sample5TestApp::~sample5TestApp() {}

void
sample5TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  sample5App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"sample5TestApp"});
    Registry::registerActionsTo(af, {"sample5TestApp"});
  }
}

void
sample5TestApp::registerApps()
{
  registerApp(sample5App);
  registerApp(sample5TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
sample5TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  sample5TestApp::registerAll(f, af, s);
}
extern "C" void
sample5TestApp__registerApps()
{
  sample5TestApp::registerApps();
}
