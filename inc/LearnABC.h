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

#ifndef _LEARNABC_H_
#define _LEARNABC_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>

/**
 * [LearnABC] application must inherit from Application class
 * which provides basic features necessary to define an application.
 */
class LearnABC :
		public Osp::App::Application,
		public Osp::System::IScreenEventListener {
	public:

		/**
		 * [LearnABC] application must have a factory method that creates an instance of itself.
		 */
		static Osp::App::Application* CreateInstance(void);


	public:
		LearnABC();
		~LearnABC();


	public:


		// Called when the application is initializing.
		bool OnAppInitializing(Osp::App::AppRegistry& appRegistry);

		// Called when the application is terminating.
		bool OnAppTerminating(Osp::App::AppRegistry& appRegistry, bool forcedTermination = false);


		// Called when the application's frame moves to the top of the screen.
		void OnForeground(void);


		// Called when this application's frame is moved from top of the screen to the background.
		void OnBackground(void);

		// Called when the system memory is not sufficient to run the application any further.
		void OnLowMemory(void);

		// Called when the battery level changes.
		void OnBatteryLevelChanged(Osp::System::BatteryLevel batteryLevel);

		// Called when the screen turns on.
		void OnScreenOn (void);

		// Called when the screen turns off.
		void OnScreenOff (void);
};

#endif
