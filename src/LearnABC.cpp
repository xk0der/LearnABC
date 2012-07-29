/*
LearnABC - A BadaOS app to teach alphabets to kids in a fun way.
Copyright (C) 2012, Amit Singh (aka xk0der)

e: amit@xkoder.com
w: http://xkoder.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "LearnABC.h"
#include "LearnABCForm.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::System;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

LearnABC::LearnABC() {
}

LearnABC::~LearnABC() {
}

Application* LearnABC::CreateInstance(void) {
	// Create the instance through the constructor.
	return new LearnABC();
}

bool LearnABC::OnAppInitializing(AppRegistry& appRegistry) {
	// Create a form
	LearnABCForm *pMainForm = new LearnABCForm();
	pMainForm->Initialize();

	// Add the form to the frame
	Frame *pFrame = GetAppFrame()->GetFrame();
	pFrame->AddControl(*pMainForm);

	// Set the current form
	pFrame->SetCurrentForm(*pMainForm);

	// Draw and Show the form
	pMainForm->Draw();
	pMainForm->Show();

	return true;
}

bool LearnABC::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination) {
	return true;
}

void LearnABC::OnForeground(void) {
}

void LearnABC::OnBackground(void) {
}

void LearnABC::OnLowMemory(void) {
}

void LearnABC::OnBatteryLevelChanged(BatteryLevel batteryLevel) {
}

void LearnABC::OnScreenOn (void) {
}

void LearnABC::OnScreenOff (void) {
}
