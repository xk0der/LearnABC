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

/**
 * This file contains the bada application entry point.
 */
#include "LearnABC.h"

using namespace Osp::Base;
using namespace Osp::Base::Collection;

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

_EXPORT_ int OspMain(int argc, char *pArgv[]);
#ifdef _PROFILE
extern void start_profile (void);
extern void end_profile (void);
#else
#define start_profile()
#define end_profile()
#endif


/**
 * The entry function of bada application called by the operating system.
 */
int OspMain(int argc, char *pArgv[]) {
	result r = E_SUCCESS;

	AppLog("Application started.");
	ArrayList* pArgs = new ArrayList();
	pArgs->Construct();
	for (int i = 0; i < argc; i++)
		pArgs->Add(*(new String(pArgv[i])));

	start_profile();
	r = Osp::App::Application::Execute(LearnABC::CreateInstance, pArgs);
	if (IsFailed(r)) {
		AppLogException("Application execution failed-[%s].", GetErrorMessage(r));
		r &= 0x0000FFFF;
	}
	end_profile();

	pArgs->RemoveAll(true);
	delete pArgs;
	AppLog("Application finished.");

	return static_cast<int>(r);
}

#ifdef __cplusplus
}
#endif // __cplusplus
