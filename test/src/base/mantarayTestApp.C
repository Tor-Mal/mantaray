//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "mantarayTestApp.h"
#include "mantarayApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
mantarayTestApp::validParams()
{
  InputParameters params = mantarayApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

mantarayTestApp::mantarayTestApp(InputParameters parameters) : MooseApp(parameters)
{
  mantarayTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

mantarayTestApp::~mantarayTestApp() {}

void
mantarayTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  mantarayApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"mantarayTestApp"});
    Registry::registerActionsTo(af, {"mantarayTestApp"});
  }
}

void
mantarayTestApp::registerApps()
{
  registerApp(mantarayApp);
  registerApp(mantarayTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
mantarayTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  mantarayTestApp::registerAll(f, af, s);
}
extern "C" void
mantarayTestApp__registerApps()
{
  mantarayTestApp::registerApps();
}
