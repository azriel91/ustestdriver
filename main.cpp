/*=============================================================================

	CppMicroServices Test Driver

	Copyright (c) German Cancer Research Center,
		Division of Medical and Biological Informatics

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

		http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

=============================================================================*/

#include "usConfig.h"

#include <azriel/cppmicroservices/include/usModule.h>
#include <azriel/cppmicroservices/include/usModuleRegistry.h>

#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>

US_USE_NAMESPACE

int main(int /*argc*/, char** /*argv*/) {
	char cmd[256];

	std::cout << "us > ";
	while(std::cin.getline(cmd, sizeof(cmd))) {
		std::string strCmd(cmd);
		if (strCmd == "q") {
			break;
		} else if (strCmd == "h") {
			printf("  %-11s %s", "h", "This help text\n");
			printf("  %-11s %s", "s", "Print status information\n");
			printf("  %-11s %s", "q", "Quit\n");
			fflush(stdout);
		} else if (strCmd == "s") {
			std::vector<Module*> modules = ModuleRegistry::GetModules();

			std::cout << std::left;

			std::cout << "Id | " << std::setw(20) << "Name" << " | " << std::setw(9) << "Status" << std::endl;
			std::cout << "-----------------------------------\n";

			for (std::vector<Module*>::const_iterator moduleIter = modules.begin();
					 moduleIter != modules.end(); ++moduleIter) {
				std::cout << std::right << std::setw(2) << (*moduleIter)->GetModuleId() << std::left << " | ";
				std::cout << std::setw(20) << (*moduleIter)->GetName() << " | ";
				std::cout << std::setw(9) << ((*moduleIter)->IsLoaded() ? "LOADED" : "UNLOADED");
				std::cout << std::endl;
			}
		} else {
			std::cout << "Unknown command: " << strCmd << " (type 'h' for help)" << std::endl;
		}
		std::cout << "us > ";
	}

	return 0;
}