#include "sample5App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<sample5App>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

sample5App::sample5App(InputParameters parameters) : MooseApp(parameters)
{
  sample5App::registerAll(_factory, _action_factory, _syntax);
}

sample5App::~sample5App() {}

void
sample5App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"sample5App"});
  Registry::registerActionsTo(af, {"sample5App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
sample5App::registerApps()
{
  registerApp(sample5App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
sample5App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  sample5App::registerAll(f, af, s);
}
extern "C" void
sample5App__registerApps()
{
  sample5App::registerApps();
}
