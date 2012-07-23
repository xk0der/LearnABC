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
#include "LearnABCGame.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

LearnABCGame::LearnABCGame() {
}

void LearnABCGame::Construct(Osp::Ui::Controls::Form *gameForm) {
	Osp::Base::DateTime dt;
	Osp::System::SystemTime::GetCurrentTime(dt);
	Osp::Base::Utility::Math::Srand(static_cast<unsigned int>(dt.GetTime().GetSeconds()));

	this->gameForm = gameForm;
	result r = E_SUCCESS;


	Alpha.Append(L"ABCDEFGHIJIKLMNOPQRSTUVWXYZ");

	for(int idx = 0; idx < MAX_ALPHA_BUTTON; idx++) {
		String buttonResourceName;
		buttonResourceName.Append(RES_BUTTON_ALPHA_PREFIX);
		buttonResourceName.Append(idx + 1);
		pButtonAlpha[idx] = static_cast<Osp::Ui::Controls::Button*>(gameForm->GetControl(buttonResourceName));
		if(pButtonAlpha[idx] == null) {
			AppLog("Could not get one of the buttons!!");
			r = E_FAILURE;
			break;
		}
		pButtonAlpha[idx]->SetActionId(idx);
		pButtonAlpha[idx]->AddActionEventListener(*this);
	}

	initAudio();
}

void LearnABCGame::start(void) {
	setNextBoard();
}

void LearnABCGame::initAudio(void) {

	audioPlayer = new Osp::Media::Player();
	int rt = audioPlayer->Construct(*this, 0);

	if(rt != E_SUCCESS) {
		AppLog("Unable to properly construct Player!");
		audioPlayer = null;
	} else {
		audioPlayer->SetVolume(100);
		audioPlayer->SetLooping(false);
	}
}


void LearnABCGame::playSound(Osp::Base::String filePath) {
	if(!audioPlayer) {
		return;
	}

	int rt = E_SUCCESS;

	while(audioPlayer->GetState() == Osp::Media::PLAYER_STATE_PLAYING) ;

	if( audioPlayer->GetState() == Osp::Media::PLAYER_STATE_STOPPED
			|| audioPlayer->GetState() == Osp::Media::PLAYER_STATE_ENDOFCLIP
			|| audioPlayer->GetState() == Osp::Media::PLAYER_STATE_ERROR) rt = audioPlayer->Close();

	if(rt != E_SUCCESS) {
		AppLog("Unable to close audio!");
	}

	rt = audioPlayer->OpenFile(filePath, false);

	if(rt != E_SUCCESS) {
		AppLog("Unable to open sound file: %i", rt);
	}

	audioPlayer->Play();
}

result LearnABCGame::setNextBoard(void) {
	result r = E_SUCCESS;

	bool usedButton[MAX_ALPHA_BUTTON] = { false };
	bool usedAlpha[MAX_ALPHA] = { false };

	int numAlpha = (Osp::Base::Utility::Math::Rand() % (MAX_ALPHA_BUTTON - MIN_ALPHA_BUTTON)) + MIN_ALPHA_BUTTON;

	correctAnswer = Osp::Base::Utility::Math::Rand() % MAX_ALPHA;

	usedAlpha[correctAnswer] = true;

	for(int idx = 0; idx < MAX_ALPHA_BUTTON; idx++) {
		pButtonAlpha[idx]->SetText(L"");
		pButtonAlpha[idx]->SetShowState(false);
	}

	AppLog("numAlpha : %i, correctAnswer %i ", numAlpha, correctAnswer);
	for(int idx = 0; idx < numAlpha; idx++) {
		int choosenButton = (Osp::Base::Utility::Math::Rand() % (MAX_ALPHA_BUTTON));
		if(usedButton[choosenButton]) {
			for(int idy = 0; idy < MAX_ALPHA_BUTTON; idy++) {
				if(!usedButton[idy]) {
					choosenButton = idy;
					break;
				}
			}
		}
		usedButton[choosenButton] = true;
		AppLog("choosenButton: %i", choosenButton);
		pButtonAlpha[choosenButton]->SetShowState(true);

		if(idx == 0) {
			mchar c;
			Alpha.GetCharAt(correctAnswer, c);
			pButtonAlpha[choosenButton]->SetText(c);
			AppLog("CorrectAnswerAlpha %c", c);
			answerButton = choosenButton;
		}
		else {
			int randomAlpha = Osp::Base::Utility::Math::Rand() % MAX_ALPHA;

			if(usedAlpha[randomAlpha]) {
				for(int idy = 0; idy < MAX_ALPHA; idy++) {
					if(!usedAlpha[idy]) {
						randomAlpha = idy;
						break;
					}
				}
			}

			usedAlpha[randomAlpha] = true;

			mchar c;
			Alpha.GetCharAt(randomAlpha, c);
			pButtonAlpha[choosenButton]->SetText(c);
		}
	}

	gameForm->RequestRedraw(true);

	playSound(RES_SOUND_TOUCH1);

	String path;
	path.Append(RES_PATH);
	{
		mchar c;
		Alpha.GetCharAt(correctAnswer, c);
		path.Append(c);
		path.Append(1);
		path.Append(RES_SOUND_EXT_WAV);
	}
	playSound(path);

	return r;
}

void LearnABCGame::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	if(actionId == answerButton) {
		AppLog("Correct Answer!");
		String path;
		path.Append(RES_PATH);
		{
			int sound = (Osp::Base::Utility::Math::Rand() % MAX_CORRECT_SOUND) + 1;
			path.Append(RES_SOUND_CORRECT_PREFIX);
			path.Append(sound);
			path.Append(RES_SOUND_EXT_WAV);
		}
		playSound(path);
		setNextBoard();
	} else {
		playSound(RES_SOUND_WRONG1);
		AppLog("Incorrect!!");
	}
}



LearnABCGame::~LearnABCGame() {
	for(int idx = 0; idx < MAX_ALPHA_BUTTON; idx++) {
		if(pButtonAlpha[idx])
			delete pButtonAlpha[idx];
	}

	if(audioPlayer) {
		delete audioPlayer;
	}
}

// These are required by audio-player when used in async mode.
// We need to implement these as these are pure virtual functions.
void  LearnABCGame::OnPlayerBuffering (int percent) {}
void  LearnABCGame::OnPlayerEndOfClip (void) {}
void  LearnABCGame::OnPlayerErrorOccurred (Osp::Media::PlayerErrorReason r) {}
void  LearnABCGame::OnPlayerInterrupted (void) {}
void  LearnABCGame::OnPlayerOpened (result r) {}
void  LearnABCGame::OnPlayerReleased (void) {}
void  LearnABCGame::OnPlayerSeekCompleted (result r) {}
