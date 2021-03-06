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

#ifndef rtosim_GeneralisedCoordinatesFromStorageFile_h
#define rtosim_GeneralisedCoordinatesFromStorageFile_h

#include "rtosim/GeneralisedCoordinatesFromX.h"
#include "rtosim/Mapper.h"
#include <OpenSim/OpenSim.h>

namespace rtosim {
    class GeneralisedCoordinatesFromStorageFile : public GeneralisedCoordinatesFromX {
    public:
        GeneralisedCoordinatesFromStorageFile(
            GeneralisedCoordinatesQueue& outputGeneralisedCoordinatesQueue,
            rtb::Concurrency::Latch& doneWithSubscriptions,
            rtb::Concurrency::Latch& doneWithExecution,
            const std::string& osimModelFilename,
            const std::string& kinematicsStorageFilename,
            double fc = -1);
        GeneralisedCoordinatesFromStorageFile(
            GeneralisedCoordinatesQueue& outputGeneralisedCoordinatesQueue,
            rtb::Concurrency::Latch& doneWithSubscriptions,
            rtb::Concurrency::Latch& doneWithExecution,
            const std::string& osimModelFilename,
            const std::string& kinematicsStorageFilename,
            const std::vector<std::string>& coordinatesToLog,
            double fc = -1);
        virtual ~GeneralisedCoordinatesFromStorageFile() override {}
        virtual void operator()() override;
    private:
        void updateKinematicsSplines(double fc);
        OpenSim::GCVSplineSet splines_;
        OpenSim::Model model_;
        std::string kinematicsStorageFilename_;
        std::vector<double> timeColumn_;
        std::vector<std::string> coordinateNamesFromOsimModel_;
        Mapper mapper_;
    };
}

#endif
