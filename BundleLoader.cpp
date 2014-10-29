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

#include "BundleLoader.h"

namespace us {
namespace test {
namespace driver {

BundleLoader::BundleLoader() {
}

BundleLoader::~BundleLoader() {
}

void BundleLoader::load(const std::string libraryPath) {
	std::map<const std::string, SharedLibrary>::const_iterator libIter = this->libraryHandles.find(libraryPath);

	if (libIter != this->libraryHandles.end()) {
		SharedLibrary libHandle = libIter->second;
		libHandle.Load();
	} else {
		SharedLibrary libHandle(libraryPath);
		libHandle.Load();
		this->libraryHandles.insert(std::make_pair(libraryPath, libHandle));
	}
}

void BundleLoader::unload(const long int id) {
}

} /* namespace driver */
} /* namespace test */
} /* namespace us */
