#include "mantarayApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
mantarayApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

mantarayApp::mantarayApp(InputParameters parameters) : MooseApp(parameters)
{
  mantarayApp::registerAll(_factory, _action_factory, _syntax);
}

mantarayApp::~mantarayApp() {}

void
mantarayApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<mantarayApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"mantarayApp"});
  Registry::registerActionsTo(af, {"mantarayApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
mantarayApp::registerApps()
{
  registerApp(mantarayApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
mantarayApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  mantarayApp::registerAll(f, af, s);
}
extern "C" void
mantarayApp__registerApps()
{
  mantarayApp::registerApps();
}
