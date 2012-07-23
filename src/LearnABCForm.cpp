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

#include "LearnABCForm.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

LearnABCForm::LearnABCForm(void) {
}

LearnABCForm::~LearnABCForm(void) {
}

bool LearnABCForm::Initialize() {
	// Construct an XML form
	Construct(L"IDF_LEARNABC_FORM");

	// Create the game
	game = new LearnABCGame();
	if(game) {
		game->Construct(this);
		game->start();
	}
	return true;
}

result LearnABCForm::OnInitializing(void) {
	result r = E_SUCCESS;
	return r;
}

result LearnABCForm::OnTerminating(void) {
	result r = E_SUCCESS;
	if(game) delete game;
	return r;
}
