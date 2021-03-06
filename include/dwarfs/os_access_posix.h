/* vim:set ts=2 sw=2 sts=2 et: */
/**
 * \author     Marcus Holland-Moritz (github@mhxnet.de)
 * \copyright  Copyright (c) Marcus Holland-Moritz
 *
 * This file is part of dwarfs.
 *
 * dwarfs is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * dwarfs is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with dwarfs.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <cstddef>
#include <memory>
#include <string>

#include "dwarfs/os_access.h"

namespace dwarfs {

class mmif;

class os_access_posix : public os_access {
 public:
  std::shared_ptr<dir_reader> opendir(const std::string& path) const override;
  void lstat(const std::string& path, struct ::stat* st) const override;
  std::string readlink(const std::string& path, size_t size) const override;
  std::shared_ptr<mmif>
  map_file(const std::string& path, size_t size) const override;
  int access(const std::string& path, int mode) const override;
};
} // namespace dwarfs
