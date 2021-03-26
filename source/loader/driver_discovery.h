/*
 *
 * Copyright (C) 2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once

#include <string>
#include <vector>

namespace loader {

using DriverLibraryPath = std::string;

void discoverEnabledDrivers(std::vector<DriverLibraryPath>&);

} // namespace loader
