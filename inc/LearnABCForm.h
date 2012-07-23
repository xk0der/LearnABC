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

#ifndef _LEARN_ABC_FORM_H_
#define _LEARN_ABC_FORM_H_

#include <FBase.h>
#include <FUi.h>
#include <FText.h>
#include <FBaseUtil.h>
#include <FSystem.h>
#include <FMedia.h>

#include "LearnABCGame.h"

class LearnABCGame;

class LearnABCForm :
		public Osp::Ui::Controls::Form {

	private:
		LearnABCGame *game;

	public:
		LearnABCForm(void);
		virtual ~LearnABCForm(void);
		bool Initialize(void);

	public:
		virtual result OnInitializing(void);
		virtual result OnTerminating(void);
};

#endif	//_FORM1_H_
