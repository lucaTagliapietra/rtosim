/* -------------------------------------------------------------------------- *
 * Copyright (c) 2010-2016 C. Pizzolato, M. Reggiani                          *
 *                                                                            *
 * Licensed under the Apache License, Version 2.0 (the "License");            *
 * you may not use this file except in compliance with the License.           *
 * You may obtain a copy of the License at:                                   *
 * http://www.apache.org/licenses/LICENSE-2.0                                 *
 *                                                                            *
 * Unless required by applicable law or agreed to in writing, software        *
 * distributed under the License is distributed on an "AS IS" BASIS,          *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
 * See the License for the specific language governing permissions and        *
 * limitations under the License.                                             *
 * -------------------------------------------------------------------------- */

#ifndef rtosim_GeneralisedCoordinatesQueue_h
#define rtosim_GeneralisedCoordinatesQueue_h

#include "rtb/concurrency/Queue.h"
#include "rtosim/QueueData.h"
#include "rtosim/GeneralisedCoordinatesData.h"

namespace rtosim {

    using GeneralisedCoordinatesFrame = QueueData < GeneralisedCoordinatesData > ;
    using GeneralisedCoordinatesQueue = rtb::Concurrency::Queue < GeneralisedCoordinatesFrame > ;
}

#endif