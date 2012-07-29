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

#ifndef LEARNABCGAME_H_
#define LEARNABCGAME_H_

#include "LearnABCForm.h"

const Osp::Base::String RES_SOUND_TOUCH1 = "/res/touch1.wav";
const Osp::Base::String RES_SOUND_WRONG1 = "/res/wrong1.wav";
const Osp::Base::String RES_PATH = "/res/";
const Osp::Base::String RES_SOUND_EXT_WAV = ".wav";
const Osp::Base::String RES_SOUND_CORRECT_PREFIX = "correct";

const Osp::Base::String RES_BUTTON_ALPHA_PREFIX = L"IDC_BTN_ALPHA";

class LearnABCGame :
  	  public Osp::Ui::IActionEventListener,
  	  public Osp::Media::IPlayerEventListener {
	private:
		const static int MAX_ALPHA_BUTTON = 6;
		const static int MIN_ALPHA_BUTTON = 3;
		const static int MAX_ALPHA = 26;
		const static int MAX_CORRECT_SOUND = 5;
		const static int MAX_WRONG_SOUND = 1;

		Osp::Base::String Alpha;

		int correctAnswer;
		int answerButton;
		Osp::Media::Player *audioPlayer;
		Osp::Ui::Controls::Form *gameForm;
		Osp::Ui::Controls::Button *pButtonAlpha[MAX_ALPHA_BUTTON];

		result setNextBoard(void);
		void playSound(Osp::Base::String filePath);
		result initAudio(void);

	public:
		virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
		LearnABCGame();
		result Construct(Osp::Ui::Controls::Form *gameForm);
		virtual ~LearnABCGame();
		void start(void);

		virtual void  OnPlayerBuffering (int percent);
		virtual void  OnPlayerEndOfClip (void);
		virtual void  OnPlayerErrorOccurred (Osp::Media::PlayerErrorReason r);
		virtual void  OnPlayerInterrupted (void);
		virtual void  OnPlayerOpened (result r);
		virtual void  OnPlayerReleased (void);
		virtual void  OnPlayerSeekCompleted (result r);

};

#endif /* LEARNABCGAME_H_ */
