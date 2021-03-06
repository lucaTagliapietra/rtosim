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

#ifndef rtosim_ArrayConverter_h
#define rtosim_ArrayConverter_h

#include <vector>

namespace rtosim {
    namespace ArrayConverter{

        template<typename T, typename U>
        void toStdVector(const T& srcArray, U& dstVector) {
            dstVector.clear();
            int size = srcArray.getSize();
            dstVector.resize(size);
            for (int i = 0; i < size; ++i)
                dstVector.at(i) = srcArray.get(i);
        }

        template<typename T, typename U>
        void fromStdVector(T& dstArray, const U& srcVector) {
            for (typename U::const_iterator it(srcVector.begin()); it != srcVector.end(); ++it)
                dstArray.append(*it);
        }
    }
}

#endif
