/**
 * Copyright (C) 2020-2021 Xilinx, Inc
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You may
 * not use this file except in compliance with the License. A copy of the
 * License is located at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#include "plugin/xdp/plugin_loader.h"
#include "plugin/xdp/hal_profile.h"
#include "plugin/xdp/hal_device_offload.h"
#include "plugin/xdp/aie_profile.h"
#include "plugin/xdp/noc_profile.h"
#include "plugin/xdp/power_profile.h"
#include "plugin/xdp/aie_trace.h"
#include "plugin/xdp/vart_profile.h"

#include "core/common/config_reader.h"

namespace xdp {
namespace hal_hw_plugins {

// This function is responsible for loading all of the HAL level HW XDP plugins
bool load()
{
  if (xrt_core::config::get_xrt_trace()) {
    xdp::hal::load() ;
  }

  if (xrt_core::config::get_data_transfer_trace() != "off") {
    xdp::hal::device_offload::load() ;
  }

  if (xrt_core::config::get_aie_profile()) {
    xdp::aie::profile::load() ;
  }

  if (xrt_core::config::get_noc_profile()) {
    xdp::noc::profile::load() ;
  }

  if (xrt_core::config::get_power_profile()) {
    xdp::power::profile::load() ;
  }

  if (xrt_core::config::get_aie_trace()) {
    xdp::aie::trace::load() ;
  }

  if (xrt_core::config::get_vitis_ai_profile()) {
    xdp::vart::profile::load() ;
  }

  return true ;
}

} // end namespace hal_hw_plugins
} // end namespace xdp
