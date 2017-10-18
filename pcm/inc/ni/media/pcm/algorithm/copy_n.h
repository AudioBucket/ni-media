//
// Copyright (c) 2017 Native Instruments GmbH, Berlin
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#pragma once
#include <ni/media/pcm/detail/dispatch.h>

#include <algorithm>

namespace pcm
{
namespace detail
{

struct copy_n_impl
{
    template <class InputIt, class Size, class OutputIt>
    OutputIt operator()( InputIt first, Size count, OutputIt result ) const
    {
        return std::copy_n( first, count, result );
    }
};

} // namespace detail

template <class InputIt, class Size, class OutputIt>
OutputIt copy_n( InputIt first, Size count, OutputIt result )
{
    using namespace detail;
    return dispatch( copy_n_impl{}, first, count, result );
}

} // namespace pcm